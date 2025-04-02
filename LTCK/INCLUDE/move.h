#ifndef _MOVE_H_
#define _MOVE_H_

#include "allfunc.h"

void store();// 存储箱子到仓库
int have_stored(int in_or_out);// 判断是否有存储的箱子
void get_out();// 取出箱子
void get_in(int box_num);// 取入箱子


#endif