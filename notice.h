#pragma once

#include "window.h"
#include "screen.h"
#include "keyboard.h"
#include <assert.h>


class Notice : public Window
{
public:
    vector<string> selections;
    int space = 1;

public:
    Notice(){}; // default constructor
    Notice(int x, int y, int w, int h, string title, vector<string> selections, int space = 1);

    int select(Keyboard *kb, Screen *screen);

};

int show_notice(string &title, vector<string> &selections, Keyboard *kb, Screen *screen);