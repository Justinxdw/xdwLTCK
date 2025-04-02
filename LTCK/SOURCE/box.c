#include "allfunc.h"
#include <stdlib.h>

/*----- ��ʼ������ -----*/
void InitBox(BOX *box, int x, int y, int width, int height)
{
    int i, j; // ѭ������

    box->x = x;
    box->y = y;
    box->width = width;
    box->height = height;
    box->bg_buffer = (unsigned int *)malloc(width * height * sizeof(unsigned int));
    if (!box->bg_buffer)
        return;

    // �����ʼλ�õı���
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            box->bg_buffer[i * width + j] = Getpixel64k(x + j, y + i);
        }
    }
}

/*----- �������� -----*/
void DrawBox(BOX *box, unsigned int color)
{
    int i, j; // ѭ������

    for (i = 0; i < box->height; i++)
    {
        for (j = 0; j < box->width; j++)
        {
            Putpixel64k(box->x + j, box->y + i, color);
        }
    }
}

/*----- �ƶ����� -----*/
// (˳���ƶ������ǻ�Ƶ��)
// void MoveBox(BOX* box, int target_x, int target_y, int speed)
// {
//     int dx, dy, steps, i;
//     float inc_x, inc_y;
//     int new_x, new_y;

//     // �����ƶ�����������
//     dx = target_x - box->x;
//     dy = target_y - box->y;
//     steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);  // ȡ�ϴ�ֵ��Ϊ����
//     inc_x = (float)dx / steps;
//     inc_y = (float)dy / steps;

//     // ���ƶ�����
//     for (i = 0; i < steps; i++) {
//         int i, j;  // ѭ������
//         // �������ӣ��ָ�������
//         HideBox(box);

//         // ������λ��
//         new_x = box->x + (int)(inc_x * speed);
//         new_y = box->y + (int)(inc_y * speed);

//         // ������λ�õı���
//         for (i = 0; i < box->height; i++) {
//             for ( j = 0; j < box->width; j++) {
//                 box->bg_buffer[i * box->width + j] = Getpixel64k(new_x + j, new_y + i);
//             }
//         }

//         // ��������λ��
//         box->x = new_x;
//         box->y = new_y;

//         // ����λ�û�������
//         DrawBox(box, 0xFF0000);  // ��ɫ����

//         // �����ƶ��ٶ�
//         delay(100);  // ��ͣ10ms
//     }
// }

void MoveBox(BOX *box, int target_x, int target_y)
{
    int dx, dy, steps, i;
    float inc_x, inc_y;
    int new_x, new_y;

    // ���ƶ�����
    for (; !(box->x == target_x && box->y == target_y);)
    {
        int i, j; // ѭ������
        // �������ӣ��ָ�������
        HideBox(box);

        // ������λ��
        if (abs(box->x - target_x) <= 20) // �������С��20����ֱ�ӵ���Ŀ��λ��
        {
            new_x = target_x;
        }
        else if (box->x + 20 < target_x) // �����ƶ�
        {
            new_x = box->x + 20;
        }
        else if (box->x - 20 > target_x) // �����ƶ�
        {
            new_x = box->x - 20;
        }
        
        if(abs(box->y - target_y) <= 20) // �������С��20����ֱ�ӵ���Ŀ��λ��
        {
            new_y = target_y;
        }
        else if (box->y + 20 < target_y) // �����ƶ�
        {
            new_y = box->y + 20;
        }
        else if (box->y - 20 > target_y) // �����ƶ�
        {
            new_y = box->y - 20;
        }

        // ������λ�õı���
        for (i = 0; i < box->height; i++)
        {
            for (j = 0; j < box->width; j++)
            {
                box->bg_buffer[i * box->width + j] = Getpixel64k(new_x + j, new_y + i);
            }
        }

        // ��������λ��
        box->x = new_x;
        box->y = new_y;

        // ����λ�û�������
        DrawBox(box, 0xFF0000); // ��ɫ����

        // �����ƶ��ٶ�
        delay(500); // ��ͣ10ms
    }
}

/*----- �������ӣ��ָ������� -----*/
void HideBox(BOX *box)
{
    int i, j; // ѭ������

    for (i = 0; i < box->height; i++)
    {
        for (j = 0; j < box->width; j++)
        {
            Putpixel64k(box->x + j, box->y + i, box->bg_buffer[i * box->width + j]);
        }
    }
}

/*----- �ͷ���Դ -----*/
void FreeBox(BOX *box)
{
    if (box->bg_buffer)
    {
        free(box->bg_buffer);
        box->bg_buffer = NULL;
    }
}

BOX box;  // ���ӽṹ��ʵ��