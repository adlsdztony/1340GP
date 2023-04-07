#include "pokemon.h"

Skills::Skills(string name, double mp_cost,double Damage,double Healing,double Inattack,double Indefence,double Deattack,double Dedefense,double self_damage){
    this->name = name;
    this->Damage = Damage;
    this->mp_cost = mp_cost;
    this->Healing = Healing;
    this->Inattack = Inattack;
    this->Indefence = Indefence;
    this->Deattack = Deattack;
    this->Dedefense = Dedefense;
    this->self_damage = self_damage;
    
}

Pokemon::Pokemon(vector<string> &s, string name, char type, int HP, int MP, int attack, int defense, vector<Skills> skills){
    this->name = name;
    this->type = type;
    this->HP = HP;
    this->MP = MP;
    this->attack = attack;
    this->defense = defense;
    this->skill = skill;
    this->s = s;
    script2format();
    this->x = 0;
    this->y = 0;
}

