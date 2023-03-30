#include "pokemon.h"

Skill::Skill(string name, int damage, int mp_cost, char type){
    this->name = name;
    this->damage = damage;
    this->mp_cost = mp_cost;
    this->type = type;
}

Pokemon::Pokemon(vector<string> &s, string name, char type, int HP, int MP, int attack, int defense, vector<Skill> skills){
    this->name = name;
    this->type = type;
    this->HP = HP;
    this->MP = MP;
    this->attack = attack;
    this->defense = defense;
    this->skills = skills;
    this->s = s;
    this->x = 0;
    this->y = 0;
}

Skill s1("Tackle", 40, 0, 'N');
Skill s2("Growl", 0, 0, 'N');
Skill s3("Tail Whip", 0, 0, 'N');
Skill s4("Quick Attack", 40, 0, 'N');

Pokemon p1(pikachu, "Pikachu", 'E', 100, 80, 55, 40, {s1, s2, s3, s4});