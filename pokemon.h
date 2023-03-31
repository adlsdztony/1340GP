#pragma once

#include "object.h"https://github.com/adlsdztony/1340GP/blob/main/pokemon.h


class Skill
{
public:
    string name;
    double damage;
    int mp_cost;

public:
    Skill(string name, int damage, int mp_cost);
};

class Pokemon: public Object
{
public:
    string name;
    char type;
    int HP;
    int MP;
    int max_HP;
    int max_MP;
    int attack;
    int defense;
    vector<Skill> skills;
public:
    Pokemon(){}; // default constructor
    Pokemon(vector<string> &s, string name, char type, int HP, int MP, int attack, int defense, vector<Skill> skills);
};
