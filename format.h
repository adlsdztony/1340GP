#pragma once

#include <string>
#include <map>
using namespace std;

// define color and format
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

const map<string, string> mod_map = {{"bold", BOLD}, {"underline", UNDERLINE}, {"blink", BLINK}, {"reverse", REVERSE}, {"concealed", CONCEALED}};
const map<string, string> front_map = {{"black", FRONT_BLACK}, {"red", FRONT_RED}, {"green", FRONT_GREEN}, {"yellow", FRONT_YELLOW}, {"blue", FRONT_BLUE}, {"purple", FRONT_PURPLE}, {"cyan", FRONT_CYAN}, {"white", FRONT_WHITE}};
const map<string, string> back_map = {{"black", BACK_BLACK}, {"red", BACK_RED}, {"green", BACK_GREEN}, {"yellow", BACK_YELLOW}, {"blue", BACK_BLUE}, {"purple", BACK_PURPLE}, {"cyan", BACK_CYAN}, {"white", BACK_WHITE}};


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
