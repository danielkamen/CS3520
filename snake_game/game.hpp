/*game.hpp -------
*
* Filename: game.hpp
* Description:
* Author: Adeel Bhutta
* Maintainer:
* Created: Sat Sep 12 13:16:12 2022
* Last-Updated: September 12 16:51 2022
*
*/

/* Commentary:
*
*
*
*/

/* Change log:
*
*
*/

/*Copyright (c) 2022 Adeel Bhutta
*
* All rights reserved.
*
* Additional copyrights may follow
*/
void game();
void generate_points(int *food_x, int *food_y, int width, int height, int x_offset, int y_offset);
enum State{INIT, ALIVE, DEAD, EXIT};
