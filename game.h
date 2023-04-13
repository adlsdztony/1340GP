#pragma once

#include "screen.h"
#include "keyboard.h"
#include "map.h"
#include "maps.h"
#include "notice.h"
#include "player.h"


class Game
{
public:
    Screen screen;
    Keyboard kb;
    Map game_map;
    Player player;
    Notice notice;
    vector<Object*> objects;
    int E = 0;
    map<string, Map> maps_map;

public:
    Game(vector<string> game_map);
    Game(const Map &game_map);
    void start();
    void end();
    void main_loop();
    void draw();
    void update(int e);
    void input();
    void notice_select();
    void add_notice_E();
};