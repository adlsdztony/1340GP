#include "notice.h"



Notice::Notice(int x, int y, int w, int h, string title, vector<string> selections, int space) : Window(x, y, w, h, title, selections, space){
        this->content = selections;
        this->selections = selections;
        int title_start = (w - title.length()) / 2;
        this->formats.push_back(Format(title_start, 1, title.length(), BOLD));
        this->space = space;
};


int Notice::select(Keyboard *kb, Screen *screen)
{   
    // create format for selections
    formats.push_back(Format(1, 2+space, selections[0].length(), BACK_BLUE));

    assert(formats.size() >= 2);

    int i = 0;
    while (true)
    {
        this->formats[1].y = i+2+space;
        this->formats[1].length = selections[i].length();
        screen->clear();
        screen->draw(this);
        screen->refresh();
        vector<int> keys = {KEY_UP, KEY_DOWN, KEY_ENTER, 'w', 'W', 's', 'S', KEY_ESC};
        int k = kb->wait_for(keys);
        if (k == KEY_UP || k == 'w' || k == 'W')
        {
            i--;
            if (i < 0)
            {
                i = this->selections.size() - 1;
            }
        }
        if (k == KEY_DOWN || k == 's' || k == 'S')
        {
            i++;
            if (i > this->selections.size() - 1)
            {
                i = 0;
            }
        }
        if (k == KEY_ENTER)
        {
            return i;
        }
        if (k == KEY_ESC)
        {
            return -1;
        }
    }
}