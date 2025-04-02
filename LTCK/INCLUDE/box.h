#ifndef _BOX_H_
#define _BOX_H_
#include "allfunc.h"

/*----- 箱子结构体 -----*/
typedef struct
{
    int x, y;                // 箱子的当前位置
    int width, height;       // 箱子的宽度和高度
    unsigned int *bg_buffer; // 背景缓存
} BOX;

/*----- 函数原型 -----*/
void InitBox(BOX *box, int x, int y, int width, int height); // 初始化箱子
void DrawBox(BOX *box, unsigned int color);                  // 绘制箱子
void MoveBox(BOX *box, int target_x, int target_y);          // 移动箱子
void HideBox(BOX *box);                                      // 隐藏箱子
void FreeBox(BOX *box);                                      // 释放资源

#endif