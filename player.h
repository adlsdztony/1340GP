#pragma once

#include "object.h"
#include "map.h"
#include <iostream>


class Player: public Object
{
public:
    int width;
    int height;

public:
    Player(){}; // default constructor
    Player(int x, int y, vector<string> s);
    int move(int dx, int dy, Map &map);
    void jump(int x, int y, Map &map);
};
