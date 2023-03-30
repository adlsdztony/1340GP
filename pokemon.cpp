#include "pokemon.h"

Skill::Skill(string name, int damage, int mp_cost){
    this->name = name;
    this->damage = damage;
    this->mp_cost = mp_cost;
}

Pokemon::Pokemon(vector<string> &s, string name, char type, int HP, int MP, int attack, int defense, vector<Skill> skills){
    this->name = name;
    this->type = type;
    this->HP = HP;
    this->MP = MP;
    this->max_HP = HP;
    this->max_MP = MP;
    this->attack = attack;
    this->defense = defense;
    this->skills = skills;
    this->s = s;
    script2format();
    this->x = 0;
    this->y = 0;
}

