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
    int priority = 0;
    vector<Format> formats;

public:
    Object(){}; // default constructor
    Object(int x, int y, vector<string> s);
    Object(int x, int y, vector<string> s, Format format);
    void script2format();
}; 

vector<Format> check_format(string &s, int i, int j = 0);

class Player: public Object
{
public:
    Player(int x, int y, vector<string> s);
    Player(int x, int y, vector<string> s, Format format);
};
