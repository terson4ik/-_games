#include <stdio.h> /* NULL */
#include <stdlib.h> /* malloc & free */
#include <time.h> /* use in init ball */
#include "arkanoid.h"

#define FALL    +1
#define RISE    -1
#define LEFT    -1
#define RIGHT   +1

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
    ball *nball = malloc(sizeof(*nball));
    if (!nball)
        return NULL;

    nball->pos.x = game_field->x / 2;
    nball->pos.y = game_field->y / 2;

    nball->shift_pos.x = (time(NULL) % 2) == 0 ? LEFT : RIGHT;
    nball->shift_pos.y = FALL;
    return nball;
}

paddle *paddle_init(point *game_field)
{
    paddle *npaddle = malloc(sizeof(*npaddle));
    if (!npaddle)
        return NULL;
    
    npaddle->left.x = game_field->x / 2;
    npaddle->left.y = game_field->y / 2;
    return npaddle;
}

block *blocks_init(point *game_field)
{
    int col, row, cx, cy;
    block *nblks = malloc(sizeof(*nblks) * BLOCK_COLS * BLOCK_ROWS);
    if (!nblks)
        return NULL;


    return nblks;
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
    free(b);
}

void paddle_destroy(paddle *p)
{
    free(p);
}

void blocks_destroy(block **blks)
{
    free(blks);
}