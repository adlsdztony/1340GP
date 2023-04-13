#include "game.h"




Game::Game(vector<string> game_map) {
    init_maps(this->maps_map);
    this->kb = Keyboard();
    this->kb.listen();
    this->game_map = Map(game_map);
    this->screen = Screen(this->game_map.width, this->game_map.height);
}

Game::Game(const Map &game_map) {
    init_maps(this->maps_map);
    this->kb = Keyboard();
    this->kb.listen();
    this->game_map = game_map;
    this->screen = Screen(this->game_map.width, this->game_map.height);
}


void Game::add_notice_E() {
    Object E = Object(0, 0, vector<string>(1, "E"));
    this->screen.draw(&E);
}


void Game::draw() {
    
    this->screen.clear();


    this->screen.draw(&this->game_map);
    this->screen.draw(this->objects);
    this->screen.draw(&this->player);
    if (this->E) {
        add_notice_E();
    }
    this->screen.refresh();
    
}


std::vector<std::string> split(const std::string& str, char delim) {
    std::size_t previous = 0;
    std::size_t current = str.find(delim);
    std::vector<std::string> elems;
    while (current != std::string::npos) {
        if (current > previous) {
            elems.push_back(str.substr(previous, current - previous));
        }
        previous = current + 1;
        current = str.find(delim, previous);
    }
    if (previous != str.size()) {
        elems.push_back(str.substr(previous));
    }
    return elems;
}

void Game::update(int e) {
    // TODO deal with the event
    if (this->game_map.interact_map.find(e) != this->game_map.interact_map.end()) {
        string code = this->game_map.interact_map.at(e);
        // split code
        vector<string> codes = split(code, ' ');
        if (this->maps_map.find(codes[0]) != maps_map.end()) {
            this->game_map = Map(maps_map.at(codes[0]));
            if (codes.size() >= 3) {
                this->player.x = stoi(codes[1]);
                this->player.y = stoi(codes[2]);
            }
        }
    }
}


void Game::main_loop() {
    this->screen.clean();
    while (true) {
        this->draw();
        
        vector<int> keys = {KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_ENTER, KEY_ESC, 'w', 'W', 's', 'S', 'a', 'A', 'd', 'D', 'e', 'E'};
        int k = this->kb.wait_for(keys);
        int result;
        if (k == KEY_ESC) {
            break;
        }
        if ((k == 'e' || k == 'E') && this->E) {
            if (this->E) {
                this->update(this->E);
                this->E = 0;
            }
        }
        if (k == KEY_UP || k == 'w' || k == 'W') {
            result = this->player.move(0, -1, this->game_map);
        }
        if (k == KEY_DOWN || k == 's' || k == 'S') {
            result = this->player.move(0, 1, this->game_map);
        }
        if (k == KEY_LEFT || k == 'a' || k == 'A') {
            result = this->player.move(-1, 0, this->game_map);
        }
        if (k == KEY_RIGHT || k == 'd' || k == 'D') {
            result = this->player.move(1, 0, this->game_map);
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