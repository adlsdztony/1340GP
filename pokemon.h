#pragma once

#include "object.h"




class Skill{
    public:
        string name;
        
        double mp_cost, damage, healing, inattack, indefence, deattack, dedefense, self_damage;

    public:
        Skill(){}; // default constructor
        Skill(string name, double mp_cost,double damage,double healing,double inattack,double indefence,double deattack,double dedefense,double self_damage);
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
    Pokemon(string name, int HP, int MP, map<string, Pokemon> &pokemon_element);
};
