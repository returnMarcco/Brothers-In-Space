#include "splashkit.h"
#include <vector>
#include "player.h"
#include "power_up.h"
#include "lost_in_space.h"
using std::vector;


void load_resources()
{
    load_resource_bundle("game_bundle", "lost_in_space.txt");
}

void custom_hud(player_data player_location)
{
    load_bitmap("hud_border", "rectangle_border_blue_450px_250px.png");
    load_bitmap("corey", "corey_thumbs_no_bg.png");
    load_bitmap("nicky", "nicky_boy_no_bg.png");
    load_bitmap("mini_map", "mini_map.png");
    load_bitmap("fuel_can", "fuel.png");
    load_bitmap("empty_fuel_bar", "empty.png");
    load_bitmap("full_fuel_bar", "full.png");
    load_bitmap("nonna", "nonna.png");
    draw_bitmap("hud_border", 270, 500, option_to_screen());
    draw_bitmap("mini_map", 800, 50, option_to_screen());
    draw_bitmap("fuel_can", 600, 650, option_to_screen());
    draw_bitmap("empty_fuel_bar", 480, 720, option_to_screen());
    draw_bitmap("full_fuel_bar", 480, 720, option_part_bmp(0, 0, 75, bitmap_height("full"), option_to_screen()));
    draw_bitmap("corey", 770, 230, option_to_screen());
    draw_bitmap("nicky", 1, 570, option_to_screen());
    draw_bitmap("nonna", 120, 500, option_to_screen());
    
    
    draw_text("SCORE: " + to_string(player_location.score), COLOR_BEIGE, 350, 620, option_to_screen());
    draw_text("LOCATION: " + point_to_string(center_point(player_location.player_sprite)), COLOR_YELLOW, 350, 600 , option_to_screen());
    draw_text("COLLECT ALL TO COMPLETE: BROTHERHOOD SWORD", COLOR_TEAL, 350, 640, option_to_screen());
    draw_text("POWER UPS COLLECTED: " + to_string(player_location.power_ups_collected) + "/20", COLOR_BEIGE, 350, 660, option_to_screen());
    draw_text("CREW MORALE: " + to_string(player_location.crew_morale) + "%", COLOR_GREEN, 350, 680, option_to_screen());
    draw_text("FATIGUE LEVEL: " + player_location.fatigue_level, COLOR_ORANGE, 350, 700, option_to_screen());
    
    
}



game_data new_game()
{
    game_data game;
    game.player = new_player();
    return game;
}

void add_power_up(game_data &game)
{
    
    game.power_ups.push_back(new_power_up(rnd(0, 1200), rnd(0, 1200)));
    
}

void apply_power_up(game_data &game)
{
    
    play_sound_effect("power_up_beep");
    write_line("YOU HAVE COLLIDED WITH A POWERUP");
    
}

void remove_power_up(game_data &game, int index)
{
   game.power_ups.erase(game.power_ups.begin() + index);
   if (game.power_ups.size() == 0)
    {
        play_music("ffx_victory", 1);
    }


}

void check_collisions(game_data &game)
{
    for (int i = game.power_ups.size() - 1; i >= 0; i--)
    {
        if (sprite_collision(game.player.player_sprite, game.power_ups[i].power_up_sprite))
        {
            apply_power_up(game);
            game.player.score += 10;
            game.player.power_ups_collected += 1;
            game.player.crew_morale += 5;

            remove_power_up(game, i);
        }
    }
    // }
    // if (sprite_collision(game.player.player_sprite, game.power_ups[0].power_up_sprite))
    // {
    //     apply_power_up(game.power_ups[0]);
    // }
    // if (sprite_collision(game.player.player_sprite, game.power_ups[1].power_up_sprite))
    // {
    //     apply_power_up(game.power_ups[1]);
    // }
    // if (sprite_collision(game.player.player_sprite, game.power_ups[2].power_up_sprite))
    // {
    //     apply_power_up(game.power_ups[2]);
    // }
    // if (sprite_collision(game.player.player_sprite, game.power_ups[3].power_up_sprite))
    // {
    //     apply_power_up(game.power_ups[3]);
    // }
    // if (sprite_collision(game.player.player_sprite, game.power_ups[4].power_up_sprite))
    // {
    //     apply_power_up(game.power_ups[4]);
    // }
}
    
void update_game(game_data &game)
{
    // Perform movement and update the camera
    update_player(game.player);
    
    write_line("VECTOR SIZE IS: " + to_string(game.power_ups.size()));
   
    check_collisions(game);
    

    
    for (int i = 0; i < game.power_ups.size(); i++)
        {
            // Operating on Vector as a queue Abstract Data Type (FIFO)
            update_power_up(game.power_ups[i]);
        }

}

void draw_game(game_data &game)
{
   
    add_power_up(game);
    add_power_up(game);
    add_power_up(game);
    // add_power_up(game);
    // add_power_up(game);
    // add_power_up(game);
    // add_power_up(game);
    // add_power_up(game);
    // add_power_up(game);
    // add_power_up(game);
    // add_power_up(game);
    // add_power_up(game);
    // add_power_up(game);
    // add_power_up(game);
    // add_power_up(game);
    // add_power_up(game);
    // add_power_up(game);
    // add_power_up(game);
    // add_power_up(game);
    // add_power_up(game);
    
   
    while ( not quit_requested() )
    {
        // Handle input to adjust player movement
        process_events();
        handle_input(game.player);
        
        // // Perform movement and update the camera
        update_game(game);
        // update_player(game.player);
        
        // Redraw everything
        clear_screen(COLOR_BLACK);

        // as well as the player who can move
        custom_hud(game.player);
        draw_player(game.player);
        
        for (int i = 0; i < game.power_ups.size(); i++)
        {
            draw_powerup(game.power_ups[i]);
        }

       
        
        refresh_screen(60);
    }

    
}

