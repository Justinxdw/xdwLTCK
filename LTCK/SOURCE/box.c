#include "allfunc.h"
#include <stdlib.h>

/*----- 初始化箱子 -----*/
void InitBox(BOX *box, int x, int y, int width, int height)
{
    int i, j; // 循环变量

    box->x = x;
    box->y = y;
    box->width = width;
    box->height = height;
    box->bg_buffer = (unsigned int *)malloc(width * height * sizeof(unsigned int));
    if (!box->bg_buffer)
        return;

    // 保存初始位置的背景
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            box->bg_buffer[i * width + j] = Getpixel64k(x + j, y + i);
        }
    }
}

/*----- 绘制箱子 -----*/
void DrawBox(BOX *box, unsigned int color)
{
    int i, j; // 循环变量

    for (i = 0; i < box->height; i++)
    {
        for (j = 0; j < box->width; j++)
        {
            Putpixel64k(box->x + j, box->y + i, color);
        }
    }
}

/*----- 移动箱子 -----*/
// (顺滑移动，但是会频闪)
// void MoveBox(BOX* box, int target_x, int target_y, int speed)
// {
//     int dx, dy, steps, i;
//     float inc_x, inc_y;
//     int new_x, new_y;

//     // 计算移动步数和增量
//     dx = target_x - box->x;
//     dy = target_y - box->y;
//     steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);  // 取较大值作为步数
//     inc_x = (float)dx / steps;
//     inc_y = (float)dy / steps;

//     // 逐步移动箱子
//     for (i = 0; i < steps; i++) {
//         int i, j;  // 循环变量
//         // 隐藏箱子（恢复背景）
//         HideBox(box);

//         // 计算新位置
//         new_x = box->x + (int)(inc_x * speed);
//         new_y = box->y + (int)(inc_y * speed);

//         // 保存新位置的背景
//         for (i = 0; i < box->height; i++) {
//             for ( j = 0; j < box->width; j++) {
//                 box->bg_buffer[i * box->width + j] = Getpixel64k(new_x + j, new_y + i);
//             }
//         }

//         // 更新箱子位置
//         box->x = new_x;
//         box->y = new_y;

//         // 在新位置绘制箱子
//         DrawBox(box, 0xFF0000);  // 红色箱子

//         // 控制移动速度
//         delay(100);  // 暂停10ms
//     }
// }

void MoveBox(BOX *box, int target_x, int target_y)
{
    int dx, dy, steps, i;
    float inc_x, inc_y;
    int new_x, new_y;

    // 逐步移动箱子
    for (; !(box->x == target_x && box->y == target_y);)
    {
        int i, j; // 循环变量
        // 隐藏箱子（恢复背景）
        HideBox(box);

        // 计算新位置
        if (abs(box->x - target_x) <= 20) // 如果距离小于20，则直接到达目标位置
        {
            new_x = target_x;
        }
        else if (box->x + 20 < target_x) // 向右移动
        {
            new_x = box->x + 20;
        }
        else if (box->x - 20 > target_x) // 向左移动
        {
            new_x = box->x - 20;
        }
        
        if(abs(box->y - target_y) <= 20) // 如果距离小于20，则直接到达目标位置
        {
            new_y = target_y;
        }
        else if (box->y + 20 < target_y) // 向下移动
        {
            new_y = box->y + 20;
        }
        else if (box->y - 20 > target_y) // 向上移动
        {
            new_y = box->y - 20;
        }

        // 保存新位置的背景
        for (i = 0; i < box->height; i++)
        {
            for (j = 0; j < box->width; j++)
            {
                box->bg_buffer[i * box->width + j] = Getpixel64k(new_x + j, new_y + i);
            }
        }

        // 更新箱子位置
        box->x = new_x;
        box->y = new_y;

        // 在新位置绘制箱子
        DrawBox(box, 0xFF0000); // 红色箱子

        // 控制移动速度
        delay(500); // 暂停10ms
    }
}

/*----- 隐藏箱子（恢复背景） -----*/
void HideBox(BOX *box)
{
    int i, j; // 循环变量

    for (i = 0; i < box->height; i++)
    {
        for (j = 0; j < box->width; j++)
        {
            Putpixel64k(box->x + j, box->y + i, box->bg_buffer[i * box->width + j]);
        }
    }
}

/*----- 释放资源 -----*/
void FreeBox(BOX *box)
{
    if (box->bg_buffer)
    {
        free(box->bg_buffer);
        box->bg_buffer = NULL;
    }
}

BOX box;  // 箱子结构体实例