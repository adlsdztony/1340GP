#pragma once

#include "object.h"




class Skills{
    public:
        string name;
        
        double mp_cost,Damage,Healing,Inattack,Indefence,Deattack,Dedefense,self_damage;

    public:
        Skills(){}; // default constructor
        Skills(string name, double mp_cost,double Damage,double Healing,double Inattack,double Indefence,double Deattack,double Dedefense,double self_damage);
    
    

};

class Pokemon: public Object
{
public:
    string name;
    string type;
    int HP;
    int MP;
    int attack;
    int defense;
    vector<Skills> skill;
public:
    Pokemon(){}; // default constructor
    Pokemon(vector<string> &s, string name, char type, int HP, int MP, int attack, int defense, vector<Skills> skills);
};
