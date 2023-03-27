#pragma once

#include <termio.h>
#include <stdio.h>
#include <thread>
#include <vector>
#include <iostream>

using namespace std;

#define KEY_UP 650
#define KEY_DOWN 660
#define KEY_LEFT 680
#define KEY_RIGHT 670
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
    bool is_listening = false;
public:
    Keyboard();
    void scanKeyboard();
    void loop();
    void listen();
    int read();
    int wait_for(vector<int> key);
    void stop();
};

