#include "game.h"



Game::Game(vector<string> map) {
    this->kb = Keyboard();
    this->kb.listen();
    this->map = Map(map);
    this->screen = Screen(this->map.width, this->map.height);
}

void Game::draw() {
    
    this->screen.clear();
    // // print map.s
    // for (int i = 0; i < this->map.height; i++) {
    //     for (int j = 0; j < this->map.width; j++) {
    //         cout << this->map.s[i][j];
    //     }
    // }
    // // print screen.buffer
    // for (int i = 0; i < this->screen.height; i++) {
    //     for (int j = 0; j < this->screen.width; j++) {
    //         cout << this->screen.buffer[i][j];
    //     }
    //     cout << endl;
    // }

    this->screen.draw(0, 0, this->map.s);
    this->screen.draw(&this->objects);
    this->screen.draw(&this->player);
    
}

void Game::update() {
    this->screen.refresh();
}

void Game::input() {
    

}


void Game::main_loop() {
    this->screen.clean();
    while (true) {
        this->draw();
        this->update();
        vector<int> keys = {KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_ENTER, KEY_ESC, 'w', 'W', 's', 'S', 'a', 'A', 'd', 'D'};
        int k = this->kb.wait_for(keys);
        if (k == KEY_UP || k == 'w' || k == 'W') {
            this->player.move(0, -1, this->map);
        }
        if (k == KEY_DOWN || k == 's' || k == 'S') {
            this->player.move(0, 1, this->map);
        }
        if (k == KEY_LEFT || k == 'a' || k == 'A') {
            this->player.move(-1, 0, this->map);
        }
        if (k == KEY_RIGHT || k == 'd' || k == 'D') {
            this->player.move(1, 0, this->map);
        }
        if (k == KEY_ESC) {
            this->kb.stop();
            break;
        }
    }
    this->screen.clean();
}