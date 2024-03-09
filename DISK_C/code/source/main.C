#include"common.h"
#include"main.h"

void main(){

	int page = WELCOME;//初始界面 

	int gdriver = VGA;
	int gmode = VGAHI;


	initgraph(&gdriver, &gmode, "C:\\BORLANDC\\BGI"); //初始化图形界面640*480


	while (1)
	{
		switch (page)
		{
		case WELCOME://进入初始画面 
			page = welcome_page();
			break;
		}
	}
	return 0;
}
