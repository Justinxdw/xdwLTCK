#include "allfunc.h"
extern BOX box; // �������ӽṹ��
extern int keyboard_coordinate[16][6]; // ����������������
void store()// �洢���ӵ��ֿ�
{
    int i;
    // mouse_off(&mouse); // �������
    for(i=0;i<16;i++){
        if(keyboard_coordinate[i][4]==1){
            InitBox(&box, 55, 595, 75, 75); // ��ʼ������
            DrawBox(&box, 0xFF0000); // ��������
            MoveBox(&box,150+(i%4)*130+17,540-i/4*130+35); // �ƶ����ӵ�Ŀ��λ��
            replace_color(keyboard_coordinate[i][0]-4,keyboard_coordinate[i][1]-4,keyboard_coordinate[i][2]+4,keyboard_coordinate[i][3], 0x66ff66, 0xff00ff);
            keyboard_coordinate[i][4]=0;
            keyboard_coordinate[i][5]=1; // ��Ϊ�Ѿ��洢״̬
            delay(500);
        }
    }
}

int have_stored(int in_or_out)// �������Ŀǰ�洢����Ƿ�Ϸ�
{
    int i;
    if(in_or_out == 1){
        for(i=0;i<16;i++){
            if(keyboard_coordinate[i][4]==0){
                continue; // ���û�д洢�����ӣ�����ѭ��
            }
            else{
                if(keyboard_coordinate[i][5]==1){
                    return 0; // ����д洢�����ӣ�����0
                }
            }
        }
    }
    else{
        for(i=0;i<16;i++){
            if(keyboard_coordinate[i][4]==0){
                continue; // ���û�а��°���������ѭ��
            }
            else{
                if(keyboard_coordinate[i][5]==0){
                    return 0; // ���û�д洢�����ӣ�����0
                }
            }
        }
        return 1; // ���д洢������
    }
    return 1; // �޴洢������
}

void get_out()
{
    int i;
    // mouse_off(&mouse); // �������
    for(i=0;i<16;i++){
        if(keyboard_coordinate[i][4]==1){
            bar1(150+(i%4)*130+17,540-i/4*130+35 ,150+(i%4)*130+17+75,540-i/4*130+35+75,0x66ff66); // �������
            InitBox(&box,150+(i%4)*130+17,540-i/4*130+35 ,75, 75); // ��ʼ������
            DrawBox(&box, 0xFF0000); // ��������
            MoveBox(&box, 55, 595); // �ƶ����ӵ�Ŀ��λ��
            bar1(55,595,130,670,0xffffff); // �������
            replace_color(keyboard_coordinate[i][0]-4,keyboard_coordinate[i][1]-4,keyboard_coordinate[i][2]+4,keyboard_coordinate[i][3], 0x66ff66, 0xff00ff);
            keyboard_coordinate[i][4]=0;
            keyboard_coordinate[i][5]=0; // ��Ϊ�Ѿ��洢״̬
            delay(500);
        }
    }
}