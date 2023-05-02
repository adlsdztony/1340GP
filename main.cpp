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
int main()
{
    printf("\033[?25l");

    Game game = Game();
    game.main_loop();
    printf("\033[?25h");
}

// int main(){
//     Skill s1("Thunder", 4.5, 3.5, 10, 10, 30, 0, 0, 0);
//     Skill s2("Thunder", 4.5, 3.5, 10, 10, 30, 0, 0, 0);
//     Skill s3("Thunder", 4.5, 3.5, 10, 10, 30, 0, 0, 0);
//     Skill s4("Thunder", 4.5, 3.5, 10, 10, 30, 0, 0, 0);


//     vector<string> npc = {
//             "<format front=green >@@</format>",
//             "<format front=green >@@</format>",
//             // "@",
//         };
    
//     vector<string> pkm(9, "<format front=cyan >@@@@@@@@@@@@@@@@@@@@@@@@</format>");

//     Pokemon p1(pkm, "Pikachu", 'E', 100, 80, 55, 40, {s1, s2, s3, s4});
//     Pokemon p2(pkm, "Bulbasaur", 'G', 100, 80, 49, 49, {s1, s2, s3, s4});

//     p1.HP = 50;
//     p2.HP = 30;
//     p1.MP = 30;
//     p2.MP = 30;

//     map<string, Pokemon> pokemon_element;
//     get_pokemon_element(pokemon_element);
//     p1 = pokemon_element.at("Charmeleon");
//     p2 = pokemon_element.at("Charmeleon");

//     Keyboard k;

//     k.listen();

//     Screen screen(69, 20);

//     Fight f(&p1, &p2, &k, &screen);
//     cout << "Fight start" << endl;
//     f.start();
//     k.stop();
//     // cin.get();
// }