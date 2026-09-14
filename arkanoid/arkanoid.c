#include <stdio.h> /* NULL */
#include <stdlib.h> /* malloc & free */
#include "arkanoid.h"

struct  ball_tag {
    point pos, shift_pos;
};

struct paddle_tag {
    point left;
};

struct blocks_tag {
    point up_left;
    int is_dead;
};
/* typedefs in header file */

int arkanoid_handle_resize(rectangle *cup, point *new_p)
{
    return 0;
}

ball *ball_init(point *game_field)
{
    return NULL;
}

paddle *paddle_init(point *game_field)
{
    return NULL;
}

block **blocks_init(int row, int col, point *game_field)
{
    return NULL;
}


void paddle_move(paddle *p, int dx, rectangle *small_field)
{

}

int ball_update(ball *b, paddle *p, block *blks[], rectangle *small_field)
{
    return 0;
}

point *ball_is_hit(ball *b, block *blks[])
{
    return NULL;
}

void block_set_broken(block *blk)
{

}

int blocks_is_exists(block *blks[])
{
    return 0;
}


point blocks_get_point(block *blks[], int row, int col)
{
    return blks[row][col].up_left;
}

point ball_get_point(ball *b)
{
    return b->pos;
}

point paddle_get_point(paddle *p)
{
    return p->left;
}


void ball_destroy(ball *b)
{

}

void paddle_destroy(paddle *p)
{

}

void blocks_destroy(block **blks)
{

}