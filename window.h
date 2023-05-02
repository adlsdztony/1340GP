#pragma once

#include "object.h"


class Window: public Object
{
public:
    int width;
    int height;
    string title;
    vector<string> content;
    int space = 1;
    
public:
    Window(){}; // default constructor
    Window(int x, int y, int width, int length, string title, string content, int space=1);
    Window(int x, int y, int width, int height, string title, vector<string> content, int space=1);
};