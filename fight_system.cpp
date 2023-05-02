#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include "fight_system.h"

#include <random>

using namespace std;

//damage calculation function
int damage_calculation(int pokemon_attack,char pokemon_type,double skill_damage,int enemy_defense,char enemy_type){
    int damage;
    double damage_index;
    double defense_index;
    double x = enemy_defense;
    //fire type
    if (pokemon_type == 'F'){
        if (enemy_type == 'F'){
            damage_index = 1;
        }
        else if (enemy_type == 'W'){
            damage_index = 0.7;
        }
        else if (enemy_type == 'G'){
            damage_index = 1.3;
        }
        else{
            damage_index = 0.8;
        }
            
    }
    //water type
    else if (pokemon_type == 'W'){
        if (enemy_type == 'F'){
            damage_index = 1.3;
        }
        else if (enemy_type == 'W'){
            damage_index = 1;
        }
        else if (enemy_type == 'G'){
            damage_index = 0.7;
        }
        else{
            damage_index = 0.8;
        }
    }
    //grass type
    else if (pokemon_type == 'G'){
        if (enemy_type == 'F'){
            damage_index = 0.7;
        }
        else if (enemy_type == 'W'){
            damage_index = 1.3;
        }
        else if (enemy_type == 'G'){
            damage_index = 1;
        }
        else{
            damage_index = 0.8;
        }
    }
    //normal type
    else{
        if (enemy_type == 'F'){
            damage_index = 1.2;
        }
        else if (enemy_type == 'W'){
            damage_index = 1.2;
        }
        else if (enemy_type == 'G'){
            damage_index = 1.2;
        }
        else{
            damage_index = 0.7;
        } 
}
    //defense index
    defense_index = 0.9 - 0.01*x +0.000058*(pow(x,2));
    damage = pokemon_attack*skill_damage*damage_index*defense_index;
    return damage;
}

// name mp_cost Damage Healing Inattack Indefence Deattack Dedefense self_damage
// inattack before damage calculation
// player skill calculation
int player_skill_calculation(Pokemon &pokemon, Pokemon &enemy, string skill_name){
    int damage;
    
    int pokemon_attack;
    int enemy_defense;
    string pokemon_type;
    string enemy_type;
    // find skill
    
    for (int i = 0; i < pokemon.skills.size(); i++){
        if (pokemon.skills[i].name == skill_name){
            pokemon.MP  =  pokemon.MP -pokemon.skills[i].mp_cost;
            pokemon.attack = pokemon.attack - pokemon.attack * pokemon.skills[i].inattack;
            pokemon.defense = pokemon.defense - pokemon.defense * pokemon.skills[i].indefence;
            enemy.attack = enemy.attack - enemy.attack * pokemon.skills[i].deattack;
            enemy.defense = enemy.defense - enemy.defense * pokemon.skills[i].dedefense;

            // damage calculation
            damage = damage_calculation(pokemon.attack ,pokemon.type ,pokemon.skills[i].damage ,enemy.defense ,enemy.type);
            enemy.HP = enemy.HP - damage;
            pokemon.HP = pokemon.HP + pokemon.max_HP * pokemon.skills[i].healing;
            pokemon.HP = pokemon.HP - pokemon.attack * pokemon.skills[i].self_damage;
            // check if HP is over max_HP
            if (pokemon.HP > pokemon.max_HP){
                pokemon.HP = pokemon.max_HP;

            }
            return 0;
       
        }
    
    
    }

    return 0;
}


// enemy skill calculation
int enemy_skill_calculation(Pokemon &enemy, Pokemon &pokemon, string skill_name){
    int damage;
    
    int enemy_attack;
    int pokemon_defense;
    string enemy_type;
    string pokemon_type;
    // find skill
    for (int i = 0; i < enemy.skills.size(); i++){
        if (enemy.skills[i].name == skill_name){
            enemy.MP  =  enemy.MP -enemy.skills[i].mp_cost;
            enemy.attack = enemy.attack - enemy.attack * enemy.skills[i].inattack;
            enemy.defense = enemy.defense - enemy.defense * enemy.skills[i].indefence;
            pokemon.attack = pokemon.attack - pokemon.attack * enemy.skills[i].deattack;
            pokemon.defense = pokemon.defense - pokemon.defense * enemy.skills[i].dedefense;
            enemy.HP = enemy.HP - enemy.HP * enemy.skills[i].self_damage;
            // damage calculation
            damage = damage_calculation(enemy.attack ,enemy.type ,enemy.skills[i].damage ,pokemon.defense ,pokemon.type);
            pokemon.HP = pokemon.HP - damage;
            enemy.HP = enemy.HP + enemy.HP * enemy.skills[i].healing;
            enemy.HP = enemy.HP - enemy.attack * enemy.skills[i].self_damage;
            // check if HP is over max_HP
            if (enemy.HP > enemy.max_HP){
                enemy.HP = enemy.max_HP;
            }
            return 0;    
        }       
    }
    
    return 0;
}


void player_calculation(int choice, Pokemon &pokemon, Pokemon &enemy){
    
    if (choice == 0){ 
        
        player_skill_calculation(pokemon,enemy,pokemon.skills[choice].name);
        //print all info
       
    }
    else if (choice == 1){
        
    
        player_skill_calculation(pokemon,enemy,pokemon.skills[choice].name);    
        //print all info
        
        


    }
    else if (choice == 2){
        
        
        player_skill_calculation(pokemon,enemy,pokemon.skills[choice].name);
        //print all info
        
        
    }
    else if (choice == 3){
        
        
        
        player_skill_calculation(pokemon,enemy,pokemon.skills[choice].name);
        //print all info
        
    }
}


int enemy_choose_skill(int test_choice[4]){
    random_device rd;
    uniform_int_distribution<int> dist(0, 3);
    //do not use test_choice 
    int choice;
    choice = dist(rd);
    while (test_choice[choice] == -1){
        choice = dist(rd);
    }
    return choice;
}

int enemy_fight_system(Pokemon &pokemon, Pokemon &enemy){
    
    int choice;

    int test_choice[4] = {0, 1, 2, 3};
    choice = enemy_choose_skill(test_choice);

    //if HP higher than 90%, do not use healing skill
    if (enemy.HP > enemy.max_HP * 0.9){   
        if (enemy.skills[choice].healing > 0){
            //delete the skill from test_choice
            test_choice[choice] = -1;
            choice = enemy_choose_skill(test_choice);
        }
    } 
    //if attack higher than pokemon attack, do not use inattack skill or if HP lower than 50%, do not use inattack skill
    if (enemy.attack > pokemon.attack || enemy.HP < enemy.max_HP * 0.5){
        if (enemy.skills[choice].inattack > 0){
            //delete the skill from test_choice
            test_choice[choice] = -1;
            choice = enemy_choose_skill(test_choice);
        }
    }
    
    //if HP lower than 30%, do not use indefense skill or if defense higher than attack do not use indefense skill or if defense higher than HP*0.5, do not use indefense skill
    if (enemy.HP < enemy.max_HP * 0.3 || enemy.defense > enemy.attack || enemy.defense > enemy.max_HP * 0.5){
        if (enemy.skills[choice].indefence > 0){
            //delete the skill from test_choice
            test_choice[choice] = -1;
            choice = enemy_choose_skill(test_choice);
        }
    }
    
    return choice;

}

void enemy_calculation(Pokemon &pokemon, Pokemon &enemy){

    int choice = enemy_fight_system(pokemon, enemy);
    // check if MP is enough
    while (enemy.MP < enemy.skills[choice].mp_cost){
        choice = 2;
    }
    
    if (choice == 0){ 
    
        enemy_skill_calculation(enemy,pokemon,enemy.skills[choice].name);
        //print all info
    
        
    }
    else if (choice == 1){
        cout << "enemy choose skill "<< choice +1 << endl;
        enemy_skill_calculation(enemy,pokemon,enemy.skills[choice].name);
        //print all info
    
        
}
    else if (choice == 2){
    
        
        enemy_skill_calculation(enemy,pokemon,enemy.skills[choice].name);
        //print all info

            
        
    }
    else if (choice == 3){
        
        
        enemy_skill_calculation(enemy,pokemon,enemy.skills[choice].name);

        //print all info
         
        }
    
    else{
        

    }
}
