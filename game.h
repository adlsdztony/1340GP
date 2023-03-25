#pragma once

#include "screen.h"
#include "keyboard.h"
#include "map.h"
#include "notice.h"
#include "player.h"


class Game
{
public:
    Screen screen;
    Keyboard kb;
    Map map;
    Player player;
    Notice notice;
    vector<Object*> objects;
    int E = 0;

public:
    Game(vector<string> map);
    Game(Map map);
    void start();
    void end();
    void main_loop();
    void draw();
    void update();
    void input();
    void notice_select();
    void add_notice_E();
};