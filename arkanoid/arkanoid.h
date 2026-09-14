#ifndef ARKANOID_H_SENTRY
#define ARKANOID_H_SENTRY

#include "default_defs.h"

typedef struct ball_tag ball;
typedef struct paddle_tag paddle;
typedef struct blocks_tag block;

int arkanoid_handle_resize(rectangle *cup, point *new_p);

ball *ball_init(point *game_field);
paddle *paddle_init(point *game_field);
block **blocks_init(int row, int col, point *game_field);

void paddle_move(paddle *p, int dx, rectangle *small_field);
int ball_update(ball *b, paddle *p, block *blks[], rectangle *small_field);
point *ball_is_hit(ball *b, block *blks[]);
void block_set_broken(block *blk);
int blocks_is_exists(block *blks[]);

point blocks_get_point(block *blks[], int row, int col);
point ball_get_point(ball *b);
point paddle_get_point(paddle *p);

void ball_destroy(ball *b);
void paddle_destroy(paddle *p);
void blocks_destroy(block **blks);

#endif
