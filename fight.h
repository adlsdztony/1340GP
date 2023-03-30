#pragma once

#include "pokemon.h"
#include "screen.h"
#include "keyboard.h"


class Fight
{
public:
    Pokemon *p1;
    Pokemon *p2;
    Screen screen;
    int turn = 0;
    Keyboard kb;
    vector<string> fight_map ={
"*------------------------------Round    --------------------------*",
"*                                                                 *",
"* HP [            ]                              [            ]HP *",                
"* MP [           ]                                [           ]MP *",
"*                                                                 *",
"*                                                                 *",
"*                                                                 *", 
"*                                                                 *",
"*                                                                 *", 
"*                                                                 *",
"*                                                                 *",
"*                                                                 *",
"*                                                                 *",
"*                                                                 *",
"* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *", 
"*            *            *            *            * Catch(C)    *", 
"* Damage:    * Damage:    * Damage:    * Damage:    * Withdraw(W) *",
"* MPcost:    * MPcost:    * MPcost:    * MPcost:    * Bag(B)      *", 
"*******************************************************************"
};

public:
    Fight(Pokemon *p1, Pokemon *p2);
    void start();
    void main_loop();
    void draw();
    void update();
    void input();
    void notice_select();
};

