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
        "``````````````````````",
        "``````````````````````",
        "###````#####`#########",
        "####```````````````###",
        };
    
    vector<string> player = {
        "<format front=red >@</format>",
        // "@",
    };

    vector<string> npc = {
        "<format front=green >@@</format>",
        "<format front=green >@@</format>",
        // "@",
    };

    Object n(4, 2, npc);

    Game game(map);
    

    game.objects.push_back(&n);
    
    

    game.map.add_interact_object(n, 'n');

    game.player = Player(0, 0, player);

    // cout << game.player.height << endl;
    // cout << game.player.s[0].length() << endl;

    game.main_loop();
    // game.main_loop();



    printf("\033[?25h");
}