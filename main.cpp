#include "screen.h"
#include "keyboard.h"
#include "object.h"
#include "window.h"
#include "notice.h"
#include "game.h"
#include <unistd.h>
#include "maps.h"
#include "fight.h"

// main loop for game
// int main()
// {
//     printf("\033[?25l");

//     vector<string> map = {
//         "``````````````````````",
//         "``````````````````````",
//         "``````````````````````",
//         "``````````````````````",
//         "###````<format front=red >#####</format>`#########",
//         "####```````````````###",
//         };
    
//     vector<string> player = {
//         "<format front=red >@</format>",
//         // "@",
//     };

//     vector<string> npc = {
//         "<format front=green >@@</format>",
//         "<format front=green >@@</format>",
//         // "@",
//     };

//     Object n(4, 2, npc);

//     // init_maps();

//     Map chuntian_path_map;
//     init_chuntian_path(chuntian_path_map);
//     Game game(chuntian_path_map);


    

//     game.objects.push_back(&n);
    
    

//     game.map.add_interact_object(n, 'n');

//     game.player = Player(1, 1, player);

//     // cout << game.player.height << endl;
//     // cout << game.player.s[0].length() << endl;

//     game.main_loop();
//     // game.main_loop();

//     // Screen screen(69, 20);

    
//     // screen.draw(&chuntian_path_map);

//     // screen.clean();

//     // screen.refresh();

//     // cout << chuntian_path_map.formats[0].x << endl;
//     // cout << chuntian_path_map.formats[0].y << endl;
//     // cout << chuntian_path_map.formats[0].length << endl;
//     // cout << chuntian_path_map.formats[0].format << endl;




//     printf("\033[?25h");
// }

int main(){
    Skill s1("Tackle", 40, 0);
    Skill s2("Growl", 0, 0);
    Skill s3("Tail Whip", 0, 0);
    Skill s4("Quick Atk", 40, 0);

    vector<string> npc = {
            "<format front=green >@@</format>",
            "<format front=green >@@</format>",
            // "@",
        };

    Pokemon p1(npc, "Pikachu", 'E', 100, 80, 55, 40, {s1, s2, s3, s4});
    Pokemon p2(npc, "Bulbasaur", 'G', 100, 80, 49, 49, {s1, s2, s3, s4});

    Fight f(&p1, &p2);
    cout << "Fight start" << endl;
    f.start();
}