#include "my_bitmap.h"

/*****************************************************
* 函数功能 : 获取当前位图中某一位的状态
* 函数名称 : get_bitmap_onebit
* 输入参数 : h_bitmap 需要操作的位图结构 index 索引值
* 返回值  :  成功返回状态值 失败返回-1
* 备注 : 
******************************************************/
int8_t get_bitmap_onebit(struct _my_bitmap_t *h_bitmap, uint8_t index)
{
    if (index > BITMAP_MAX_LENGTH)
    {
        return -1;
    }
    uint32_t and_temp = h_bitmap->bitmap_group[index / 32];
    and_temp >>= ((index % 32));
    and_temp &= 0x00000001;
    return (int8_t)and_temp;
}

/*****************************************************
* 函数功能 : 获取当前位图中第一个为0的索引值
* 函数名称 : get_bitmap_first_zero
* 输入参数 : h_bitmap 需要操作的位图结构
* 返回值  :  成功返回索引值 失败返回-1
* 备注 : 
******************************************************/
int8_t get_bitmap_first_zero(struct _my_bitmap_t *h_bitmap)
{
    int8_t i = -1;
    for (i = 0; i < BITMAP_MAX_LENGTH; i++)
    {
        if (get_bitmap_onebit(h_bitmap, i) == 0)
        {
            break;
        }
    }
    if (i == BITMAP_MAX_LENGTH)
    {
        i = -1;
    }
    return i;
}

/*****************************************************
* 函数功能 : 获取当前位图中第一个为1的索引值
* 函数名称 : get_bitmap_first_set
* 输入参数 : h_bitmap 需要操作的位图结构
* 返回值  :  成功返回索引值 失败返回-1
* 备注 : 
******************************************************/
int8_t get_bitmap_first_set(struct _my_bitmap_t *h_bitmap)
{
    int8_t i = -1;
    for (i = 0; i < BITMAP_MAX_LENGTH; i++)
    {
        if (get_bitmap_onebit(h_bitmap, i) == 1)
        {
            break;
        }
    }
    if (i == BITMAP_MAX_LENGTH)
    {
        i = -1;
    }
    return i;
}

/*****************************************************
* 函数功能 : 设置位图的某个位为1
* 函数名称 : set_bitmap_onebit
* 输入参数 : h_bitmap 需要操作的位图结构 index 索引值
* 返回值  :  成功返回0 失败返回-1
* 备注 : 
******************************************************/
int8_t set_bitmap_onebit(struct _my_bitmap_t *h_bitmap, uint8_t index)
{
    if (index > BITMAP_MAX_LENGTH)
    {
        return -1;
    }
    h_bitmap->bitmap_group[index / 32] |= (1 << (index % 32));
    return 0;
}

/*****************************************************
* 函数功能 : 设置位图的某个位为0
* 函数名称 : clear_bitmap_onebit
* 输入参数 : h_bitmap 需要操作的位图结构 index 索引值
* 返回值  :  成功返回0 失败返回-1
* 备注 : 
******************************************************/
int8_t clear_bitmap_onebit(struct _my_bitmap_t *h_bitmap, uint8_t index)
{
    if (index > BITMAP_MAX_LENGTH)
    {
        return -1;
    }
    h_bitmap->bitmap_group[index / 32] &= (~(1 << (index % 32)));
    return 0;
}

/*****************************************************
* 函数功能 : 初始化位图结构
* 函数名称 : init_bitmap
* 输入参数 : h_bitmap 需要操作的位图结构
* 返回值  :  固定返回0
* 备注 :  
******************************************************/
int8_t init_bitmap(struct _my_bitmap_t *h_bitmap, uint8_t init_state)
{
    for (int i = 0; i < BITMAP_MAX_LENGTH / 32; i++)
    {
        if (init_state != 0)
        {
            h_bitmap->bitmap_group[i] = 0xffffffff;
        }
        else
        {
            h_bitmap->bitmap_group[i] = 0x00000000;
        }
    }
    return 0;
}

/*****************************************************
* 函数功能 : 判断这两个位图数据是否一致
* 函数名称 : check_bitmap_is_equal
* 输入参数 : h_bitmap0/h_bitmap1 两个需要对比的位图结构
* 返回值   :   如果相等则返回0 不等则返回-1
* 备注 :  
******************************************************/
int8_t check_bitmap_is_equal(struct _my_bitmap_t *h_bitmap0, struct _my_bitmap_t *h_bitmap1)
{
    int16_t i = -1;
    for (i = 0; i < BITMAP_MAX_LENGTH; i++)
    {
        if (get_bitmap_onebit(h_bitmap0, i) != get_bitmap_onebit(h_bitmap1, i))
        {
            break;
        }
    }
    if (i == BITMAP_MAX_LENGTH)
    {
        return -1;
    }
	else
	{
		return 0;
	}
}








