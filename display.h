#pragma once

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define DIM "\033[2m"
#define ITALIC "\033[3m"
#define UNDERLINE "\033[4m"
#define BLINK "\033[5m"
#define REVERSE "\033[7m"
#define CONCEALED "\033[8m"

#define FRONT_BLACK "\033[30m"
#define FRONT_RED "\033[31m"
#define FRONT_GREEN "\033[32m"
#define FRONT_YELLOW "\033[33m"
#define FRONT_BLUE "\033[34m"
#define FRONT_PURPLE "\033[35m"
#define FRONT_CYAN "\033[36m"
#define FRONT_WHITE "\033[37m"

#define BACK_BLACK "\033[40m"
#define BACK_RED "\033[41m"
#define BACK_GREEN "\033[42m"
#define BACK_YELLOW "\033[43m"
#define BACK_BLUE "\033[44m"
#define BACK_PURPLE "\033[45m"
#define BACK_CYAN "\033[46m"
#define BACK_WHITE "\033[47m"


class Format
{
public:
    int x;
    int y;
    int length;
    string format;

public:
    Format(int x, int y, int length, string format);
};



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
    void script2format();
}; 


class Player: public Object
{
public:
    Player(int x, int y, string s);
};


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
