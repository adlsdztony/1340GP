#pragma once

#include <termio.h>
#include <stdio.h>
#include <thread>
 

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
};

