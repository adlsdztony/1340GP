#include "fight.h"

Fight::Fight(Pokemon *p1, Pokemon *p2)
{
    p1->x = 1;
    p1->y = 5;
    p2->x = 40;
    p2->y = 5;
    this->p1 = p1;
    this->p2 = p2;
    this->screen = Screen(fight_map[0].size(), fight_map.size());
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
        this->screen.draw(2 + i*13, 16, this->p1->skills[i].name);
        this->screen.draw(10 + i*13, 17, to_string(this->p1->skills[i].damage));
        this->screen.draw(10 + i*13, 18, to_string(this->p1->skills[i].mp_cost));
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
    int p1_hp_bar_length = this->p1->HP * 12 / 100;
    int p1_mp_bar_length = this->p1->MP * 11 / 80;
    int p2_hp_bar_length = this->p2->HP * 12 / 100;
    int p2_mp_bar_length = this->p2->MP * 11 / 80;

    // draw HP and MP bar
    this->screen.draw(6, 2, string(p1_hp_bar_length, '#'));
    this->screen.draw(6, 3, string(p1_mp_bar_length, '#'));
    this->screen.draw(67 - 4 - p2_hp_bar_length, 2, string(p2_hp_bar_length, '#'));
    this->screen.draw(67 - 4 - p2_mp_bar_length, 3, string(p2_mp_bar_length, '#'));

    // draw HP and MP value
    this->screen.draw(6 + p1_hp_bar_length, 2, to_string(this->p1->HP) + "/100");
    this->screen.draw(6 + p1_mp_bar_length, 3, to_string(this->p1->MP) + "/80");
}

void Fight::main_loop()
{
    while (true)
    {
        this->draw();
        this->update();
        this->input();
        this->notice_select();
    }
}