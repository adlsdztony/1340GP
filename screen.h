#pragma once

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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

public:
    Screen(){}; // default constructor
    Screen(int width, int height);
    void clear();
    void refresh();
    void draw(int x, int y, char c);
    void draw(int x, int y, const string &s);
    void draw(int x, int y, const vector<string> &s);
    void draw(Object* obj);
    void draw(vector<Object*> objs);
    void draw_map(Map* map);
    void update();
    void insert_format(vector<string> &temp);
    void clean();
};
