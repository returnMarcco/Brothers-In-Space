#include "splashkit.h"
#include "terminal_user_input.h"
#include "power_up.h"
using namespace std;

/** Function to return a specific image pertinant to the type of "powerup" obtained by the player.
 * @param Choice from the "power_up_kind" enum.
 */

bitmap power_up_bitmap(power_up_kind kind)
{
        
        
        
        
        switch (kind)
        {
            
            case FUEL:
                    
                    return bitmap_named("fuel");
                    
            
            case HEART:
                 
                    return bitmap_named("heart");
            
            case COIN:
                  
                    return bitmap_named("coin");

            case BROTHERHOOD:
             
                return bitmap_named("brotherhood_ffx_no_bg.png");
            
            case POTION:
                  
                    return bitmap_named("potion");
            
            case STAR:
                  
                    return bitmap_named("star");
        }
        return 0;
}




/** Function to initialize a new "powerup".
 * @param Horizontal and vertical position for the powerup.
 */
 

power_up_data new_power_up(double x, double y)
{   
    power_up_data result;
    bitmap default_bitmap = power_up_bitmap(BROTHERHOOD);
    
    static_cast<power_up_kind>(rnd(6));
    
    result.power_up_sprite = create_sprite(default_bitmap);
    
    sprite_set_x(result.power_up_sprite, x);
    sprite_set_y(result.power_up_sprite, y);
    sprite_set_dx(result.power_up_sprite, rnd() * 4 - 2);
    
    return result;
}



/** Procedure to draw the powerup sprite to the display.
 * @param Accepts a "power_up_data" type value as it's argument for the "powerup" to be drawn to the display.
 */

void draw_powerup(const power_up_data &power_up_to_draw)
{
    draw_sprite(power_up_to_draw.power_up_sprite);
    
}



/** Procedure to "move" the "powerup" sprite on the display
 * @param Accepts a "power_up_data" type value as it's argument as the sprite to move on the display.
 */

void update_power_up(power_up_data &power_up_to_update)
{
    update_sprite(power_up_to_update.power_up_sprite);
}



