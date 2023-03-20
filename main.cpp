#include "display.h"
#include "keyboard.h"
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
        "<format front=red >Hello</format>", 
        "World!"
        };

    Object obj(2, 2, s);   

    

    // main loop
    while (true)
    {
        // clear display
        screen.clear();

        screen.draw(obj);

        // update display
        screen.refresh();
        sleep(1);
    }
}