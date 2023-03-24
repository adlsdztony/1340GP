#include "map.h"


Map::Map(int width, int height) {
    this->width = width;
    this->height = height;
    this->valid_map = vector<string>(height, string(width, '0'));
    this->s = vector<string>(width, string(height, ' '));
}

Map::Map(vector<string> map, vector<string> valid_map) {
    this->width = map[0].size();
    this->height = map.size();
    this->valid_map = valid_map;
    this->s = map;
}

Map::Map(vector<string> map){
    this->width = map[0].size();
    this->height = map.size();
    this->valid_map = vector<string>(height, string(width, '0'));
    // init valid_map
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (map[i][j] == '`') {
                this->valid_map[i][j] = '1';
                map[i][j] = ' ';
            }
        }
    }
    this->s = map;
}

void Map::add_interact(int x, int y, char c) {
    this->valid_map[y][x] = c;
}

void Map::add_interact_object(Object &object, char name) {
    for (int i = 0; i < object.s.size(); i++) {
        for (int j = 0; j < object.s[0].size(); j++) {
            this->valid_map[object.y + i][object.x + j] = name;
        }
    }
}