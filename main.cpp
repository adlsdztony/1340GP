#include "display.h"
#include "keyboard.h"
#include "object.h"
#include "window.h"
#include <unistd.h>

// main loop for game
int main()
{
    // create display
    Screen screen(80, 10);
    // create keyboard
    Keyboard keyboard;
    // listen for keyboard input
    keyboard.listen();

    vector<string> s = {
        "<format back=blue >Hello</format>",
        "World!"};

    Object obj(2, 2, s);

    Window win(2, 2, 20, 5, "<format mod=bold >Title</format>", s);

    // main loop
    while (true)
    {
        // clear display
        screen.clear();

        screen.draw(win);

        // update display
        screen.refresh();
        int keys[] = {KEY_UP, KEY_DOWN, KEY_ENTER};
        int k = keyboard.wait_for(keys);

        if (k == 'w' | k == 'W' | k == KEY_UP)
        {
            win.formats[1].y--;
        }
        if (k == 's' | k == 'S' | k == KEY_DOWN)
        {
            win.formats[1].y++;
        }
        if (k == KEY_ENTER || k == 10 || k == 13)
        {
            break;
        }
        
    }
}