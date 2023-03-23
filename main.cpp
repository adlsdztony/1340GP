#include "screen.h"
#include "keyboard.h"
#include "object.h"
#include "window.h"
#include "notice.h"
#include <unistd.h>

// main loop for game
int main()
{
    printf("\033[?25l");
    // create display
    Screen screen(40, 10);
    // create keyboard
    Keyboard keyboard;
    // listen for keyboard input
    keyboard.listen();

    vector<string> s = {
        "Hello",
        "World!",
        };

    Object obj(1, 1, s);
    // screen.draw(&obj);
    // screen.refresh();
    // cin.get();
    Notice win(2, 2, 20, 5, "Title", s);
    // screen.draw(&win);
    // screen.refresh();

    // main loop
    screen.clean();
    int i = win.select(&keyboard, &screen);
    cout << s[i] << endl;
    keyboard.stop();
    printf("\033[?25h");
}