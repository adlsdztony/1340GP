#include "keyboard.h"


Keyboard::Keyboard()
{
	in = 0;
}

void Keyboard::scanKeyboard()
{
    tcgetattr(0,&stored_settings);
    new_settings = stored_settings;
    new_settings.c_lflag &= (~ICANON);
    new_settings.c_cc[VTIME] = 0;
    tcgetattr(0,&stored_settings);
    new_settings.c_cc[VMIN] = 1;
	new_settings.c_lflag &= ~ECHO;
    tcsetattr(0,TCSANOW,&new_settings);
    in = getchar();
	if (in == 27)
    {
        // Read the next two characters
        new_settings.c_cc[VMIN] = 0;
        tcsetattr(0,TCSANOW,&new_settings);
        char second_char = getchar();
        tcsetattr(0,TCSANOW,&stored_settings);

        // Check for '[' (ASCII 91) and 'A' (ASCII 65) for UP arrow key
        if (second_char == 91)
        {
			new_settings.c_cc[VMIN] = 0;
            tcsetattr(0,TCSANOW,&new_settings);
            char third_char = getchar();
            tcsetattr(0,TCSANOW,&stored_settings);
			if (third_char == 65)
			{
            	in = KEY_UP;
			}
			if (third_char == 66)
			{
				in = KEY_DOWN;
			}
			if (third_char == 67)
			{
				in = KEY_RIGHT;
			}
			if (third_char == 68)
			{
				in = KEY_LEFT;
			}
        }
    }
    tcsetattr(0,TCSANOW,&stored_settings);
    this->in = in;

}

void Keyboard::loop()
{
	while (true)
	{
		scanKeyboard();
	}
}

void Keyboard::listen()
{
	// start thread
	t = std::thread(&Keyboard::loop, this);
	// detach thread
	t.detach();
}

int Keyboard::read()
{
	if (in != 0)
	{
		int return_in = in;
		in = 0;
		return return_in;
	}
	else
	{
		return 0;
	}
}

int Keyboard::wait_for(vector<int> key)
{
	while (true)
	{
		scanKeyboard();
		int k = read();
		if (k != 0)
		{
			for (int i = 0; i < key.size(); i++)
			{
				if (k == key[i])
				{
					return k;
				}
			}
		}
	}
}

void Keyboard::stop()
{
	t.~thread();
	// enable echo
	stored_settings.c_lflag |= ECHO;
	tcsetattr(0,TCSANOW,&stored_settings);
}