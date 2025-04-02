#include "allfunc.h"

void welcome(int *state)
{
	mouse_off(&mouse);
	delay(100);
	bar1(0, 0, 1024, 768, 0xFFFFBB);
	bar1(200, 200, 840, 768, 0xFFFFFF);
	bar1(300, 350, 700, 480, 0x66ff66);
	bar1(300, 520, 700, 650, 0x66ff66);
	bar1(950, 710, 1000, 750, 0x66ff66);
	puthz(280, 100, "立体仓库模拟管理系统", 48, 48, 0);
	puthz(420, 400, "登录", 48, 48, 0x000000);
	puthz(420, 570, "注册", 48, 48, 0x000000);
	puthz(960, 715, "退出", 16, 16, 0x000000);
	mouse_on(mouse);
	while (1)
	{
		mouse_show(&mouse);
		if (mouse_press(300 + 2, 350 + 2, 700 - 2, 480 - 2) == 1)
		{
			*state = 2;
			break;
		}
		else if (mouse_press(302, 522, 698, 648) == 1)
		{
			*state = 3;
			break;
		}
		else if (mouse_press(952, 712, 998, 748) == 1)
		{
			while (MouseGet(&mouse) & 1);
			*state = -1;
			break;
		}
		delay(15);
	}

	// getchar();
}

void login(int *state)
{
	User temp = {0};
	mouse_off(&mouse);
	delay(100);
	bar1(0, 0, 1024, 768, 0xFFFFBB);
	bar1(200, 200, 840, 768, 0xFFFFFF);
	puthz(460, 100, "登录", 48, 96, 0);
	bar1(230, 270, 350, 360, 0x66ff66);
	bar1(230, 430, 350, 520, 0x66ff66);
	bar1(950, 710, 1000, 750, 0x66ff66);
	puthz(232, 272, "用户名", 32, 30, 0);
	puthz(232, 432, "密码", 32, 30, 0);
	puthz(960, 715, "返回", 16, 16, 0x000000);
	Line3(380, 360, 800, 360, 2, 0);
	Line3(380, 520, 800, 530, 2, 0);
	mouse_on(mouse);
	while (1)
	{
		mouse_show(&mouse);
		if (mouse_press(952, 712, 998, 748) == 1)
		{
			*state = 0;
			break;
		}
		else if (mouse_press(382, 272, 798, 358) == 1)
		{
			mouse_off(&mouse);
			input_user_name(382, 272, temp.name, 20, 382, 272, 798, 358);
			mouse_on(mouse);
		}
		else if (mouse_press(382, 432, 798, 518) == 1)
		{
			mouse_off(&mouse);
			input_user_password(382, 432, temp.password, 20, 383, 432, 798, 518);
			mouse_on(mouse);
			if (strcmp(temp.name, "\0") == 0)
			{
				puthz(480, 720, "用户名为空！", 16, 20, 0);
				delay(1000);
				bar1(470, 710, 820, 750, 0xFFFFFF);
				bar1(380, 270, 800, 360, 0xFFFFFF);
				bar1(380, 430, 800, 520, 0xFFFFFF);
				continue;
			}
			else if (strcmp(temp.password, "\0") == 0)
			{
				puthz(480, 720, "密码为空！", 16, 20, 0);
				delay(1000);
				bar1(470, 710, 820, 750, 0xFFFFFF);
				bar1(380, 270, 800, 360, 0xFFFFFF);
				bar1(380, 430, 800, 520, 0xFFFFFF);
				continue;
			}
			else if (user_name_match(temp.name) != 0)
			{
				puthz(480, 720, "未找到该用户！", 16, 20, 0);
				delay(1000);
				bar1(470, 710, 820, 750, 0xFFFFFF);
				bar1(380, 270, 800, 360, 0xFFFFFF);
				bar1(380, 430, 800, 520, 0xFFFFFF);
				continue;
			}
			else if (user_info_match(temp) != 0)
			{
				puthz(480, 720, "密码错误！", 16, 20, 0);
				delay(1000);
				bar1(470, 710, 820, 750, 0xFFFFFF);
				bar1(380, 270, 800, 360, 0xFFFFFF);
				bar1(380, 430, 800, 520, 0xFFFFFF);
				continue;
			}
			else
			{
				puthz(480, 720, "成功，正在登录中", 16, 20, 0);
				delay(1000);
				*state = 4;
				break;
			}
		}
		delay(15);
	}
}
void show_gb(int x, int y)
{
	Line1(x, y, x, y + 48, 0);
}
void registerf(int *state)
{
	User temp = {0};
	char password[20];
	mouse_off(&mouse);
	delay(100);
	bar1(0, 0, 1024, 768, 0xFFFFBB);
	bar1(200, 200, 840, 768, 0xFFFFFF);
	puthz(460, 100, "注册", 48, 96, 0);
	bar1(230, 270, 350, 360, 0x66ff66);
	bar1(230, 430, 350, 520, 0x66ff66);
	bar1(230, 590, 350, 680, 0x66ff66);
	bar1(950, 710, 1000, 750, 0x66ff66);
	puthz(232, 272, "用户名", 32, 30, 0);
	puthz(232, 432, "密码", 32, 30, 0);
	puthz(232, 592, "密码验证", 32, 30, 0);
	puthz(960, 715, "返回", 16, 16, 0x000000);
	Line3(380, 360, 800, 360, 2, 0);
	Line3(380, 520, 800, 530, 2, 0);
	Line3(380, 680, 800, 680, 2, 0);
	mouse_on(mouse);
	while (1)
	{
		mouse_show(&mouse);
		if (mouse_press(952, 712, 998, 748) == 1)
		{
			*state = 0;
			break;
		}
		else if (mouse_press(382, 272, 798, 358) == 1)
		{
			mouse_off(&mouse);
			input_user_name(382, 272, temp.name, 20, 382, 272, 798, 358);
			mouse_on(mouse);
		}
		else if (mouse_press(382, 432, 798, 518) == 1)
		{
			mouse_off(&mouse);
			input_user_password(382, 432, temp.password, 20, 383, 432, 798, 518);
			mouse_on(mouse);
		}
		else if (mouse_press(382, 592, 798, 678) == 1)
		{
			mouse_off(&mouse);
			input_user_password(382, 592, password, 20, 382, 592, 798, 678);
			mouse_on(mouse);
			if (strcmp(temp.name, "\0") == 0)
			{
				puthz(480, 720, "用户名为空！", 16, 20, 0);
				delay(1000);
				bar1(470, 710, 820, 750, 0xFFFFFF);
				bar1(380, 270, 800, 360, 0xFFFFFF);
				bar1(380, 430, 800, 520, 0xFFFFFF);
				bar1(380, 590, 800, 680, 0xFFFFFF);
				continue;
			}
			else if (strcmp(temp.password, "\0") == 0)
			{
				puthz(480, 720, "密码为空！", 16, 20, 0);
				delay(1000);
				bar1(470, 710, 820, 750, 0xFFFFFF);
				bar1(380, 270, 800, 360, 0xFFFFFF);
				bar1(380, 430, 800, 520, 0xFFFFFF);
				bar1(380, 590, 800, 680, 0xFFFFFF);
				continue;
			}
			else if (strcmp(temp.password, password) != 0)
			{
				puthz(480, 720, "两次密码不同！", 16, 20, 0);
				delay(1000);
				bar1(470, 710, 820, 750, 0xFFFFFF);
				bar1(380, 270, 800, 360, 0xFFFFFF);
				bar1(380, 430, 800, 520, 0xFFFFFF);
				bar1(380, 590, 800, 680, 0xFFFFFF);
				continue;
			}
			else if (establish_user_profile(temp) != 0)
			{
				puthz(480, 720, "账户创建失败！", 16, 20, 0);
				delay(1000);
				bar1(470, 710, 820, 750, 0xFFFFFF);
				bar1(380, 270, 800, 360, 0xFFFFFF);
				bar1(380, 430, 800, 520, 0xFFFFFF);
				bar1(380, 590, 800, 680, 0xFFFFFF);
				continue;
			}
			else
			{
				puthz(480, 720, "成功，请返回登录。", 16, 20, 0);
				*state = 0;
				break;
			}
		}
		delay(15);
	}
}
void input_user_name(int x1, int y1, char *name, int num, int a1, int b1, int c1, int d1)
{
	char showtemp[2] = {0, 0};
	int i = 0, k, temp;
	int border = x1 + 4; // border表示显示图片的左边界
	x1 = x1 + 4;
	y1 = y1 + 5;
	while (bioskey(1)) // 清空输入缓冲区
	{
		bioskey(0);
	}
	border += 24 * i;
	while (1) // 当按下回车键时表示输入完毕（回车键值为13）
	{
		show_gb(border, y1);					  // 光标闪烁
		if (bioskey(1) == 0 || !MouseGet(&mouse)) // 延时函数，使光标闪烁，在点击鼠标或有输入时退出
		{
			for (k = 0; k < 100; k++) // 延时的同时检测鼠标键盘
			{
				delay(2);
				if (bioskey(1) || MouseGet(&mouse))
				{
					break;
				}
			}
		}
		if (bioskey(1))
		{
			temp = bioskey(0) & 0x00ff;
			if (temp != '\r' && temp != '\n') // 检测输入不为回车键，则继续，否则输入结束
			{
				if (('0' <= temp && temp <= '9' || ('a' <= temp && temp <= 'z') /*||temp=='_'*/) && i < num) // 检测为数字或字母或下划线，则记录
				{
					bar1(border, y1, border + 24, y1 + 48, 0xffff);
					name[i] = temp; // 字符送入给定字符串
					*showtemp = temp;
					put_asc16_size(border, y1 - 2, 3, 3, showtemp, 0); // 显示新的字符串达到画面与实际输入的同步
					i++;
					name[i] = '\0'; // 标记字符串结尾
					border += 24;
					show_gb(border, y1);
				}
				else if ('A' <= temp && temp <= 'Z' && i < num) // 由于文件名不区分大小写，而后面的文件部分要用用户名做文件名
				{												// 故在注册时就不区分大小写了
					bar1(border, y1, border + 24, y1 + 48, 0xffff);
					temp += 32;
					name[i] = temp;	  // 字符送入给定字符串
					*showtemp = temp; // 显示新的字符串达到画面与实际输入的同步
					put_asc16_size(border, y1 - 2, 3, 3, showtemp, 0);
					i++;
					name[i] = '\0'; // 标记字符串结尾
					border += 24;
					show_gb(border, y1);
				}
				else if (temp == '\b' && i > 0) // 检测是否为退格键，是则消除前一个字符
				{
					border -= 24;
					bar1(border, y1, border + 24, y1 + 48, 0xffff);
					i--;
					name[i] = '\0';
					bar1(border, y1, border + 24, y1 + 48, 0xffff);
					show_gb(border, y1);
				}
			}
			else
			{
				break;
			}
		}
		if (!mouse_press(a1, b1, c1, d1) && MouseGet(&mouse)) // 如果鼠标点击输入框外的部分，退出
		{
			break;
		}
		bar1(border, y1, border + 24, y1 + 48, 0xffff);
		if (bioskey(1) == 0 || !MouseGet(&mouse)) // 延时函数，使光标闪烁，在点击鼠标或有输入时退出
		{
			for (k = 0; k < 100; k++) // 延时的同时检测鼠标键盘
			{
				delay(2);
				if (bioskey(1) || MouseGet(&mouse))
				{
					break;
				}
			}
		}
	}
	bar1(border, y1, border + 24, y1 + 48, 0xffff);
}
void input_user_password(int x1, int y1, char *code, int num, int a1, int b1, int c1, int d1)
{
	char showtemp[2] = {0, 0};
	int key; // 按键值
	int i = 0, k, temp;
	int border = x1 + 4; // border表示显示图片的左边界
	x1 = x1 + 4;
	y1 = y1 + 5;
	while (bioskey(1)) // 清空输入缓冲区
	{
		bioskey(0);
	}
	border += 24 * i;
	while (1) // 当按下回车键时表示输入完毕（回车键值为13）
	{
		show_gb(border, y1);
		if (bioskey(1) == 0 || !MouseGet(&mouse)) // 延时函数，使光标闪烁，在点击鼠标或有输入时退出
		{
			for (k = 0; k < 100; k++) // 延时的同时检测鼠标键盘
			{
				delay(2);
				if (bioskey(1) || MouseGet(&mouse))
				{
					break;
				}
			}
		}
		if (bioskey(1))
		{
			temp = bioskey(0) & 0x00ff;
			if (temp != '\r' && temp != '\n') // 检测输入不为回车键，则继续，否则输入结束
			{
				if (('0' <= temp && temp <= '9' || 'a' <= temp && temp <= 'z' || temp == '_') && i < num) // 检测为数字或字母或下划线，则记录
				{
					bar1(border, y1, border + 24, y1 + 48, 0xffff);
					code[i] = temp; // 字符送入给定字符串
					*showtemp = temp;
					put_asc16_size(border, y1 - 2, 3, 3, showtemp, 0); // 显示新的字符串达到画面与实际输入的同步
					delay(150);
					bar1(border, y1, border + 24, y1 + 48, 0xffff);
					put_asc16_size(border, y1 - 2, 3, 3, "_", 0);
					delay(50);
					bar1(border, y1, border + 8, y1 + 16, 0xffff);
					put_asc16_size(border, y1 - 2, 3, 3, "*", 0);
					i++;
					code[i] = 0; // 标记字符串结尾
					border += 24;
					show_gb(border, y1);
				}
				else if ('A' <= temp && temp <= 'Z' && i < num) // 由于文件名不区分大小写，而后面的文件部分要用用户名做文件名
				{												// 故在注册时就不区分大小写了
					bar1(border, y1, border + 24, y1 + 48, 0xffff);
					temp += 32;
					code[i] = temp;	  // 字符送入给定字符串
					*showtemp = temp; // 显示新的字符串达到画面与实际输入的同步
					put_asc16_size(border, y1 - 2, 3, 3, showtemp, 0);
					delay(300);
					bar1(border, y1, border + 24, y1 + 48, 0xffff);
					put_asc16_size(border, y1 - 2, 3, 3, "_", 0);
					delay(100);
					bar1(border, y1, border + 24, y1 + 48, 0xffff);
					put_asc16_size(border, y1 - 2, 3, 3, "*", 0);
					i++;
					code[i] = 0; // 标记字符串结尾
					border += 24;
					show_gb(border, y1);
				}
				else if (temp == '\b' && i > 0) // 检测是否为退格键，是则消除前一个字符
				{
					border -= 24;
					bar1(border, y1, border + 24, y1 + 48, 0xffff);
					i--;
					code[i] = 0;
					bar1(border, y1, border + 24, y1 + 48, 0xffff);
					show_gb(border, y1);
				}
			}
			else
			{
				break;
			}
		}
		if (!mouse_press(a1, b1, c1, d1) && MouseGet(&mouse)) // 如果鼠标点击输入框外的部分，退出
		{
			break;
		}
		bar1(border, y1, border + 24, y1 + 48, 0xffff);
		if (bioskey(1) == 0 || !MouseGet(&mouse)) // 延时函数，使光标闪烁，在点击鼠标或有输入时退出
		{
			for (k = 0; k < 100; k++) // 延时的同时检测鼠标键盘
			{
				delay(2);
				if (bioskey(1) || MouseGet(&mouse))
				{
					break;
				}
			}
		}
	}
	bar1(border, y1, border + 24, y1 + 48, 0xffff);
}
int establish_user_profile(User temp)
{
	FILE *fp = NULL;
	int match_result;
	if ((fp = fopen("C:\\LTCK\\userinfo.dat", "ab+")) == NULL)
	{
		puthz(480, 720, "文件无法打开！", 16, 20, 0);
		delay(1000);
		bar1(470, 710, 820, 750, 0xFFFFFF);
		return 1;
	}
	match_result = user_name_match(temp.name);
	if (match_result == 0)
	{
		puthz(480, 720, "用户已存在！", 16, 20, 0);
		delay(1000);
		bar1(470, 710, 820, 750, 0xFFFFFF);
		return 2;
	}
	else if (match_result == -1)
	{
		puthz(480, 720, "文件无法打开！", 16, 20, 0);
		delay(1000);
		bar1(470, 710, 820, 750, 0xFFFFFF);
		return -1;
	}
	fseek(fp, 0, SEEK_END);
	fwrite(&temp, sizeof(User), 1, fp);
	fclose(fp);
	return 0;
}
int user_name_match(char *p)
{
	FILE *fp = NULL;
	User temp;
	if ((fp = fopen("C:\\LTCK\\userinfo.dat", "rb")) == NULL)
	{
		return -1;
	}
	while (fread(&temp, sizeof(User), 1, fp))
	{
		if (strcmp(temp.name, p) == 0)
		{
			fclose(fp);
			return 0;
		}
	}
	fclose(fp);
	return 1;
}
int user_info_match(User temp)
{
	FILE *fp = NULL;
	User ttemp;
	if ((fp = fopen("C:\\LTCK\\userinfo.dat", "rb")) == NULL)
	{
		return -1;
	}
	while (fread(&ttemp, sizeof(User), 1, fp))
	{
		if (strcmp(ttemp.name, temp.name) == 0 && strcmp(ttemp.password, temp.password) == 0)
		{
			fclose(fp);
			return 0;
		}
	}
	fclose(fp);
	return 1;
}
