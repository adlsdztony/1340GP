#include "fight.h"

Fight::Fight(Pokemon *p1, Pokemon *p2)
{
    p1->x = 2;
    p1->y = 5;
    p2->x = 41;
    p2->y = 5;
    this->p1 = p1;
    this->p2 = p2;
    this->screen = Screen(fight_map[0].size(), fight_map.size());
    this->kb = Keyboard();
}

void Fight::start()
{
    this->screen.clean();
    this->main_loop();
}

void Fight::draw()
{
    this->screen.clear();
    this->screen.draw(0, 0, fight_map);

    // draw p1 and p2
    this->screen.draw(this->p1);
    this->screen.draw(this->p2);

    // draw p1's skills
    for (int i = 0; i < this->p1->skills.size(); i++)
    {
        this->screen.draw(2 + i*13, 15, this->p1->skills[i].name);
        this->screen.draw(10 + i*13, 16, to_string(this->p1->skills[i].damage));
        this->screen.draw(10 + i*13, 17, to_string(this->p1->skills[i].mp_cost));
    }

    // draw p1 and p2 name
    this->screen.draw(2, 4, this->p1->name);
    this->screen.draw(67 - this->p2->name.length() - 2, 4, this->p2->name);

    // draw types
    this->screen.draw(17, 4, this->p1->type);
    this->screen.draw(45, 4, this->p2->type);

    // draw turn
    this->screen.draw(37, 0, to_string(this->turn));

    // calculate HP and MP bar length
    int p1_hp_bar_length = this->p1->HP * 12 / this->p1->max_HP;
    int p1_mp_bar_length = this->p1->MP * 11 / this->p1->max_MP;
    int p2_hp_bar_length = this->p2->HP * 12 / this->p2->max_HP;
    int p2_mp_bar_length = this->p2->MP * 11 / this->p2->max_MP;

    // draw HP and MP bar
    this->screen.draw(6, 2, string(p1_hp_bar_length, '#'));
    this->screen.draw(6, 3, string(p1_mp_bar_length, '#'));
    this->screen.draw(67 - 5 - p2_hp_bar_length, 2, string(p2_hp_bar_length, '#'));
    this->screen.draw(67 - 5 - p2_mp_bar_length, 3, string(p2_mp_bar_length, '#'));

    // draw HP and MP value
    this->screen.draw(19, 2, to_string(this->p1->HP) + "/" + to_string(this->p1->max_HP));
    this->screen.draw(18, 3, to_string(this->p1->MP) + "/" + to_string(this->p1->max_MP));
    this->screen.draw(67 - 19 - to_string(this->p2->HP).length() - to_string(this->p2->max_HP).length(), 2, to_string(this->p2->HP) + "/" + to_string(this->p2->max_HP));
    this->screen.draw(67 - 18 - to_string(this->p2->MP).length() - to_string(this->p2->max_MP).length(), 3, to_string(this->p2->MP) + "/" + to_string(this->p2->max_MP));
}

void Fight::update()
{
    this->screen.refresh();
}

void Fight::input()
{
    this->kb.wait_for({KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN, 'c', 'w', 'b'});
}

void Fight::main_loop()
{
    while (true)
    {
        this->draw();
        this->update();
        this->input();
    }
}

