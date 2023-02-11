#ifndef LOST_IN_SPACE_MAIN
#define LOST_IN_SPACE_MAIN


#include "splashkit.h"
#include "player.h"
#include "power_up.h"
#include <vector>


struct game_data
{
    player_data player;
    vector<power_up_data> power_ups;
};

// void load_resources();

game_data new_game();

void load_resources();

void custom_hud(player_data player_location);

void full_fuel(player_data player_location);

void add_power_up(game_data &game);

void update_game(game_data &game);

void draw_game(game_data &game);

void apply_power_up(game_data &game);

void remove_power_up(game_data &game, int index);

void check_collisions(game_data &game);












#endif