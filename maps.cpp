#include "maps.h"

void init_maps(map<string, Map> &maps) {
    maps["chuntian_path"] = Map(chuntian_path, chuntian_path_vaild, chuntian_path_interact);
    maps["chuntian_town"] = Map(chuntian_town, chuntian_town_vaild, chuntian_town_interact);
    maps["Fairy_society_center"] = Map(Fairy_society_center, Fairy_society_center_vaild, Fairy_society_center_interact);
    maps["Fairy_society_center1"] = Map(Fairy_society_center1, Fairy_society_center1_vaild, Fairy_society_center1_interact);
    maps["grassland"] = Map(grassland, grassland_vaild, grassland_interact);
    maps["hill"] = Map(hill, hill_vaild, hill_interact);
    maps["home"] = Map(home, home_vaild, home_interact);
    maps["market"] = Map(market, market_vaild, market_interact);
    maps["market1"] = Map(market1, market1_vaild, market1_interact);
    maps["qiushui_town"] = Map(qiushui_town, qiushui_town_vaild, qiushui_town_interact);
    maps["riverside"] = Map(riverside, riverside_vaild, riverside_interact);
}
