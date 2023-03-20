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
    stored_settings.c_lflag |= ECHO;
    tcsetattr(0,TCSANOW,&new_settings);
    in = getchar();
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

