#include "screen.h"
#include "keyboard.h"
#include "object.h"
#include "window.h"
#include "notice.h"
#include "game.h"
#include <unistd.h>
#include "maps.h"

// main loop for game
int main()
{
    printf("\033[?25l");

    vector<string> map = {
        "``````````````````````",
        "``````````````````````",
        "``````````````````````",
        "``````````````````````",
        "###````<format front=red >#####</format>`#########",
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

    Game game(chuntian_path);


    

    game.objects.push_back(&n);
    
    

    game.map.add_interact_object(n, 'n');

    game.player = Player(1, 1, player);

    // cout << game.player.height << endl;
    // cout << game.player.s[0].length() << endl;

    // game.main_loop();
    game.main_loop();

    // Screen screen(69, 20);

    
    // screen.draw(&chuntian_path_map);

    // screen.clean();

    // screen.refresh();

    // cout << chuntian_path_map.formats[0].x << endl;
    // cout << chuntian_path_map.formats[0].y << endl;
    // cout << chuntian_path_map.formats[0].length << endl;
    // cout << chuntian_path_map.formats[0].format << endl;




    printf("\033[?25h");
}