#pragma once

#include "pokemon.h"
#include "screen.h"
#include "keyboard.h"
#include "format.h"
#include "fight_system.h"
#include "notice.h"

const vector<string> fight_map = {
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
"* MPcost:    * MPcost:    * MPcost:    * MPcost:    *             *", 
"*******************************************************************"
};



class Fight
{
public:
    Pokemon* p1;
    Pokemon* p2;
    Screen* screen;
    int turn = 0;
    Keyboard* kb;
    int selected = 0;
;

public:
    Fight(Pokemon* p1, Pokemon* p2, Keyboard* kb, Screen* screen);
    char start();
    char main_loop();
    void draw();
    int update(int choice);
    int input();
    void notice_select();
    bool withdraw();
    void catch_pokemon();
    void bag();
};

