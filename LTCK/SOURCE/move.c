#include "allfunc.h"
extern BOX box; // 声明箱子结构体
extern int keyboard_coordinate[16][6]; // 声明键盘坐标数组
void store()// 存储箱子到仓库
{
    int i;
    // mouse_off(&mouse); // 隐藏鼠标
    for(i=0;i<16;i++){
        if(keyboard_coordinate[i][4]==1){
            InitBox(&box, 55, 595, 75, 75); // 初始化箱子
            DrawBox(&box, 0xFF0000); // 绘制箱子
            MoveBox(&box,150+(i%4)*130+17,540-i/4*130+35); // 移动箱子到目标位置
            replace_color(keyboard_coordinate[i][0]-4,keyboard_coordinate[i][1]-4,keyboard_coordinate[i][2]+4,keyboard_coordinate[i][3], 0x66ff66, 0xff00ff);
            keyboard_coordinate[i][4]=0;
            keyboard_coordinate[i][5]=1; // 变为已经存储状态
            delay(500);
        }
    }
}

int have_stored(int in_or_out)// 检测箱子目前存储情况是否合法
{
    int i;
    if(in_or_out == 1){
        for(i=0;i<16;i++){
            if(keyboard_coordinate[i][4]==0){
                continue; // 如果没有存储的箱子，继续循环
            }
            else{
                if(keyboard_coordinate[i][5]==1){
                    return 0; // 如果有存储的箱子，返回0
                }
            }
        }
    }
    else{
        for(i=0;i<16;i++){
            if(keyboard_coordinate[i][4]==0){
                continue; // 如果没有按下按键，继续循环
            }
            else{
                if(keyboard_coordinate[i][5]==0){
                    return 0; // 如果没有存储的箱子，返回0
                }
            }
        }
        return 1; // 均有存储的箱子
    }
    return 1; // 无存储的箱子
}

void get_out()
{
    int i;
    // mouse_off(&mouse); // 隐藏鼠标
    for(i=0;i<16;i++){
        if(keyboard_coordinate[i][4]==1){
            bar1(150+(i%4)*130+17,540-i/4*130+35 ,150+(i%4)*130+17+75,540-i/4*130+35+75,0x66ff66); // 清除箱子
            InitBox(&box,150+(i%4)*130+17,540-i/4*130+35 ,75, 75); // 初始化箱子
            DrawBox(&box, 0xFF0000); // 绘制箱子
            MoveBox(&box, 55, 595); // 移动箱子到目标位置
            bar1(55,595,130,670,0xffffff); // 清除箱子
            replace_color(keyboard_coordinate[i][0]-4,keyboard_coordinate[i][1]-4,keyboard_coordinate[i][2]+4,keyboard_coordinate[i][3], 0x66ff66, 0xff00ff);
            keyboard_coordinate[i][4]=0;
            keyboard_coordinate[i][5]=0; // 变为已经存储状态
            delay(500);
        }
    }
}