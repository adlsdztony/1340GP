#include "keyboard.h"
#include <iostream>

using namespace std;


Keyboard::Keyboard()
{
	in = 0;
	this->is_listening = false;
}

void Keyboard::scanKeyboard()
{
	int temp_in;
    tcgetattr(0,&stored_settings);
    new_settings = stored_settings;
    new_settings.c_lflag &= (~ICANON);
	// new_settings.c_lflag |= ISIG;
    new_settings.c_cc[VTIME] = 0;
    new_settings.c_cc[VMIN] = 1;
	new_settings.c_lflag &= ~ECHO;
    tcsetattr(0,TCSANOW,&new_settings);
    temp_in = getchar();
	
	if (temp_in == 27)
    {
        // Read the next two characters
        new_settings.c_cc[VMIN] = 1;
        tcsetattr(0,TCSANOW,&new_settings);
        char second_char = getchar();

        // Check for '[' (ASCII 91) and 'A' (ASCII 65) for UP arrow key
        if (second_char == 91)
        {
			new_settings.c_cc[VMIN] = 0;
        	tcsetattr(0,TCSANOW,&new_settings);
            char third_char = getchar();
			if (third_char == 65)
			{
            	temp_in = KEY_UP;
			}
			if (third_char == 66)
			{
				temp_in = KEY_DOWN;
			}
			if (third_char == 67)
			{
				temp_in = KEY_RIGHT;
			}
			if (third_char == 68)
			{
				temp_in = KEY_LEFT;
			}
        }
    }
    // tcsetattr(0,TCSANOW,&stored_settings);
    this->in = temp_in;

}

void Keyboard::loop()
{
	while (this->is_listening)
	{
		scanKeyboard();
	}
}

void Keyboard::listen()
{
	this->is_listening = true;
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
		// @todo make this more efficient
		// scanKeyboard();
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
	this->is_listening = false;
	// enable echo
	stored_settings.c_lflag |= ECHO;
	tcsetattr(0,TCSANOW,&stored_settings);
}

// int main(){
// 	Keyboard kb;
// 	kb.listen();
// 	while (true)
// 	{
// 		int i = kb.read();
// 		if (i != 0)
// 		{
// 			cout << i << endl;
// 		}
// 	}

// }
