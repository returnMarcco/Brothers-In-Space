#ifndef POWER_UP_H
#define POWER_UP_H

#include "splashkit.h"
#include <vector>

using namespace std;

/**
 * Enumeration for the power up to be chosen
 */
enum power_up_kind
{
    FUEL,
    HEART,
    COIN,
    BROTHERHOOD,
    POTION,
    STAR
    
};

/** Struct for instantiating objects of the 'power_up_data' type
 */
struct power_up_data
{
    string power_up_type;
    sprite power_up_sprite;
    string power_up_;
    power_up_kind kind;
    
    
};

/** Various functions for loading, positioning and drawing 'powerups' to the screen
 */
bitmap power_up_bitmap(power_up_kind kind);

power_up_data new_power_up(double x, double y);

void draw_powerup(const power_up_data &power_up_to_draw);

void update_power_up(power_up_data &power_up_to_update);


#endif