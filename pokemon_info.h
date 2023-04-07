#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
ifstream fin;


class skills{
    public:
        string name;
        
        double mp_cost,Damage,Healing,Inattack,Indefence,Deattack,Dedefense,self_damage;

    
    

};
void get_pokemon_skill(map <string,skills> &pokemon_skill);