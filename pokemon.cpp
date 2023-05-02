#include "pokemon.h"

Skill::Skill(string name, double mp_cost,double damage,double healing,double inattack,double indefence,double deattack,double dedefense,double self_damage){
    this->name = name;
    this->damage = damage;
    this->mp_cost = mp_cost;
    this->healing = healing;
    this->inattack = inattack;
    this->indefence = indefence;
    this->deattack = deattack;
    this->dedefense = dedefense;
    this->self_damage = self_damage;
    
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

Pokemon::Pokemon(string name, int HP, int MP, map<string, Pokemon> &pokemon_element){
    this->name = name;
    this->HP = HP;
    this->MP = MP;
    this->max_HP = pokemon_element[name].max_HP;
    this->max_MP = pokemon_element[name].max_MP;
    this->attack = pokemon_element[name].attack;
    this->defense = pokemon_element[name].defense;
    this->skills = pokemon_element[name].skills;
    this->type = pokemon_element[name].type;
    this->s = pokemon_element[name].s;
    this->formats = pokemon_element[name].formats;
    this->x = 0;
    this->y = 0;
}