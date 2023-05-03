#pragma once

#include "screen.h"
#include "keyboard.h"
#include "map.h"
#include "maps.h"
#include "notice.h"
#include "player.h"
#include "chats.h"
#include "pokemon.h"
#include "pokemon_info.h"
#include "fight.h"
#include <fstream>
#include "startup_map.h"

// a class to store the state of the game
// also provide functions to store and load the state
class State
{
public:
    int x;
    int y;
    string map_name;
    vector<Pokemon> pokemons;
    map<string, Pokemon> pokemon_element;

public:
    State(){
        this->x = 0;
        this->y = 0;
        this->map_name = "";
        this->pokemons = vector<Pokemon>();
        get_pokemon_element(this->pokemon_element);
    }; // default constructor
    void store(string file_name);
    void load(string file_name);
};


// main process of the game
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
    State state;

public:
    Game();
    void main_loop();
    void draw();
    void update(int e);
    void add_notice_E();
    void save_and_exit();
    void fight(string enemy_name);
    int chat(string title, vector<string> content);
};