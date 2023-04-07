#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include "pokemon.h"
using namespace std;


void get_pokemon_skill(map <string,Skills> &pokemon_skill){ 
    ifstream fin;
    string test,skill_name;
    fin.open("Pokemon_skill.txt");
    int pos,pos1; 
    
    double mp_cost,Damage,Healing,Inattack,Indefence,Deattack,Dedefense,self_damage;
    //test the file open success or not
    if (fin.fail()){
        cout << "Error in opening the file."<< endl;
    }
    else{
        
        while(getline(fin,test)){
            
            //test the last line is -1 and break
            if (test =="-1"){
                break;
            }else{
                Skills skill;
                //get info
                
                pos = test.find(" ");
                skill_name = test.substr(0,pos);
                skill.name = skill_name;
                pos1 = pos;

                pos= test.find(" ",pos1+1);
                mp_cost = stod(test.substr(pos1+1,pos-pos1-1));
                skill.mp_cost = mp_cost;
                pos1 = pos;

                pos= test.find(" ",pos1+1);
                Damage = stod(test.substr(pos1+1,pos-pos1-1));
                skill.Damage = Damage;
                pos1 = pos;

                pos= test.find(" ",pos1+1);
                Healing = stod(test.substr(pos1+1,pos-pos1-1));
                skill.Healing = Healing;
                pos1 = pos;

                pos= test.find(" ",pos1+1);
                Inattack = stod(test.substr(pos1+1,pos-pos1-1));
                skill.Inattack = Inattack;
                pos1 = pos;

                pos= test.find(" ",pos1+1);
                Indefence = stod(test.substr(pos1+1,pos-pos1-1));
                skill.Indefence = Indefence;
                pos1 = pos;

                pos= test.find(" ",pos1+1);
                Deattack = stod(test.substr(pos1+1,pos-pos1-1));
                skill.Deattack = Deattack;
                pos1 = pos;

                pos= test.find(" ",pos1+1);
                Dedefense = stod(test.substr(pos1+1,pos-pos1-1));
                skill.Dedefense = Dedefense;
                pos1 = pos;

                pos= test.find(" ",pos1+1);
                self_damage = stod(test.substr(pos1+1,pos-pos1-1));
                skill.self_damage = self_damage;
                pos1 = pos;
             
                //insert the skill into map
                pokemon_skill.insert(pair <string,Skills> (skill_name,skill));         
                   
            }       
        }
    } 
    
    
}

void get_pokemon_element(map <string,Pokemon> &pokemon_element){
    map<string, Skills> pokemon_skill;
    get_pokemon_skill(pokemon_skill);

    ifstream fin;
    string test,pokemon_name,type;

    int pos,pos1;
    double HP,MP,attack,defense;
    
    vector<Skills> skill;
    //open the file
    fin.open("Pokemon_info.txt");
    //test the file open success or not
    if (fin.fail()){
        cout << "Error in opening the file."<< endl;
    }
    else{
        while(getline(fin,test)){
            //test the last line is -1 and break
            if (test =="-1"){
                break;
            }else{
                Pokemon pokemon;
                //get info
                pos = test.find(" ");
                pokemon_name = test.substr(0,pos);
                pokemon.name = pokemon_name;
                pos1 = pos;

                pos= test.find(" ",pos1+1);
                type = test.substr(pos1+1,pos-pos1-1);
                pokemon.type = type;
                pos1 = pos;

                pos= test.find(" ",pos1+1);
                HP = stod(test.substr(pos1+1,pos-pos1-1));
                pokemon.HP = HP;
                pos1 = pos;

                pos= test.find(" ",pos1+1);
                MP = stod(test.substr(pos1+1,pos-pos1-1));
                pokemon.MP = MP;
                pos1 = pos;

                pos= test.find(" ",pos1+1);
                attack = stod(test.substr(pos1+1,pos-pos1-1));
                pokemon.attack = attack;
                pos1 = pos;

                pos= test.find(" ",pos1+1);
                defense = stod(test.substr(pos1+1,pos-pos1-1));
                pokemon.defense = defense;
                pos1 = pos;
                
                for(int i = 0; i < 4; i++){
                    pos = test.find(" ",pos1+1);
                    if (pos == -1){
                        pos = test.length();
                    }                    
                    
                    skill.push_back(pokemon_skill.at(test.substr(pos1+1,pos-pos1-1)));
                    pos1 = pos;
                }
                pokemon.skill = skill;
                
                
                //insert the pokemon into the map
                pokemon_element.insert(pair <string,Pokemon> (pokemon_name,pokemon));         
                   
            }       
        }
        

}
}
    
// int main(){
//     map <string,Pokemon> pokemon_element;
//     map <string,Skills> pokemon_skill;
//     get_pokemon_element(pokemon_element);
//     get_pokemon_skill(pokemon_skill);
//     pokemon_skill["water_gun"];
//     for (map<string,Skills>::iterator itr = pokemon_skill.begin();itr != pokemon_skill.end();itr++){
//         cout << (*itr).first << endl;
//         cout << (*itr).second.name << endl;
    
//     }

//     for (map<string,Pokemon>::iterator itr = pokemon_element.begin();itr != pokemon_element.end();itr++){
//         cout << (*itr).first << endl;
//         cout << (*itr).second.name << endl;
    
//     }
    
//     return 0;
// }


