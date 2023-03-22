#pragma once

#include "window.h"
#include "display.h"
#include "keyboard.h"
#include <assert.h>


class Notice : public Window
{
public:
    vector<string> selections;
    int space = 1;

public:
    Notice(int x, int y, int w, int h, string title, vector<string> selections, int space = 1);

    int select(Keyboard *kb, Screen *screen);

};