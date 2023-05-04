#include "game.h"

// store the state of the game to the file
void State::store(string file_name){
    ofstream fout(file_name);
    fout << this->x << endl;
    fout << this->y << endl;
    fout << this->map_name << endl;
    fout << this->pokemons.size() << endl;
    for (int i = 0; i < this->pokemons.size(); i++) {
        fout << this->pokemons[i].name << endl;
        fout << this->pokemons[i].HP << endl;
        fout << this->pokemons[i].MP << endl;
    }
    fout.close();
}

// load the state of the game from the file
void State::load(string file_name){
    // clear the state
    this->pokemons.clear();

    if (file_name == "") {
        return;
    }
    // if no file exists
    if (!ifstream(file_name)) {
        this->x = 1;
        this->y = 1;
        this->map_name = "home";
        return;
    }
    ifstream fin(file_name);
    int x;
    int y;
    string map_name;
    fin >> x;
    fin >> y;
    fin >> map_name;
    this->x = x;
    this->y = y;
    this->map_name = map_name;
    int n;
    fin >> n;
    for (int i = 0; i < n; i++) {
        string name;
        int HP;
        int MP;
        fin >> name;
        fin >> HP;
        fin >> MP;
        this->pokemons.push_back(Pokemon(name, HP, MP, this->pokemon_element));
    }
    fin.close();
}


// constructor of Game
Game::Game() {
    init_maps(this->maps_map);
    this->kb = Keyboard();
    this->kb.listen();
    cout << "test main" << endl;
    this->state = State();
    this->state.load("game_state.txt");
    vector<string> playe = {
        "<format front=red >@</format>",
        // "@",
    };
    this->player = Player(this->state.x, this->state.y, playe);
    this->game_map = this->maps_map.at(this->state.map_name);
    this->screen = Screen(this->game_map.width, this->game_map.height);
}


// draw the notice of pressing E
void Game::add_notice_E() {
    // Object E = Object(0, 0, vector<string>(1, "E"));
    Window E(47, 1, 19, 1, "Press <format front=blue >E</format>", "", 0);
    this->screen.draw(&E);
}


// draw all the objects in the game
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

// chat with the npc
int Game::chat(string title, vector<string> content){
    int key_pressed;
    for (int i = 0; i < content.size(); i++) {
        // draw chat
        Window chat(1, 13, 66, 5, title, content[i], 1);
        this->screen.draw(&chat);
        
        // draw tips
        Object tips = Object(3, 14, vector<string>(1, "Press <format front=blue >E</format>"));
        this->screen.draw(&tips);

        this->screen.refresh();
        key_pressed = this->kb.wait_for({KEY_ENTER, 'e', 'E', 'q', 'Q'});
    }
    if (key_pressed == 'q' || key_pressed == 'Q') {
            return 0;
        }
        else {
            return 1;
    }
    return -1;
}

// fight with the enemy
void Game::fight(string enemy_name){
    // select pokemon
    vector<string> pokemon_names;
    for (int i = 0; i < this->state.pokemons.size(); i++) {
        pokemon_names.push_back(this->state.pokemons[i].name);
    }

    pokemon_names.push_back("cancel");

    int pkm_index;

    while (true) {
        Notice s_pkm(20, 3, 26, 11, "select pokemon", pokemon_names);
        pkm_index = s_pkm.select(&this->kb, &this->screen);

        // check cancel
        if (pkm_index == this->state.pokemons.size()) {
            return;
        }
        // check hp
        if (this->state.pokemons[pkm_index].HP <= 0) {
            show_notice("This pokemon is dead", {"OK"}, &this->kb, &this->screen);
            continue;
        }
        else {
            break;
        }
    }
    // get enemy
    Pokemon* p1 = &this->state.pokemons[pkm_index];
    Pokemon p2 = this->state.pokemon_element.at(enemy_name);
    Fight f(p1, &p2, &this->kb, &this->screen);
    cout << "Fight start" << endl;
    char r = f.start();
    if (r == 'c') {
        // check if pokemon in state.pokemons is exit
        for (int i = 0; i < this->state.pokemons.size(); i++) {
            if (this->state.pokemons[i].name == p2.name) {
                return;
            }
        }
        // add pokemon to state.pokemons
        this->state.pokemons.push_back(p2);
    }
}

// interact with the object
void Game::update(int e) {
    if (this->game_map.interact_map.find(e) != this->game_map.interact_map.end()) {
        string code = this->game_map.interact_map.at(e);
        // split code
        vector<string> codes = split(code, ' ');
        // switch map
        if (this->maps_map.find(codes[0]) != this->maps_map.end()) {
            this->game_map = Map(maps_map.at(codes[0]));
            this->state.map_name = codes[0];
            if (codes.size() >= 3) {
                this->player.x = stoi(codes[1]);
                this->player.y = stoi(codes[2]);
                return;
            }
        }

        for (int i = 0; i < codes.size(); i+=2) {

            // chat function
            if (codes[i] == "chat"){

                if (chat_map.find(codes[i+1]) != chat_map.end()) {
                    this->chat(codes[i+1], chat_map.at(codes[i+1]));
                };
            }

            // fight function
            if (codes[i] == "fight") {
                if (codes.size() >= i) {
                    this->fight(codes[i+1]);
                }
            }

            // recover function
            if (codes[i] == "recover") {
                for (int j = 0; j < this->state.pokemons.size(); j++) {
                    this->state.pokemons[j].HP = this->state.pokemons[j].max_HP;
                    this->state.pokemons[j].MP = this->state.pokemons[j].max_MP;
                }
                return;
            }


        }
    }
}

// save game state and exit
void Game::save_and_exit(){
    this->state.x = this->player.x;
    this->state.y = this->player.y;
    this->state.store("game_state.txt");

    this->kb.stop();
    this->screen.clean();
    cout << "Bye!" << endl;
    
    this->kb.stored_settings.c_lflag |= ECHO;
    tcsetattr(0,TCSANOW,&this->kb.stored_settings);
    printf("\033[?25h");
}

void Game::main_loop() {
    this->screen.clean();
    // print start map
    for (int i = 0; i < start_map.size(); i++) {
        cout << start_map[i] << endl;
    }
    this->kb.wait_for({KEY_ENTER, KEY_SPACE});
    // check if game_state.txt is exit
    int c;
    ifstream f("game_state.txt");
    if (f.good()) {
        c = show_notice("Welcome to Pokemon", {"New Game", "Continue"}, &this->kb, &this->screen);
    } else {
        c = show_notice("Welcome to Pokemon", {"New Game"}, &this->kb, &this->screen);
    }
    if (c == 0) {
        ofstream fout("game_state.txt");
        fout << 1 << endl;
        fout << 1 << endl;
        fout << "home" << endl;
        fout << 1 << endl;
        fout << "Charmeleon" << endl;
        fout << 90 << endl;
        fout << 40 << endl;
        fout.close();
        this->state.load("game_state.txt");
        this->game_map = Map(maps_map.at("home"));
        this->player.x = 1;
        this->player.y = 1;
    }

    
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

    this->save_and_exit();
}
