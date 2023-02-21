

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
