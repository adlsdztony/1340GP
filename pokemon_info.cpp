#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include "pokemon.h"
#include "chars.cpp"
using namespace std;


void get_pokemon_skill(map <string, Skill> &pokemon_skills){ 
    ifstream fin;
    string test,skill_name;
    fin.open("Pokemon_skill.txt");
    int pos,pos1; 
    
    double mp_cost,Damage,Healing,Inattack,Indefense,Deattack,Dedefense,self_damage;
    //test the file open success or not
    if (fin.fail()){
        cout << "Error in opening the file."<< endl;
    }
    else{
        
        while(getline(fin,test)){
            
            //test the last line is -1 and break
            if (test == "-1"){
                break;
            }else{
                //get info by using constructor
                
                pos = test.find(" ");
                skill_name = test.substr(0,pos);
                
                pos1 = pos;

                pos= test.find(" ",pos1+1);
                mp_cost = stod(test.substr(pos1+1,pos-pos1-1));
                
                pos1 = pos;

                pos= test.find(" ",pos1+1);
                Damage = stod(test.substr(pos1+1,pos-pos1-1));
                
                pos1 = pos;

                pos= test.find(" ",pos1+1);
                Healing = stod(test.substr(pos1+1,pos-pos1-1));
                
                pos1 = pos;

                pos= test.find(" ",pos1+1);
                Inattack = stod(test.substr(pos1+1,pos-pos1-1));
                
                pos1 = pos;

                pos= test.find(" ",pos1+1);
                Indefense = stod(test.substr(pos1+1,pos-pos1-1));
                
                pos1 = pos;

                pos= test.find(" ",pos1+1);
                Deattack = stod(test.substr(pos1+1,pos-pos1-1));
               
                pos1 = pos;

                pos= test.find(" ",pos1+1);
                Dedefense = stod(test.substr(pos1+1,pos-pos1-1));
                
                pos1 = pos;

                pos= test.find(" ",pos1+1);
                self_damage = stod(test.substr(pos1+1,pos-pos1-1));
                
                pos1 = pos;
                
                Skill skill(skill_name,mp_cost,Damage,Healing,Inattack,Indefense,Deattack,Dedefense,self_damage);
                
                //insert the skill into map
                pokemon_skills.insert(pair <string,Skill> (skill_name,skill));         
                   
            }       
        }
    } 
    
    
}

void get_pokemon_element(map <string,Pokemon> &pokemon_element){
    map<string, Skill> pokemon_skills;
    get_pokemon_skill(pokemon_skills);
    
    
    map <string,vector<string>>  pokemon_picture;
    init_chars(pokemon_picture);

    ifstream fin;
    string test,pokemon_name;

    char type;

    int pos,pos1;
    double HP,MP,attack,defense;
    
    vector<Skill> skills;
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
                skills.clear();

                //get info
                pos = test.find(" ");
                pokemon_name = test.substr(0,pos);
                
                pos1 = pos;

                pos= test.find(" ",pos1+1);
                string temp_type = test.substr(pos1+1,pos-pos1-1);
                
                if (temp_type == "fire"){
                    type = 'F';
                }else if (temp_type == "water"){
                    type = 'W';
                }else if (temp_type == "grass"){
                    type = 'G';
                }else if (temp_type == "normal"){
                    type = 'E';
                }
                
                pos1 = pos;

                pos= test.find(" ",pos1+1);
                HP = stod(test.substr(pos1+1,pos-pos1-1));
                
                pos1 = pos;

                pos= test.find(" ",pos1+1);
                MP = stod(test.substr(pos1+1,pos-pos1-1));
                
                pos1 = pos;

                pos= test.find(" ",pos1+1);
                attack = stod(test.substr(pos1+1,pos-pos1-1));
                
                pos1 = pos;

                pos= test.find(" ",pos1+1);
                defense = stod(test.substr(pos1+1,pos-pos1-1));
                
                pos1 = pos;
                
                for(int i = 0; i < 4; i++){
                    pos = test.find(" ",pos1+1);
                    if (pos == -1){
                        pos = test.length();
                    }                    
                    
                    skills.push_back(pokemon_skills.at(test.substr(pos1+1,pos-pos1-1)));
                    pos1 = pos;
                }
                
                //vector<string> pkm(9, "<format front=cyan >@@@@@@@@@@@@@@@@@@@@@@@@</format>");

                vector<string> pkm = pokemon_picture.at(pokemon_name);

                //get info by using constructor
                Pokemon pokemon(pkm, pokemon_name, type, HP, MP, attack, defense, skills);
                
                
                //insert the pokemon into the map
                pokemon_element.insert(pair <string,Pokemon> (pokemon_name,pokemon));         
                   
            }       
        }
        

}
}
    
// int main(){
//     map <string,Pokemon> pokemon_element;
//     map <string,Skill> pokemon_skills;
//     get_pokemon_element(pokemon_element);
//     // get_pokemon_skill(pokemon_skills);
//     // for (map<string,Skill>::iterator itr = pokemon_skills.begin();itr != pokemon_skills.end();itr++){
//     //     cout << (*itr).first << endl;
//     //     cout << (*itr).second.name << endl;
    
//     // }

//     for (map<string,Pokemon>::iterator itr = pokemon_element.begin();itr != pokemon_element.end();itr++){
//         cout << (*itr).first << endl;
//         cout << (*itr).second.name << endl;
    
//     }
    
//     return 0;
// }


