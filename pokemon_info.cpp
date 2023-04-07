#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include "pokemon_info.h"
using namespace std;


// void get_pokemon_info(map <string,string> &info){ 
//     ifstream fin;
//     string test;
//     test = "0";
//     fin.open("Pokemon_info.txt");
//     int pos;  
//     //test the file open success or not
//     if (fin.fail()){
//         cout << "Error in opening the file."<< endl;
//     }
//     else{
        
//         while(test != "-1"){
//             getline(fin,test);
//             //test the last line is -1 and break
//             if (test =="-1"){
//                 break;
//             }else{
//                 //get info
//                 pos = test.find(" ");
//                 info.insert(pair <string,string> (test.substr(0,pos),test));              
//             }       
//         }
//     } 
//     for (map<string,string>::iterator itr = info.begin();itr != info.end();itr++){
//         cout << (*itr).first << endl;
//         cout << (*itr).second << endl;
        
//     }   
// }

void get_pokemon_skill(map <string,skills> &pokemon_skill){ 
    ifstream fin;
    string test,skill_name;
    test = "0";
    
    fin.open("Pokemon_skill.txt");
    int pos,pos1; 
    
    double mp_cost,Damage,Healing,Inattack,Indefence,Deattack,Dedefense,self_damage;
    //test the file open success or not
    if (fin.fail()){
        cout << "Error in opening the file."<< endl;
    }
    else{
        
        while(test != "-1"){
            getline(fin,test);
            //test the last line is -1 and break
            if (test =="-1"){
                break;
            }else{
                //get info
                
                pos = test.find(" ");
                skill_name = test.substr(0,pos);
                
                skills skill;
                
                skill.name = skill_name;
               
                pos1= test.find(" ",pos+1);
                mp_cost = stod(test.substr(pos,pos1));
                skill.mp_cost = mp_cost;

                pos = test.find(" ",pos1+1);
                Damage = stod(test.substr(pos1,pos));
                skill.Damage = Damage;

                pos1= test.find(" ",pos+1);
                Healing = stod(test.substr(pos,pos1));
                skill.Healing = Healing;

                pos = test.find(" ",pos1+1);
                Inattack = stod(test.substr(pos1,pos));
                skill.Inattack = Inattack;

                pos1= test.find(" ",pos+1);
                Indefence = stod(test.substr(pos,pos1));
                skill.Indefence = Indefence;
                
                pos = test.find(" ",pos1+1);
                Deattack= stod(test.substr(pos1,pos));
                skill.Deattack = Deattack;

                pos1= test.find(" ",pos+1);
                Dedefense = stod(test.substr(pos,pos1));
                skill.Dedefense = Dedefense;

                pos = test.length();
                self_damage= stod(test.substr(pos1,pos));
                skill.self_damage = self_damage;
                
                pokemon_skill.insert(pair <string,skills> (skill_name,skill));         
                   
            }       
        }
    } 
    
    
}
    
// int main(){
//     map <string,string> pokemon_element;
//     map <string,skills> pokemon_skill;
//     //get_pokemon_info(pokemon_info);
//     get_pokemon_skill(pokemon_skill);
//     pokemon_skill["water_gun"];
//     for (map<string,skills>::iterator itr = pokemon_skill.begin();itr != pokemon_skill.end();itr++){
//         cout << (*itr).first << endl;
//         cout << (*itr).second.name << endl;
    
//     }
//     return 0;
// }



