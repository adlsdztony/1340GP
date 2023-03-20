#include "display.h"
#include "keyboard.h"
#include <unistd.h>

// main loop for game
int main()
{
    // create display
    Screen display(80, 10);
    // create keyboard
    Keyboard keyboard;
    // listen for keyboard input
    keyboard.listen();
    // main loop
    while (true)
    {
        // clear display
        display.clear();

        // update display
        display.refresh();
        sleep(1);
    }
}