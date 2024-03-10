#include"welcome.h" 
#include"common.h"

/**
  * @brief  初始化欢迎界面 
  			the initialization of the welcome screen
  * @param  None 
  * @retval None 
  */
void welcome_view()
{
	setlinestyle(0, 0, 1);
	setcolor(BLACK); //线形
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	bar(0, 0, 640, 480); //背景
	
	puthz(210, 100, "采摘系统",48, 48, BLACK);

	setfillstyle(SOLID_FILL, WHITE);
	draw_button(200-75,340-50,200+75,340+50,LIGHTGREEN);
	draw_button(480-75,340-50,480+75,340+50,LIGHTGREEN);//用户与管理员处形状 
	
	puthz(200-30, 330, "用户", 24, 32, BLACK);	 //用户
	puthz(480-38, 330, "管理员", 24, 28, BLACK); //管理员
	
	ESC_draw();//退出按钮
}

/**
  * @brief  欢迎界面人机交互功能 
  			the man-machine interaction of the welcome interface
  * @param  None 
  * @retval the num of page 
  */
int welcome_page(){
	int num = 0;//设置按钮序号
/**
  *     @arg 1:user button
  *     @arg 2:master button 
  *     @arg 3:ESC
  */
	welcome_view();
	mouseinit(); //初始化鼠标
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		
		//用户交互
		if(MouseX>200-75&&MouseX<200+75&&MouseY>340-50&&MouseY<340+50)
		{
			if(mouse_press(200-75,340-50,200+75,340+50) == 2){
				if (num == 0)
				{
					MouseS = 1;
					num = 1;
					button_change(200-75,340-50,200+75,340+50);
				} //用户按钮 
				continue;
			}
			else if(mouse_press(200-75,340-50,200+75,340+50))//用户按钮
			{
				delay(1000);
				return 1;
			}
		}
		
		//管理员交互
		if(MouseX>480-75&&MouseX<480+75&&MouseY>340-50&&MouseY<340+50)
		{
			if(mouse_press(480-75,340-50,480+75,340+50) == 2){
				if (num == 0)
				{
					MouseS = 1;
					num = 2;
					button_change(480-75,340-50,480+75,340+50);
				} //管理员按钮 
				continue;
			}
			else if(mouse_press(480-75,340-50,480+75,340+50))//用户按钮
			{
                delay(1000);
		     	return 2;
			}
		}
		
		//ESC交互 
		else if(MouseX>600&&MouseX<635&&MouseY>5&&MouseY<40)
		{
			if(mouse_press(600,5,635,40) == 2){
				if (num == 0)
				{
					MouseS = 1;
					num = 3;
					ESC_change();
				} //退出按钮未按
				continue;
			}
			else if(mouse_press(600,5,635,40) == 1)//退出按钮 
			{
				setcolor(LIGHTRED);
				setfillstyle(SOLID_FILL, YELLOW);
				bar(0, 0, 640, 480);
				settextstyle(GOTHIC_FONT, HORIZ_DIR, 9);
				outtextxy(30, 160, "THANK YOU");
				delay(3000);
				exit(1);
			}
		}
		else
		{
			if (num != 0)
			{
				MouseS = 0;
				switch(num){
					case 1:
						button_recover(200-75,340-50,200+75,340+50);
						break; 
					case 2:
						button_recover(480-75,340-50,480+75,340+50);
						break;
					case 3:
						ESC_recover();//页面恢复 
						break;
				}
				num = 0;
			}
			continue;
		}
	}
}


