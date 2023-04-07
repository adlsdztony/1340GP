#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include "pokemon.h"
using namespace std;
ifstream fin;


class Skills{
    public:
        string name;
        
        double mp_cost,Damage,Healing,Inattack,Indefence,Deattack,Dedefense,self_damage;

    
    

};
void get_pokemon_skill(map <string,Skills> &pokemon_skill);
void get_pokemon_info(map <string,Pokemon> &pokemon_info);