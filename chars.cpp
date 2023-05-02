//
// Created by KiKi on 2023/5/2.
//

#include "chars.h"
#include <string>
#include <vector>

void init_chars(map<string, vector<string>> &chars) {
    chars["Charmeleon"] = Charmeleon_fire;
    chars["Wartortle"] = Wartortle_water;
    chars["Weepinbell"] = Weepinbell_grass;
    chars["Ninetales"] = Ninetales_fire;
    chars["Blastoise"] = Blastoise_water;
    chars["Grovyle"] = Grovyle_gress;
    chars["Rapidash"] = Rapidash_fire;
    chars["Vaporeon"] = Vaporeon_water;
    chars["Venusaur"] = Venusaur_grass;
    chars["Arcanine"] = Arcanine_fire;
    chars["Gyarados"] = Gyarados_water;
    chars["Sceptile"] = Sceptile_grass;
    chars["Sentret"] = Sentret_normal;
    chars["Furret"] = Furret_normal;
};