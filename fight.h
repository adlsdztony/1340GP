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

public:
    Fight(Pokemon *p1, Pokemon *p2);
    void start();
    void main_loop();
    void draw();
    void update();
    void input();
    void notice_select();
};

vector<string> fight_map ={
"*------------------------------Round    ---------------------------",
"*                                                                  ",
"* HP [            ]100/100                100/100[            ]HP *",                
"* MP [           ]80/80                      80/80[           ]MP *",
"* Pokenmon Name  Type                        Type   Pokenmon Name *",
"*                                                                  ",
"*                                                                  ",
"*                                                                  ", 
"*                                                                  ", 
"*                                                                  ",
"*                                                                  ",
"*                                                                  ",
"*                                                                  ",
"*                                                                  ",
"* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *", 
"*            *            *            *            * Catch(C)    *", 
"* Damage:    * Damage:    * Damage:    * Damage:    * Withdraw(W) *",
"* MPcost:    * MPcost:    * MPcost:    * MPcost:    * Bag(B)      *", 
"*******************************************************************"
};