#include "tui.h"
#include <curses.h>

void draw_pixel(point *up_left, int length, int height, int chr)
{
    int x = up_left->x;
    for ( ; x - up_left->x < length; x++) {
        int y = up_left->y;
        for ( ; y - up_left->y < height; y++)
            mvaddch(y, x, chr);        
    }
    refresh();
}