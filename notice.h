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
    Notice(int x, int y, int w, int h, string title, vector<string> selections) : Window(x, y, w, h, title, selections){
        this->content = selections;
        this->selections = selections;
        int title_start = (w - title.length()) / 2;
        this->formats.push_back(Format(title_start, 1, title.length(), BOLD));
    };

    Notice(int x, int y, int w, int h, string title, vector<string> selections, int space) : Window(x, y, w, h, title, selections){
        Window win(x, y, w, h, title, selections);
        this->content = selections;
        this->selections = selections;
        this->space = space;
    };

    int select(Keyboard *kb, Screen *screen);

};