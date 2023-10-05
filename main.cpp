#include "fight.h"
#include "game.h"
#include "keyboard.h"
#include "maps.h"
#include "notice.h"
#include "object.h"
#include "screen.h"
#include "window.h"
#include <unistd.h>
#include <signal.h>


Game game;


void sigwinch_handler(int sig) {
    game.screen.rearrange();
}

// main loop for game
int main() {
    printf("\033[?25l");
    game.init();
    signal(SIGWINCH, sigwinch_handler);
    game.main_loop();
    printf("\033[?25h");
}
