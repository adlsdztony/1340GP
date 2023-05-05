#include "fight.h"
#include "game.h"
#include "keyboard.h"
#include "maps.h"
#include "notice.h"
#include "object.h"
#include "screen.h"
#include "window.h"
#include <unistd.h>


// main loop for game
int main() {
    printf("\033[?25l");

    Game game = Game();
    game.main_loop();
    printf("\033[?25h");
}
