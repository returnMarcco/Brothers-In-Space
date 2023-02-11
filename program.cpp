#include "splashkit.h"
#include "lost_in_space.h"
#include "player.h"
#include "power_up.h"
#include <string>
using namespace std;



int main()
{
    
    open_window("Lost In Space", 1024, 768);
    load_resources();
    game_data test_game;
    test_game = new_game();
    load_music("zanarkand", "zan.ogg");
    load_music("ffx_victory", "ffx_victory_fanfare.ogg");
    load_sound_effect("power_up_beep", "beep.ogg");
    play_music("zanarkand", 99);
    
   

    
    
    
    
   
    update_game(test_game);
    draw_game(test_game);
     
    
    
    
   

    return 0;
}