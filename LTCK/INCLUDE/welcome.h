#ifndef _WELCOME_H_
#define _WELCOME_H_
#include "allfunc.h"
typedef struct user
{
	char name[21];
	char password[21];
}User;

void welcome(int* state);
void login(int* state);
void registerf(int *state); 
void draw_basic_logging(void);
void draw_welcome(void);
void draw_botton(int x1 ,int y1,int x2,int y2,int Cowercolor,int Bordercolor);
void input_user_name(int x1,int y1,char *name,int num,int a1,int b1,int c1,int d1);
void input_user_password(int x1,int y1,char *code,int num,int a1,int b1,int c1,int d1);

int establish_user_profile(User temp);
int user_name_match(char *p);
int user_info_match(User temp);
void show_gb(int x,int y);

#endif
