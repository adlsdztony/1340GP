#pragma once

#include <string>
#include <vector>
using namespace std;

#include "format.h"

class Object
{
public:
    int x;
    int y;
    vector<string> s;
    int priority;
    vector<Format> formats;

public:
    Object(int x, int y, vector<string> s);
    Object(int x, int y, vector<string> s, Format format);
    void script2format();
}; 


class Player: public Object
{
public:
    Player(int x, int y, vector<string> s);
    Player(int x, int y, vector<string> s, Format format);
};
