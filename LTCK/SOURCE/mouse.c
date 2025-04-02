#include"mouse.h"
#include <dos.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "SVGA.h"
//#include "draw.h"




int mouse_shape[H][W] =    //ï¿½ï¿½ï¿½ï¿½ï¿½×´ï¿½ï¿½Î¬ï¿½ï¿½ï¿½ï¿?
{
    {1,1,0,0,0,0,0,0,0,0,0,0},
	{1,2,1,0,0,0,0,0,0,0,0,0},
	{1,2,2,1,0,0,0,0,0,0,0,0},
	{1,2,2,2,1,0,0,0,0,0,0,0},
	{1,2,2,2,2,1,0,0,0,0,0,0},
	{1,2,2,2,2,2,1,0,0,0,0,0},
	{1,2,2,2,2,2,2,1,0,0,0,0},
	{1,2,2,2,2,2,2,2,1,0,0,0},
	{1,2,2,2,2,2,2,2,2,1,0,0},
	{1,2,2,2,2,2,2,2,2,2,1,0},
	{1,2,2,2,2,2,2,1,1,1,1,1},
	{1,2,2,1,2,2,2,1,0,0,0,0},
	{1,2,1,0,1,2,2,2,1,0,0,0},	
	{1,1,0,0,0,1,2,2,2,1,0,0},	
	{1,0,0,0,0,0,1,1,1,1,0,0}
		    			
};

unsigned int mouse_bk[20][20];           //ï¿½ï¿½Å±ï¿½ï¿½ï¿½ê¸²ï¿½Çµï¿½ï¿½ï¿½ï¿½ï¿½
MOUSE mouse={0,0,0};            //ï¿½ï¿½ï¿½ï¿½Ò»ï¿½ï¿½ï¿½ï¿½ï¿½á¹¹ï¿½ï¿½ï¿½ï¿½
 



/***ï¿½ï¿½ï¿½ï¿½Ê¼ï¿½ï¿½***/
void mouse_init()
{
	MouseInit();                  //ï¿½ï¿½ê¸´Î»ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ç·ï¿½×°ï¿½ï¿½ï¿?
	MouseRange(0,0,1012,752);         //ï¿½ï¿½ê·¶Î§ï¿½ï¿½ï¿½ï¿?
	MouseGet(&mouse);                  //ï¿½Ãµï¿½ï¿½ï¿½ï¿½×´Ì?
	MouseSpeed(6,4);
	mouse_on(mouse);                 //ï¿½ï¿½Ê¾ï¿½ï¿½ï¿?
}


/***ï¿½ï¿½ê¸´Î?***/
void MouseInit()
{
	union REGS regs;
	regs.x.ax=0;
	int86(0x33,&regs,&regs);
	if(regs.x.ax==0)
	{
		printf("mouse error");
		delay(5000);
		exit(1);
	}
}
/********************************
	ï¿½ï¿½ï¿½ï¿½Ëµï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ø±ï¿½,ÖµÔ½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Æ¶ï¿½ï¿½Ù¶ï¿½Ô½ï¿½ï¿? 
	ï¿½ï¿½ï¿½ï¿½Ëµï¿½ï¿½ï¿½ï¿½int   vx,	ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ä£ï¿½int   vy	ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
**
********************************/
void MouseSpeed(int x, int y)
{
	union REGS regs;
	regs.x.ax=0x0f;
	regs.x.cx=x;
    regs.x.dx=y;
	int86(0x33,&regs,&regs);
}
/**********************************************************************
	ï¿½ï¿½ï¿½ï¿½Ëµï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½È£ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ê±¶ï¿½ï¿½ï¿½ï¿½Öµï¿½ï¿½
	ï¿½ï¿½ï¿½ï¿½Ëµï¿½ï¿½ï¿½ï¿½xÎªË®Æ½ï¿½ï¿½ï¿½ï¿½ï¿½È£ï¿½yÎªï¿½ï¿½Ö±ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½,vÎªï¿½ï¿½ê¼´ï¿½ï¿½ï¿½è¶¨ï¿½Ä±ï¿½ï¿½ï¿½ï¿½ï¿½Ö?
	ï¿½ï¿½ï¿½ï¿½ÖµËµï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
*********************************************************************/
void SetMouseSen(int x,int y)
{
	union REGS regs;
    regs.x.ax=0x1a;
	regs.x.bx=x;
	regs.x.cx=y;
   // regs.x.dx=v;
	int86(51,&regs,&regs);
}
/***ï¿½Ãµï¿½Ä³Ò»ï¿½ï¿½ï¿½ï¿½ï¿½É«Ö?***/
unsigned int Getpixel64k(int x, int y)
{
	unsigned int far * const video_buffer = (unsigned int far *)0xa0000000L;
	unsigned char page;                                                  //Òªï¿½Ð»ï¿½ï¿½ï¿½Ò³ï¿½ï¿½ï¿?
	unsigned long int page_dev;                                           //ï¿½ï¿½Ó¦ï¿½Ô´ï¿½ï¿½Ö·Æ«ï¿½ï¿½ï¿½ï¿?                       
	if(x < 0 || x > (SCR_WIDTH - 1) || y < 0 || y > (SCR_HEIGHT - 1))           //ï¿½Ð¶Ïµï¿½ï¿½Ç·ï¿½ï¿½ï¿½ï¿½ï¿½Ä»ï¿½ï¿½Î§ï¿½Ú£ï¿½ï¿½ï¿½ï¿½Ú¾ï¿½ï¿½Ë³ï¿½ 
	{
		printf("out of range");
	}
	page_dev = ((unsigned long int)y << 10) + x;                              //ï¿½ï¿½ï¿½ï¿½ï¿½Ô´ï¿½ï¿½Ö·Æ«ï¿½ï¿½ï¿½ï¿½ï¿½Í¶ï¿½Ó¦ï¿½ï¿½Ò³ï¿½ï¿½Å£ï¿½ï¿½ï¿½ï¿½ï¿½Ò³ï¿½ï¿½ï¿½ï¿½
	page = page_dev >> 15;	//32kï¿½ï¿½ï¿½ï¿½Ò»ï¿½ï¿½Ò³ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½32kï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ã·?
	Selectpage(page);
	return video_buffer[page_dev];	 //ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½É«
}

/***ï¿½ï¿½ê·¶Î§ï¿½ï¿½ï¿½ï¿?***/
void MouseRange(int x1, int y1, int x2, int y2)
{
	union REGS mouse;
	/*ï¿½ï¿½ï¿½Ãºï¿½ï¿½ï¿½ï¿½ê·¶Î§*/
	mouse.x.ax = 7;
	mouse.x.cx = x1;
	mouse.x.dx = x2;
	int86(0x33, &mouse, &mouse);
	/*ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ê·¶Î§*/
	mouse.x.ax = 8;
	mouse.x.cx = y1;
	mouse.x.dx = y2;
	int86(0x33, &mouse, &mouse);
}


/***ï¿½Ãµï¿½ï¿½ï¿½ê°´ï¿½ï¿½×´Ì?(ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿?)***/
int MouseBut(MOUSE * mouse)
{ 
	union REGS regs;
	regs.x.ax = 3;
	int86(0x33, &regs, &regs);
	mouse->key = regs.x.bx;
	return mouse->key;     
}


/***ï¿½Ãµï¿½ï¿½ï¿½ï¿½Î»ï¿½Ã£ï¿½ï¿½ï¿½ï¿½ï¿½×´Ì?***/
int MouseGet(MOUSE * mouse)
{ 
	union REGS regs;
	regs.x.ax = 3;
	int86(0x33, &regs, &regs);
	mouse->x = regs.x.cx;
	mouse->y = regs.x.dx;
	mouse->key = regs.x.bx;
	return mouse->key;
}

/***ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê¾Î»ï¿½ï¿?***/
void MouseSet(int x,int y)
{
	union REGS regs;
    regs.x.ax=4;
	regs.x.cx=x;
    regs.x.dx=y;
	int86(0x33,&regs,&regs);      //ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½êµ±Ç°ï¿½ï¿½ï¿½ï¿?	
	mouse_on(mouse);               //ï¿½ï¿½ï¿½ï¿½ï¿?	
}

/***ï¿½Ð¶ï¿½ï¿½ï¿½ï¿½ï¿½Ç·ï¿½ï¿½ï¿½Ö¸ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ú²ï¿?***
int MouseIn(int x1, int y1, int x2, int y2)
{ 
	MOUSE mouse = {0,0,0};                       //very importantï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ò»ï¿½ï¿½ï¿½ï¿½ï¿½á¹¹ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ù¶ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½á¹¹ï¿½Äµï¿½ï¿½ï¿½ 
	MouseGet(&mouse);       
	if ((mouse.x >= x1)
		&& (mouse.x <= x2)
		&& (mouse.y >= y1)
		&& (mouse.y <= y2))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
**************************************************/

/***ï¿½Ð¶ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ç·ï¿½ï¿½ï¿½Ö¸ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ú°ï¿½ï¿½ï¿½***/
int mouse_press(int x1, int y1, int x2, int y2)
{ 
	MOUSE mouse = {0,0,0};                       
	MouseGet(&mouse);       
	if ((mouse.x >= x1)
		&& (mouse.x <= x2)
		&& (mouse.y >= y1)
		&& (mouse.y <= y2)
		&& ((mouse.key & 1) == 1))
	{
		return 1;
	}
	else if ((mouse.x >= x1)
		&& (mouse.x <= x2)
		&& (mouse.y >= y1)
		&& (mouse.y <= y2))
	{
		return 2;
	}
	else
	{
		return 0;
	}
}

/***ï¿½ï¿½ï¿½ï¿½ï¿½Ê?***/
void mouse_on(MOUSE mouse)
{
	int i, j;
	for (i = 0; i < H; i++)
	{
		for (j = 0; j < W; j++)
		{
			
			mouse_bk[i][j] = Getpixel64k(j + mouse.x, i + mouse.y);  //ï¿½æ´¢ï¿½ï¿½ê¸²ï¿½ï¿½ï¿½ï¿?
			/***ï¿½ï¿½ï¿½ï¿½ï¿?***/
			if (mouse_shape[i][j] == 1)
				Putpixel64k(mouse.x + j, mouse.y + i, 0);
			else if (mouse_shape[i][j] == 2)
				Putpixel64k(mouse.x + j, mouse.y + i, 0xffff);
		}
	}

}


/***ï¿½ï¿½ï¿½Ã¿ï¿½ï¿½ï¿½Æ¶ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ê?***/
void mouse_show(MOUSE *mouse)
{  
	int i,j;       //Ñ­ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½
	int color;     //ï¿½ï¿½ï¿½Ä³ï¿½ï¿½ï¿½ï¿½É?
	int x,y;
	x=mouse->x;             //ï¿½ï¿½ï¿½Ô­Î»ï¿½ï¿½ï¿½ï¿½ï¿½ï¿?
	y=mouse->y;         
	MouseGet(mouse);    //ï¿½Ãµï¿½ï¿½ï¿½ï¿½ï¿½ï¿½×´Ì?
	if(mouse->x!=x||mouse->y!=y)         //ï¿½ï¿½ï¿½ï¿½Æ¶ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Â»ï¿½ï¿½ï¿½ï¿½
	{
		for (i = 0; i < H; i++)           	
		{
			for (j = 0; j < W; j++)
			{
				if (mouse_shape[i][j] == 0)
					continue;
				Putpixel64k(x + j, y + i, mouse_bk[i][j]);   //ï¿½ï¿½ï¿½ï¿½Ô­ï¿½ï¿½ê¸²ï¿½ï¿½ï¿½ï¿?
			}
		}
		mouse_on(*mouse);                            //ï¿½ï¿½ï¿½ï¿½Î»ï¿½ï¿½ï¿½ï¿½Ê¾ï¿½ï¿½ï¿?
	}
}

/***ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿?***/
void mouse_off(MOUSE *mouse)
{
	int i,j;
	int x,y;
	x=mouse->x;
	y=mouse->y;
	for (i = 0; i <H; i++)
		for (j = 0; j < W; j++)
		{
			if (mouse_shape[i][j] == 0)
				continue;
			Putpixel64k(x + j, y + i, mouse_bk[i][j]);   //ï¿½ï¿½ï¿½ï¿½Ô­ï¿½ï¿½ê¸²ï¿½ï¿½ï¿½ï¿?
		}
}

/*ï¿½ï¿½Ê¼ï¿½ï¿½ï¿½ï¿½ê£¬ï¿½ï¿½ï¿½ï¿½Ë®Æ½ï¿½ï¿½Ö±ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½Ø±ï¿½ï¿½ï¿½ï¿½*/
void Curinit()
{
	_AX=0;
	geninterrupt(0x33);
	if(_AX==0)
		puts("mouse init fail!");
	_AX=7;
	_CX=10;
	_DX=1000;
	geninterrupt(0x33);
	_AX=8;
	_CX=10;
	_DX=750;
	geninterrupt(0x33);
}

void draw_mouse(int mx,int my)
{
	int i, j;
	for (i = 0; i < H; i++)
	{
		for (j = 0; j < W; j++)
		{
			/***ï¿½ï¿½ï¿½ï¿½ï¿?***/
			if (mouse_shape[i][j] == 1)
				Putpixel64k(mx + j, my + i, 0);
			else if (mouse_shape[i][j] == 2)
				Putpixel64k(mx + j, my + i, 0xffff);
		}
	}
}

void CurShow()
{
	Cursor(500,500,2);
}

void Curhide()
{
	Cursor(500,500,1);
}

void Cursor(int x,int y,int flag)
{
	static unsigned int far *tempgraph;
	static int mx,my;
    if(tempgraph==NULL)
	{
		tempgraph=malloc(1000);
	}
	if(1<=x&&x<=1000&&1<=y&&y<=750)
	{
		switch(flag)
		{			
		case 1:	//hidemouse
			Put_image(mx,my,mx+16,my+15,tempgraph);
			//delay(20);
			break;
		case 2:	//showmouse
			do
			{
				_AX=3;
				geninterrupt(0x33);
				mx=_CX;
				my=_DX;
			}
			while(1>=mx||mx>=1000||1>=my||my>=750);
			Get_image(mx,my,mx+16,my+15,tempgraph);
			draw_mouse(mx,my);
			break;
		}
	}
}

void getmouse(int *button,int *x,int *y)
{
	static int mx,my,mbutton;
	_AX=3;
	geninterrupt(0x33);
	mbutton=_BL;
	mx=_CX;
	my=_DX;
	Cursor(mx,my,0);
	if(button!=NULL)
		*button=mbutton;
	if(x!=NULL&&y!=NULL)
	{
		*x=mx;
		*y=my;
	}
}

/*----- »ñÈ¡Êó±ê×ø±ê -----*/
int GetMouseX(void) {
    union REGS regs;
    regs.x.ax = 0x03;     // ¹¦ÄÜºÅ£º»ñÈ¡Êó±ê×´Ì¬
    int86(0x33, &regs, &regs);
    return regs.x.cx;      // ·µ»ØX×ø±ê£¨·Ö±æÂÊÏà¹Ø£¬ÐèÐ£×¼£©
}

int GetMouseY(void) {
    union REGS regs;
    regs.x.ax = 0x03;
    int86(0x33, &regs, &regs);
    return regs.x.dx;      // ·µ»ØY×ø±ê
}
