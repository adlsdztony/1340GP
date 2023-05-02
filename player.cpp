#include "player.h"


Player::Player(int x, int y, vector<string> s) {
    this->x = x;
    this->y = y;
    this->s = s;
    this->script2format();
    this->width = this->s[0].length();
    this->height = this->s.size();
}

int Player::move(int dx, int dy, Map &map){

    if (this->y + dy < 0 ) {
        return 'U';
    }
    if (this->x + dx < 0 ) {
        return 'L';
    }
    if (this->y + dy + this->height > map.height) {
        return 'D';
    }
    if (this->x + dx + this->width > map.width) {
        return 'R';
    }

    // chack area to move to are valid
    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            char c = map.valid_map[this->y + dy + i][this->x + dx + j];
            if (c == '0') {
                c = map.valid_map[this->y + i][this->x + j];
                if (c != '1'){
                    return c;
                }
                return -1;
            }
            if (c != '1') {
                this->x += dx;
                this->y += dy;
                return c;
            }
        }
    }

    
    this->x += dx;
    this->y += dy;
    return 0;
}

void Player::jump(int x, int y, Map &map) {
    // chack area to move to are valid
    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            if (map.valid_map[y + i][x + j] == '0') {
                return;
            }
        }
    }
    this->x = x;
    this->y = y;
}