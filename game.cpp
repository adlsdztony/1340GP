#include "game.h"



Game::Game(vector<string> map) {
    this->kb = Keyboard();
    this->kb.listen();
    this->map = Map(map);
    this->screen = Screen(this->map.width, this->map.height);
}

Game::Game(Map &map) {
    this->kb = Keyboard();
    this->kb.listen();
    this->map = map;
    this->screen = Screen(this->map.width, this->map.height);
}


void Game::add_notice_E() {
    Object E = Object(0, 0, vector<string>(1, "E"));
    this->screen.draw(&E);
}


void Game::draw() {
    
    this->screen.clear();


    this->screen.draw(&this->map);
    this->screen.draw(this->objects);
    this->screen.draw(&this->player);
    if (this->E) {
        add_notice_E();
    }
    
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
        int result;
        if (k == KEY_ESC) {
            break;
        }
        if (k == KEY_UP || k == 'w' || k == 'W') {
            result = this->player.move(0, -1, this->map);
        }
        if (k == KEY_DOWN || k == 's' || k == 'S') {
            result = this->player.move(0, 1, this->map);
        }
        if (k == KEY_LEFT || k == 'a' || k == 'A') {
            result = this->player.move(-1, 0, this->map);
        }
        if (k == KEY_RIGHT || k == 'd' || k == 'D') {
            result = this->player.move(1, 0, this->map);
        }
        if (result > 0) {
            this->E = result;
        } else {
            this->E = 0;
        }
    }
    this->kb.stop();
    cin.get();
    this->kb.stored_settings.c_lflag |= ECHO;
	tcsetattr(0,TCSANOW,&this->kb.stored_settings);
    printf("\033[?25h");
}