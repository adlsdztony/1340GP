#include "fight.h"

Fight::Fight(Pokemon *p1, Pokemon *p2, Keyboard *kb, Screen* screen)
{
    p1->x = 2;
    p1->y = 5;
    p2->x = 41;
    p2->y = 5;
    this->p1 = p1;
    this->p2 = p2;
    this->screen = screen;
    this->kb = kb;
}


void Fight::draw()
{
    this->screen->clear();
    this->screen->draw(0, 0, fight_map);

    // draw p1 and p2
    this->screen->draw(this->p1);
    this->screen->draw(this->p2);


    // draw p1's skills
    for (int i = 0; i < this->p1->skills.size(); i++)
    {
        string skill_format = FRONT_CYAN BOLD;
        if (i == this->selected)
        {
            skill_format = FRONT_CYAN BOLD REVERSE;
        }
        Object skill = Object(2 + i*13, 15, this->p1->skills[i].name, Format(0, 0, this->p1->skills[i].name.length(), skill_format));
        this->screen->draw(&skill);
        Object damage = Object(10 + i*13, 16, to_string((int)this->p1->skills[i].damage), Format(0, 0, to_string((int)this->p1->skills[i].damage).length(), FRONT_YELLOW BOLD));
        this->screen->draw(&damage);
        Object mp_cost = Object(10 + i*13, 17, to_string((int)this->p1->skills[i].mp_cost), Format(0, 0, to_string((int)this->p1->skills[i].mp_cost).length(), FRONT_BLUE BOLD));
        this->screen->draw(&mp_cost);
    }

    // draw p1 and p2 name
    this->screen->draw(2, 4, this->p1->name);
    this->screen->draw(67 - this->p2->name.length() - 2, 4, this->p2->name);

    // draw types
    this->screen->draw(17, 4, this->p1->type);
    this->screen->draw(45, 4, this->p2->type);

    // draw turn
    Object turn = Object(37, 0, to_string(this->turn), Format(0, 0, to_string(this->turn).length(), BOLD));
    this->screen->draw(&turn);



    // calculate HP and MP bar length
    int p1_hp_bar_length = this->p1->HP * 12 / this->p1->max_HP;
    int p1_mp_bar_length = this->p1->MP * 11 / this->p1->max_MP;
    int p2_hp_bar_length = this->p2->HP * 12 / this->p2->max_HP;
    int p2_mp_bar_length = this->p2->MP * 11 / this->p2->max_MP;



    // draw HP and MP bar
    char bar = '=';

    Object hp_bar = Object(6, 2, string(p1_hp_bar_length, bar), Format(0, 0, p1_hp_bar_length, FRONT_RED BOLD));
    this->screen->draw(&hp_bar);

    Object mp_bar = Object(6, 3, string(p1_mp_bar_length, bar), Format(0, 0, p1_mp_bar_length, FRONT_BLUE BOLD));
    this->screen->draw(&mp_bar);

    Object p2_hp_bar = Object(67 - 5 - p2_hp_bar_length, 2, string(p2_hp_bar_length, bar), Format(0, 0, p2_hp_bar_length, FRONT_RED BOLD));
    this->screen->draw(&p2_hp_bar);

    Object p2_mp_bar = Object(67 - 5 - p2_mp_bar_length, 3, string(p2_mp_bar_length, bar), Format(0, 0, p2_mp_bar_length, FRONT_BLUE BOLD));
    this->screen->draw(&p2_mp_bar);


    // draw HP and MP value
    this->screen->draw(19, 2, to_string((int)this->p1->HP) + "/" + to_string((int)this->p1->max_HP));
    this->screen->draw(18, 3, to_string((int)this->p1->MP) + "/" + to_string((int)this->p1->max_MP));
    this->screen->draw(67 - 19 - to_string((int)this->p2->HP).length() - to_string((int)this->p2->max_HP).length(), 2, to_string((int)this->p2->HP) + "/" + to_string((int)this->p2->max_HP));
    this->screen->draw(67 - 19 - to_string((int)this->p2->HP).length() - to_string((int)this->p2->max_HP).length(), 2, to_string((int)this->p2->HP) + "/" + to_string((int)this->p2->max_HP));
    this->screen->draw(67 - 19 - to_string((int)this->p2->HP).length() - to_string((int)this->p2->max_HP).length(), 2, to_string((int)this->p2->HP) + "/" + to_string((int)this->p2->max_HP));
    this->screen->draw(67 - 18 - to_string((int)this->p2->MP).length() - to_string((int)this->p2->max_MP).length(), 3, to_string((int)this->p2->MP) + "/" + to_string((int)this->p2->max_MP));

    // show screen
    this->screen->refresh();
    
}

int Fight::update(int choice)
{
    if (p1->skills[choice].mp_cost > p1->MP)
    {
        return -1;
    }
    player_calculation(choice, *this->p1, *this->p2);


    if (this->p2->HP <= 0)
    {
        this->p2->HP = 0;
        this->screen->clean();
        this->draw();
        this->screen->refresh();
        return 1;
    }
    

    enemy_calculation(*this->p1, *this->p2);

    if (this->p1->HP <= 0)
    {
        this->p1->HP = 0;
        this->screen->clean();
        this->draw();
        this->screen->refresh();
        return 2;
    }
    turn++;

    return 0;
}

int Fight::input()
{
    return this->kb->wait_for({KEY_LEFT, KEY_RIGHT, KEY_ENTER, 'c', 'w', 'b', 'a', 'd'});
}


void Fight::bag()
{
    // TODO bag
}


char Fight::main_loop()
{
    int input;
    
    while (true)
    {
        this->draw();
        input = this->input();
        if (input == KEY_LEFT || input == 'a'){
            selected = (selected + 3) % 4;
        }
        else if (input == KEY_RIGHT || input == 'd'){
            selected = (selected + 1) % 4;
        }
        else if (input == 'w'){
            int c = show_notice("Do you want to withdraw?", {"YES", "NO"}, this->kb, this->screen);
            if (c == 0){
                break;
            }
        }
        else if (input == 'b'){
            this->bag();
        }
        else if (input == 'c'){
            int c = show_notice("Do you want to catch?", {"YES", "NO"}, this->kb, this->screen);
            if (c == 0){
                if (this->p2->HP < this->p2->max_HP / 3){
                    show_notice("Notice!", {"Success!"}, this->kb, this->screen);
                    return 'c';
                }
                else{
                    show_notice("Notice!", {"Failed!"}, this->kb, this->screen);
                }
            }
        }
        else if (input == KEY_ENTER){
            int result = this->update(selected);
            if (result == 1){
                show_notice("Notice!", {"You win!"}, this->kb, this->screen);
                break;
            }
            else if (result == 2){
                show_notice("Notice!", {"Failed!"}, this->kb, this->screen);
                break;
            }
            else if (result == -1){
                show_notice("Notice!", {"Not enough MP!"}, this->kb, this->screen);
            }
        }
    }
    return 'e';
}

char Fight::start()
{
    this->screen->clean();
    return this->main_loop();
}
