#pragma once

#include "object.h"


class Skill
{
public:
    string name;
    int damage;
    int mp_cost;
    char type;

public:
    Skill(string name, int damage, int mp_cost, char type);
};

class Pokemon: public Object
{
public:
    string name;
    char type;
    int HP;
    int MP;
    int attack;
    int defense;
    vector<Skill> skills;
public:
    Pokemon(){}; // default constructor
    Pokemon(vector<string> &s, string name, char type, int HP, int MP, int attack, int defense, vector<Skill> skills);
};
