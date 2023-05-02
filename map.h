#pragma once

#include <vector>
#include <string>
#include "object.h"

using namespace std;


class Map: public Object {
public:
    vector<string> valid_map;
    int width;
    int height;
    int priority = 0;
    // vector<string> s;
    map<char, string> interact_map;


public:
    Map(){}; // default constructor
    Map(int width, int height);
    Map(const vector<string> &ma, const vector<string> &valid_map, const map<char, string> &interact_map);
    Map(vector<string> &map);
    void init(vector<string> &map, vector<string> &valid_map);
    void add_interact(int x, int y, char c);
    void add_interact_object(Object &object, char name);
};
