#ifndef _BOX_H_
#define _BOX_H_
#include "allfunc.h"

/*----- ���ӽṹ�� -----*/
typedef struct
{
    int x, y;                // ���ӵĵ�ǰλ��
    int width, height;       // ���ӵĿ�Ⱥ͸߶�
    unsigned int *bg_buffer; // ��������
} BOX;

/*----- ����ԭ�� -----*/
void InitBox(BOX *box, int x, int y, int width, int height); // ��ʼ������
void DrawBox(BOX *box, unsigned int color);                  // ��������
void MoveBox(BOX *box, int target_x, int target_y);          // �ƶ�����
void HideBox(BOX *box);                                      // ��������
void FreeBox(BOX *box);                                      // �ͷ���Դ

#endif