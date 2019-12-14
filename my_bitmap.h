#ifndef _MY_BITMAP__H
#define _MY_BITMAP__H

#include <stdint.h>
/* 位图结构 */
#define BITMAP_MAX_LENGTH       (128)

typedef struct _my_bitmap_t
{
    uint32_t bitmap_group[BITMAP_MAX_LENGTH/32];
}my_bitmap_t;

int8_t get_bitmap_onebit(struct _my_bitmap_t *h_bitmap, uint8_t index);
int8_t get_bitmap_first_zero(struct _my_bitmap_t *h_bitmap);
int8_t get_bitmap_first_set(struct _my_bitmap_t *h_bitmap);
int8_t set_bitmap_onebit(struct _my_bitmap_t *h_bitmap, uint8_t index);
int8_t clear_bitmap_onebit(struct _my_bitmap_t *h_bitmap,uint8_t index);
int8_t init_bitmap(struct _my_bitmap_t *h_bitmap, uint8_t init_state);






#endif







