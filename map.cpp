#include "map.h"


Map::Map(int width, int height) {
    this->x = 0;
    this->y = 0;
    this->width = width;
    this->height = height;
    this->valid_map = vector<string>(height, string(width, '0'));
    this->s = vector<string>(width, string(height, ' '));
}

Map::Map(const vector<string> &ma, const vector<string> &valid_map, const map<char, string> &interact_map) {
    this->x = 0;
    this->y = 0;
    this->s = ma;
    this->script2format();
    this->width = this->s[0].size();
    this->height = this->s.size();
    this->valid_map = valid_map;
    this->interact_map = interact_map;
}

void Map::init(vector<string> &map, vector<string> &valid_map) {
    this->x = 0;
    this->y = 0;
    this->s = map;
    this->script2format();
    this->width = this->s[0].size();
    this->height = this->s.size();
    this->valid_map = valid_map;
}

Map::Map(vector<string> &map){
    this->x = 0;
    this->y = 0;
    this->s = map;
    this->script2format();
    this->width = this->s[0].size();
    this->height = this->s.size();
    this->valid_map = vector<string>(height, string(width, '0'));
    // init valid_map
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (this->s[i][j] == ' ') {
                this->valid_map[i][j] = '1';
                // this->s[i][j] = ' ';
            }
        }
    }
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