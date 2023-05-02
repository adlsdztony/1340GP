
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include "pokemon.h"
using namespace std;

// info

int damage_calculation(int pokemon_attack,string pokemon_type,double skill_damage,int enemy_defense,string enemy_type);

int player_skill_calculation(Pokemon &pokemon, Pokemon &enemy, string skill_name);

int enemy_skill_calculation(Pokemon &pokemon, Pokemon &enemy, string skill_name);

void player_calculation(int choice, Pokemon &pokemon, Pokemon &enemy);

void enemy_calculation(int choice, Pokemon &pokemon, Pokemon &enemy);

int enemy_fight_system(Pokemon &pokemon, Pokemon &enemy);

int enemy_choose_skill(int test_choice[4]);

// use player_skill_calculation and enemy_skill_calculation for fight
