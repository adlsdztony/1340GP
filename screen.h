#pragma once

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
#include <sys/types.h>

// #include <map>
using namespace std;

#include "map.h"
#include "object.h"

class Screen
{
public:
    int width;
    int height;
    vector<string> buffer;
    vector<Format> formats;
    vector<vector<int>> format_map;
    vector<string> current;
    int x_posi;
    int y_posi;

public:
    Screen(){}; // default constructor
    Screen(int width, int height);
    void set_pos();
    void clear();
    void refresh();
    void draw(int x, int y, char c);
    void draw(int x, int y, const string &s);
    void draw(int x, int y, const vector<string> &s);
    void draw(Object* obj);
    void draw(vector<Object*> objs);
    void draw_map(Map* map);
    void draw_letter(int x, int y, char c);
    void draw_letters(int x, int y, string &lts);
    void update();
    void insert_format(vector<string> &temp);
    void clean();
    void rearrange(); 
};
