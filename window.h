#pragma once

#include "object.h"


class Window: public Object
{
public:
    int width;
    int height;
    string title;
    vector<string> content;
    
public:
    Window(int x, int y, int width, int length, string title, vector<string> content);
};