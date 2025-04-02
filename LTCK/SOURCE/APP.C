#include <allfunc.h>
#include <stdlib.h>

void test(int *state)
{
    int i, k; // 循环变量

    mouse_off(&mouse);
    test_page();
    mouse_on(mouse);
    // InitBox(&box, 55, 595, 75, 75); // 初始化箱子
    // DrawBox(&box, 0xFF0000); // 绘制箱子
    // getchar();
    // while(1){
    //     getchar();
    //     MoveBox(&box, 167, 185); // 移动箱子到目标位置
    //     getchar();
    // }
    while (1)
    {
        mouse_show(&mouse);
        if (mouse_press(950, 710, 1000, 750) == 1)//退出按钮
        {
            replace_color(950, 710, 1000, 750, 0x66ff66, 0xff00ff);
            delay(50);
            replace_color(950, 710, 1000, 750, 0x66ff66, 0xff00ff);
            while (MouseGet(&mouse) & 1); // 等待鼠标释放
            *state = -1; // 退出程序
            break;
        }
        key_press();
        if(mouse_press(924,350,994,401)==1){
            replace_color(924-4,350-4,994+4,401,0x66ff66,0xff00ff);
            delay(100);
            replace_color(924-4,350-4,994+4,401,0x66ff66,0xff00ff);
            if(have_stored(1)==1){
                mouse_off(&mouse); // 隐藏鼠标
                store(); // 存储箱子到仓库
            }
            else{
                puthz(764,402,"选中位置已有货物",16,20,0x000000);
                delay(1000);
                bar1(764,402,1000,418,0x0066ff);
            }
        }
        if(mouse_press(750,350,820,401)==1){
            replace_color(750-4,350-4,820+4,401,0x66ff66,0xff00ff);
            delay(100);
            replace_color(750-4,350-4,820+4,401,0x66ff66,0xff00ff);
            if(have_stored(2)==1){
                mouse_off(&mouse); // 隐藏鼠标
                get_out(); // 取出箱子
            }
            else{
                puthz(764,402,"选中位置无货物",16,20,0x000000);
                delay(1000);
                bar1(764,402,1000,418,0x0066ff);
            }
        }
        delay(15);
    }
}

void test_page()
{
    int i, k, i1, k1;

    mouse_off(&mouse);
    delay(100);
    bar1(0, 0, 1024, 768, 0xFFFFff);
    bar1(130, 125, 670, 725, 0xffffbb); // 仓库底色
    for (i = 150; i < 600; i += 130)// 十六个位置
    {
        for (k = 150; k < 600; k += 130)
        {
            bar1(i, k, i + 110, k + 110, 0x66ff66);
            // getchar();
            bar1(i, k + 110, i + 110, k + 110 + 20, 0xff66ff);
            // getchar();
        }
    }
    bar1(0, 671, 700, 690, 0xff00ff);   // 横杆
    bar1(720, 40, 1024, 690, 0x000000); // 按键底盘
    bar1(730, 50, 1014, 680, 0x0066ff);
    bar1(720, 320, 1024, 327, 0x000000);
    for (i = 750, i1 = 1; i < 1000; i += 66, i1++) // 16个数字按键
    {
        for (k = 423, k1 = 1; k < 640; k += 66, k1++)
        {
            an_niu(i, k, i + 46, k + 51, 0x66ff66);
            my_put_asc16_number_size(i + 4, k + 10, 2, 2, 4 * (4 - k1) + i1, 0x000000);
        }
    }
    for (i = 750, i1 = 1, k = 350; i < 950; i += 87+87, i1++)
    {
        an_niu(i, k, i + 70, k + 51, 0x66ff66);
        if (i1 == 1)
            puthz(i + 10, k + 10, "出库", 24, 28, 0);
        else if (i1 == 2)
            puthz(i + 10, k + 10, "入库", 24, 28, 0);
        //     // puthz(i + 10, k + 10, "入库", 24, 28, 0);
        // else if (i1 == 3)
        //     puthz(i + 10, k + 10, 开始", 24, 28, 0);
    }
    for (i = 750, i1 = 1, k = 260; i < 950; i += 87, i1++)
    {
        an_niu(i, k, i + 70, k + 51, 0x66ff66);
        if (i1 == 1)
            puthz(i + 10, k + 10, "启动", 24, 28, 0);
        else if (i1 == 2)
            puthz(i + 10, k + 10, "停止", 24, 28, 0);
        else if (i1 == 3)
            puthz(i + 10, k + 10, "复位", 24, 28, 0);
    }
    for (i = 750, i1 = 1, k = 70, k1 = 1; k1 < 10; k1++) // 四个方向按键
    {
        if (k1 % 2 == 0)
        {
            an_niu(i, k, i + 70, k + 51, 0x66ff66);
            if (i1 == 1)
                puthz(i + 10, k + 10, "上行", 24, 28, 0);
            else if (i1 == 2)
                puthz(i + 10, k + 10, "左行", 24, 28, 0);
            else if (i1 == 3)
                puthz(i + 10, k + 10, "右行", 24, 28, 0);
            else if (i1 == 4)
                puthz(i + 10, k + 10, "下行", 24, 28, 0);
            i += 87;
            i1++;
        }
        else
        {
            i += 87;
        }
        if (i > 950)
        {
            k += 65;
            i = 750;
        }
    }
    puthz(210, 70, "模拟仓库管理系统", 48, 48, 0);
    bar1(950, 710, 1000, 750, 0x66ff66);
    puthz(960, 715, "退出", 16, 16, 0x000000);
    // getchar();
}

void an_niu(int x1, int y1, int x2, int y2, int color)
{
    bar1(x1 - 4, y1, x2 + 4, y2, color);
    bar1(x1, y1 - 4, x2, y2, color);
    Circlefill(x1, y1, 4, color);
    Circlefill(x2, y1, 4, color);
    // puthz(x1+10,y1+10,str,16,20,0);
}

void my_put_asc16_number_size(int x, int y, int xsize, int ysize, int n, unsigned int color)
{
    char *s[3];
    itoa(n, s, 10);
    put_asc16_size(x, y, xsize, ysize, s, color);
}

// /*
//  * 颜色替换函数 (C89 兼容版本)
//  * 参数：x1,y1,x2,y2 - 矩形对角坐标
//  *       old_color  - 要替换的颜色值
//  *       new_color  - 替换后的颜色值
//  */
// void replace_color(int x1, int y1, int x2, int y2, unsigned int old_color, unsigned int new_color)
// {
//     /*-------- 所有变量定义在函数开头 --------*/
//     int left, right, top, bottom;  // 矩形边界
//     int x, y;                       // 循环变量
//     unsigned int current;           // 当前像素颜色

//     mouse_off(&mouse);  // 隐藏鼠标
//     /*-------- 计算矩形边界 --------*/
//     left = (x1 < x2) ? x1 : x2;
//     right = (x1 > x2) ? x1 : x2;
//     top = (y1 < y2) ? y1 : y2;
//     bottom = (y1 > y2) ? y1 : y2;

//     /*-------- 遍历矩形区域 --------*/
//     for (y = top; y <= bottom; y++) {
//         for (x = left; x <= right; x++) {
//             current = Getpixel64k(x, y);  // 获取当前像素颜色
//             if (current == old_color) {
//                 Putpixel64k(x, y, new_color); // 替换颜色
//             }
//         }
//     }
// }

/*
 * 智能颜色替换函数（带恢复检查）
 * 参数：x1,y1,x2,y2 - 矩形对角坐标
 *       old_color  - 原颜色值
 *       new_color  - 替换颜色值
 * 返回值：1表示执行了替换，0表示未替换
 */
int replace_color(int x1, int y1, int x2, int y2,
                  unsigned int old_color, unsigned int new_color)
{
    /*-------- 变量定义（C89兼容） --------*/
    int left, right, top, bottom;
    int x, y, has_replaced = 0;
    unsigned int current;

    /*-------- 隐藏鼠标避免干扰 --------*/
    mouse_off(&mouse);

    /*-------- 计算矩形边界 --------*/
    left = (x1 < x2) ? x1 : x2;
    right = (x1 > x2) ? x1 : x2;
    top = (y1 < y2) ? y1 : y2;
    bottom = (y1 > y2) ? y1 : y2;

    /*-------- 颜色替换逻辑 --------*/
    for (y = top; y <= bottom; y++)
    {
        for (x = left; x <= right; x++)
        {
            current = Getpixel64k(x, y);

            /* 情况1：需要替换颜色 */
            if (current == old_color)
            {
                Putpixel64k(x, y, new_color);
                has_replaced = 1;
            }
            /* 情况2：检测到已变色，恢复原色 */
            else if (current == new_color)
            {
                Putpixel64k(x, y, old_color);
            }
        }
    }
    /*-------- 恢复鼠标显示 --------*/
    mouse_on(mouse);
    delay(250);  // 暂停250ms，避免频闪
    return has_replaced;
}