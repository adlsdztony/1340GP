// #pragma once

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


#include "object.h"

class Screen
{
public:
    int width;
    int height;
    vector<string> buffer;
    vector<Format> formats;

public:
    Screen(int width, int height);
    void clear();
    void refresh();
    void draw(int x, int y, char c);
    void draw(int x, int y, string s);
    void draw(int x, int y, vector<string> s);
    void draw(Object obj);
};
