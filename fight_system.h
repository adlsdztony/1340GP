
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

// info

class Skills{
    public:
        string name;
        double mp_cost;
        double damage;
        double healing;
        double inattack;
        double indefense;
        double deattack;
        double dedefense;
        double self_damage;
    
    
    
    public:    
    Skills(string name, double mp_cost,double Damage,double Healing,double Inattack,double Indefense,double Deattack,double Dedefense,double self_damage);


};

class Pokemon{
    public:
        string name;
        string type;
        int HP;
        int MP;
        int max_HP;
        int max_MP;
        int attack;
        int defense;
        vector<Skills> skills;
        Pokemon(string name,string type,int HP,int MP,int attack,int defense,vector<Skills> skills);
        
    
        
};


Skills :: Skills(string name, double mp_cost,double Damage,double Healing,double Inattack,double Indefense,double Deattack,double Dedefense,double self_damage){
    this->name = name;
    this->mp_cost = mp_cost;
    this->damage = Damage;
    this->healing = Healing;
    this->inattack = Inattack;
    this->indefense = Indefense;
    this->deattack = Deattack;
    this->dedefense = Dedefense;
    this->self_damage = self_damage;
}

Pokemon :: Pokemon(string name,string type,int HP,int MP,int attack,int defense,vector<Skills> skills){
    this->name = name;
    this->type = type;
    this->HP = HP;
    this->MP = MP;
    this->max_HP = HP;
    this->max_MP = MP;
    this->attack = attack;
    this->defense = defense;
    this->skills = skills;
    
}
        
    
int player_skill_calculation(Pokemon &pokemon, Pokemon &enemy, string skill_name);
void enemy_calculation(int choice, Pokemon &pokemon, Pokemon &enemy);
int damage_calculation(int pokemon_attack,string pokemon_type,double skill_damage,int enemy_defense,string enemy_type);
int enemy_skill_calculation(Pokemon &pokemon, Pokemon &enemy, string skill_name);
void player_calculation(int choice, Pokemon &pokemon, Pokemon &enemy);
int enemy_choose_skill();
void enemy_calculation(int choice, Pokemon &pokemon, Pokemon &enemy);
