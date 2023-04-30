#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include "fight_system.h"
#include <random>

using namespace std;
// info
// player_calculation(choice,pokemon,enemy);
// enemy_choice = enemy_choose_skill(); 
// enemy_calculation(enemy_choice,pokemon,enemy);

int damage_calculation(int pokemon_attack,string pokemon_type,double skill_damage,int enemy_defense,string enemy_type){
    int damage;
    double damage_index;
    double defense_index;
    double x = enemy_defense;
    //fire type
    if (pokemon_type == "fire"){
        if (enemy_type == "fire"){
            damage_index = 1;
        }
        else if (enemy_type == "water"){
            damage_index = 0.7;
        }
        else if (enemy_type == "grass"){
            damage_index = 1.3;
        }
        else{
            damage_index = 0.8;
        }
            
    }
    //water type
    else if (pokemon_type == "water"){
        if (enemy_type == "fire"){
            damage_index = 1.3;
        }
        else if (enemy_type == "water"){
            damage_index = 1;
        }
        else if (enemy_type == "grass"){
            damage_index = 0.7;
        }
        else{
            damage_index = 0.8;
        }
    }
    //grass type
    else if (pokemon_type == "grass"){
        if (enemy_type == "fire"){
            damage_index = 0.7;
        }
        else if (enemy_type == "water"){
            damage_index = 1.3;
        }
        else if (enemy_type == "grass"){
            damage_index = 1;
        }
        else{
            damage_index = 0.8;
        }
    }
    //normal type
    else{
        if (enemy_type == "fire"){
            damage_index = 1.2;
        }
        else if (enemy_type == "water"){
            damage_index = 1.2;
        }
        else if (enemy_type == "grass"){
            damage_index = 1.2;
        }
        else{
            damage_index = 0.7;
        }
        
    
}
    defense_index = 0.9 - 0.01*x +0.000058*(pow(x,2));
    
    damage = pokemon_attack*skill_damage*damage_index*defense_index;
    cout << "damage is " << damage << endl;
    cout << "damage index is " << damage_index << endl;
    cout << "defense index is " << defense_index << endl;

    

    return damage;
}
// name mp_cost Damage Healing Inattack Indefence Deattack Dedefense self_damage
// inattack before damage calculation
// player skill calculation
int player_skill_calculation(Pokemon &pokemon, Pokemon &enemy, string skill_name){
    int damage;
    int MP_cost;
    double skill_damage;
    double skill_healing;
    double skill_inattack;
    double skill_indefense;
    double skill_deattack;
    double skill_dedefense;
    double skill_self_damage;
    int pokemon_attack;
    int enemy_defense;
    string pokemon_type;
    string enemy_type;
    // find skill
    for (int i = 0; i < pokemon.skills.size(); i++){
        if (pokemon.skills[i].name == skill_name){
            MP_cost = pokemon.skills[i].mp_cost;
            skill_damage = pokemon.skills[i].damage;
            skill_healing = pokemon.skills[i].healing;
            skill_inattack = pokemon.skills[i].inattack;
            skill_indefense = pokemon.skills[i].indefense;
            skill_deattack = pokemon.skills[i].deattack;
            skill_dedefense = pokemon.skills[i].dedefense;
            skill_self_damage = pokemon.skills[i].self_damage;
        }
        
    }
    // find pokemon info
    pokemon_type = pokemon.type;
    pokemon_attack = pokemon.attack;
    // find enemy info
    enemy_type = enemy.type;
    enemy_defense = enemy.defense;

    pokemon.MP = pokemon.MP - MP_cost;
    
    // inattack
    pokemon.attack = pokemon.attack + pokemon_attack * skill_inattack;
    // indefense
    pokemon.defense = pokemon.defense + pokemon.defense * skill_indefense;
    // deattack
    enemy.attack = enemy.attack +enemy.attack * skill_deattack;
    // dedefense
    enemy.defense =  enemy.defense + enemy_defense * skill_dedefense;
    // damage calculation
    

    damage = damage_calculation(pokemon_attack,pokemon_type,skill_damage,enemy_defense,enemy_type);
    
    enemy.HP = enemy.HP - damage;
    
    // healing
    pokemon.HP = pokemon.HP + skill_healing*pokemon.HP;
    // self damage
    pokemon.HP = pokemon.HP - skill_self_damage*pokemon.HP;
    if (pokemon.HP > pokemon.max_HP){
        pokemon.HP = pokemon.max_HP;
    }
    return 0;
}



// enemy skill calculation

int enemy_skill_calculation(Pokemon &enemy, Pokemon &pokemon, string skill_name){


    int damage;
    int MP_cost;
    double skill_damage;
    double skill_healing;
    double skill_inattack;
    double skill_indefense;
    double skill_deattack;
    double skill_dedefense;
    double skill_self_damage;
    int enemy_attack;
    int pokemon_defense;
    string enemy_type;
    string pokemon_type;
    // find skill
    for (int i = 0; i < enemy.skills.size(); i++){
        if (enemy.skills[i].name == skill_name){
            MP_cost = enemy.skills[i].mp_cost;
            skill_damage = enemy.skills[i].damage;
            skill_healing = enemy.skills[i].healing;
            skill_inattack = enemy.skills[i].inattack;
            skill_indefense = enemy.skills[i].indefense;
            skill_deattack = enemy.skills[i].deattack;
            skill_dedefense = enemy.skills[i].dedefense;
            skill_self_damage = enemy.skills[i].self_damage;
        }
        
    }
    

    
    // find enemy info
    enemy_type = enemy.type;
    enemy_attack = enemy.attack;
    // find pokemon info
    pokemon_type = pokemon.type;
    pokemon_defense = pokemon.defense;

    enemy.MP = enemy.MP - MP_cost;
    
    // inattack
    enemy.attack = enemy.attack + enemy_attack * skill_inattack;
    // indefense
    enemy.defense = enemy.defense + enemy.defense * skill_indefense;
    // deattack
    pokemon.attack = pokemon.attack +pokemon.attack * skill_deattack;
    // dedefense
    pokemon.defense =  pokemon.defense + pokemon_defense * skill_dedefense;
    // damage calculation
    

    damage = damage_calculation(enemy_attack,enemy_type,skill_damage,pokemon_defense,pokemon_type);
    
    pokemon.HP = pokemon.HP - damage;
    
    // healing
    enemy.HP = enemy.HP + skill_healing*enemy.HP;
    // self damage
    enemy.HP = enemy.HP - skill_self_damage*enemy.HP;
    if (enemy.HP > enemy.max_HP){
        enemy.HP = enemy.max_HP;
    }
    return 0;
}


void player_calculation(int choice, Pokemon &pokemon, Pokemon &enemy){
    
    if (choice == 0){ 
        cout << "choose skill "<< choice +1 << endl; 
        if (pokemon.MP < pokemon.skills[choice].mp_cost){
            cout << "Not enough MP, please choose another skill" << endl;
            
        }
        else{
            player_skill_calculation(pokemon,enemy,pokemon.skills[choice].name);
            //print all info
            cout << "pokemon HP: " << pokemon.HP << endl;
            cout << "pokemon MP: " << pokemon.MP << endl;
            cout << "enemy HP: " << enemy.HP << endl;
            cout << "pokemon attack: " << pokemon.attack << endl;
            cout << "pokemon defense: " << pokemon.defense << endl;
            cout << "enemy attack: " << enemy.attack << endl;
            cout << "enemy defense: " << enemy.defense << endl;
            
        }
    }
    else if (choice == 1){
        cout << "choose skill "<< choice +1 << endl;
        if (pokemon.MP < pokemon.skills[choice].mp_cost){
            cout << "Not enough MP, please choose another skill" << endl;
            
        }
        else{
            player_skill_calculation(pokemon,enemy,pokemon.skills[choice].name);
            
            //print all info
            cout << "pokemon HP: " << pokemon.HP << endl;
            cout << "pokemon MP: " << pokemon.MP << endl;
            cout << "enemy HP: " << enemy.HP << endl;
            cout << "pokemon attack: " << pokemon.attack << endl;
            cout << "pokemon defense: " << pokemon.defense << endl;
            cout << "enemy attack: " << enemy.attack << endl;
            cout << "enemy defense: " << enemy.defense << endl;

            
        }


    }
    else if (choice == 2){
        cout << "choose skill "<< choice + 1 << endl;
        if (pokemon.MP < pokemon.skills[choice].mp_cost){
            cout << "Not enough MP, please choose another skill" << endl;

            
        }
        else{
            player_skill_calculation(pokemon,enemy,pokemon.skills[choice].name);
            //print all info
            cout << "pokemon HP: " << pokemon.HP << endl;
            cout << "pokemon MP: " << pokemon.MP << endl;
            cout << "enemy HP: " << enemy.HP << endl;
            cout << "pokemon attack: " << pokemon.attack << endl;
            cout << "pokemon defense: " << pokemon.defense << endl;
            cout << "enemy attack: " << enemy.attack << endl;
            cout << "enemy defense: " << enemy.defense << endl;
            
            
        }
    }
    else if (choice == 3){
        cout << "choose skill " << choice +1 << endl;
        if (pokemon.MP < pokemon.skills[choice].mp_cost){
            cout << "Not enough MP, please choose another skill" << endl;
            
        }
        else{
            player_skill_calculation(pokemon,enemy,pokemon.skills[choice].name);

            //print all info
            cout << "pokemon HP: " << pokemon.HP << endl;
            cout << "pokemon MP: " << pokemon.MP << endl;
            cout << "enemy HP: " << enemy.HP << endl;
            cout << "pokemon attack: " << pokemon.attack << endl;
            cout << "pokemon defense: " << pokemon.defense << endl;
            cout << "enemy attack: " << enemy.attack << endl;
            cout << "enemy defense: " << enemy.defense << endl;


            
        }
    }
    else{
        cout << "error: invalid input for choice" << endl;

    }

   

}


int enemy_choose_skill(){
    random_device rd;
    uniform_int_distribution<int> dist(0, 3);
    return dist(rd);
}

void enemy_calculation(int choice, Pokemon &pokemon, Pokemon &enemy){

    if (choice == 0){ 
        cout << "enemy choose skill "<< choice +1 << endl; 
        if (enemy.MP < enemy.skills[choice].mp_cost){
            cout << "Not enough MP, please choose another skill" << endl;
            
        }
        else{
            enemy_skill_calculation(enemy,pokemon,enemy.skills[choice].name);
            //print all info
            cout << "pokemon HP: " << pokemon.HP << endl;
            cout << "pokemon MP: " << pokemon.MP << endl;
            cout << "enemy HP: " << enemy.HP << endl;
            cout << "pokemon attack: " << pokemon.attack << endl;
            cout << "pokemon defense: " << pokemon.defense << endl;
            cout << "enemy attack: " << enemy.attack << endl;
            cout << "enemy defense: " << enemy.defense << endl;
            
        }
    }
    else if (choice == 1){
        cout << "enemy choose skill "<< choice +1 << endl;
        if (enemy.MP < enemy.skills[choice].mp_cost){
            cout << "Not enough MP, please choose another skill" << endl;
            
        }
        else{
            enemy_skill_calculation(enemy,pokemon,enemy.skills[choice].name);
            
            //print all info
            cout << "pokemon HP: " << pokemon.HP << endl;
            cout << "pokemon MP: " << pokemon.MP << endl;
            cout << "enemy HP: " << enemy.HP << endl;
            cout << "pokemon attack: " << pokemon.attack << endl;
            cout << "pokemon defense: " << pokemon.defense << endl;
            cout << "enemy attack: " << enemy.attack << endl;
            cout << "enemy defense: " << enemy.defense << endl;
            
        }


}
    else if (choice == 2){
        cout << "enemy choose skill "<< choice + 1 << endl;
        if (enemy.MP < enemy.skills[choice].mp_cost){
            cout << "Not enough MP, please choose another skill" << endl;

            
        }
        else{
            enemy_skill_calculation(enemy,pokemon,enemy.skills[choice].name);
            //print all info
            cout << "pokemon HP: " << pokemon.HP << endl;
            cout << "pokemon MP: " << pokemon.MP << endl;
            cout << "enemy HP: " << enemy.HP << endl;
            cout << "pokemon attack: " << pokemon.attack << endl;
            cout << "pokemon defense: " << pokemon.defense << endl;
            cout << "enemy attack: " << enemy.attack << endl;
            cout << "enemy defense: " << enemy.defense << endl;
            
            
        }
    }
    else if (choice == 3){
        cout << "enemy choose skill " << choice +1 << endl;
        if (enemy.MP < enemy.skills[choice].mp_cost){
            cout << "Not enough MP, please choose another skill" << endl;
            
        }
        else{
            enemy_skill_calculation(enemy,pokemon,enemy.skills[choice].name);

            //print all info
            cout << "pokemon HP: " << pokemon.HP << endl;
            cout << "pokemon MP: " << pokemon.MP << endl;
            cout << "enemy HP: " << enemy.HP << endl;
            cout << "pokemon attack: " << pokemon.attack << endl;
            cout << "pokemon defense: " << pokemon.defense << endl;
            cout << "enemy attack: " << enemy.attack << endl;
            cout << "enemy defense: " << enemy.defense << endl;

            
        }
    }
    else{
        cout << "error: invalid input for choice" << endl;

    }

   

}



