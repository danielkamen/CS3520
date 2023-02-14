/* key.cpp -------
 *
 * Filename: key.cpp
 * Description:
 * Author: Adeel Bhutta
 * Maintainer:
 * Created: Sun Sep 13 20:29:30 2022
 * Last-Updated: September 13 22:39 2022
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

/* Copyright (c) 2022 Adeel Bhutta
 *
 * All rights reserved.
 *
 * Additional copyrights may follow
 */

#include <ncurses.h>
#include <cstdlib>
#include "key.hpp"

int get_char()
{
  int ch = getch();
  if (ch == ERR)
  {
    return (NOCHAR);
  }
  switch (ch)
  {
  case KEY_LEFT:
    return LEFT;
    break;
  case KEY_RIGHT:
    return RIGHT;
    break;
  case KEY_UP:
    return UP;
    break;
  case KEY_DOWN:
    return DOWN;
    break;
  default:
    return (ch);
    break;
  }
}
