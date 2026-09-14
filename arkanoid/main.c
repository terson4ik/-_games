#include <curses.h>
#include "default_defs.h"
#include "arkanoid.h"
#include "tui.h"

int main(void)
{
    point game_field_edge, tmp_p;
    rectangle cup;
    block **blks;
    paddle *p;
    ball *b;
    int key;

    initscr();
    cbreak();
    curs_set(0);
    keypad(stdscr, 1);
    timeout(DELAY_NORM);

    getmaxyx(stdscr, game_field_edge.y, game_field_edge.x);
    b = ball_init(&game_field_edge);
    tmp_p = ball_get_point(b);
    draw_pixel(&tmp_p, 2, 2, CHR_BALL);

    p = paddle_init(&game_field_edge);
    tmp_p = paddle_get_point(p);
    draw_pixel(&tmp_p, PADDLE_LEN, 1, CHR_PADDLE);
    blks = blocks_init(&game_field_edge);

    while ((key = getch()) != KEY_ESCAPE && key != 'q' && key != 'Q') {
        switch (key) {
        case KEY_LEFT:  paddle_move(p, -1, &cup); break;
        case KEY_RIGHT: paddle_move(p, +1, &cup); break;
        case KEY_RESIZE:
            getmaxyx(stdscr, game_field_edge.y, game_field_edge.x);
            if (arkanoid_handle_resize(&cup, &game_field_edge)) {
                endwin();
                return 1;
            }
        }
        if (ball_update(b, p, blks, &cup)) {
            break;
        }
        if (ball_is_hit(b, blks)) {
            /* draw empty*/
            if (!blocks_is_exists(blks)) {
                break;
            }
        }
    }

    ball_destroy(b);
    paddle_destroy(p);
    blocks_destroy(blks);
    endwin();
    return 0;
}