#include "allfunc.h"

void main()
{
	int state=0;
   	SetSVGA64k();
	mouse_init(); 
	if(mouse_press(0,0,1024,768)); 
	while(state!=-1)
	{
		switch(state)
		{
			case 0:
				welcome(&state);
				break;
			case 2:
				login(&state);
				break;
			case 3:
				registerf(&state);
				break;
			case 4:
				test(&state);
			default:
				break;
		}
	}    
	CloseSVGA();
}
