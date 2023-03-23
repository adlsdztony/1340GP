#include "screen.h"
#include "keyboard.h"
#include "object.h"
#include "window.h"
#include "notice.h"
#include "game.h"
#include <unistd.h>

// main loop for game
int main()
{
    printf("\033[?25l");

    vector<string> map = {
        "``````````````````````",
        "``````````````````````",
        "###````#####`#########",
        "####```````````````###",
        };
    
    vector<string> player = {
        "@",
        "@",
    };

    Game game(map);

    game.player = Player(0, 0, player);

    // print game.valid_map

    game.main_loop();
    // game.main_loop();



    printf("\033[?25h");
}