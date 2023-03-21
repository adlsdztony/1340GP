#pragma once

#include <termio.h>
#include <stdio.h>
#include <thread>
#include <vector>

using namespace std;

#define KEY_UP 65
#define KEY_DOWN 66
#define KEY_LEFT 68
#define KEY_RIGHT 67
#define KEY_SPACE 32
#define KEY_ENTER 10
#define KEY_ESC 27
 

class Keyboard
{
public:
    int in;
    struct termios new_settings;
    struct termios stored_settings;
    std::thread t;
public:
    Keyboard();
    void scanKeyboard();
    void loop();
    void listen();
    int read();
    int wait_for(vector<int> key);
};

