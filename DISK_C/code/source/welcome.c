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
	bar(200-75,340-50,200+75,340+50);
	bar(480-75,340-50,480+75,340+50);//用户与管理员处形状 
	
	puthz(200-30, 330, "用户", 24, 32, BLACK);		 //用户
	puthz(480-38, 330, "管理员", 24, 28, BLACK); //管理员

	setfillstyle(SOLID_FILL, WHITE);
	bar(640, 0, 595, 45);
	setlinestyle(0, 0, 3);
	setcolor(BLACK);
	line(635, 5, 600, 40);
	line(635, 5, 600, 5);
	line(635, 5, 635, 40);
	line(600, 40, 635, 40);
	line(600, 40, 600, 5);
	line(600, 5, 635, 40); //退出按钮
	
	
}

/**
  * @brief  欢迎界面人机交互功能 
  			the man-machine interaction of the welcome interface
  * @param  None 
  * @retval the num of page 
  */
int welcome_page(){
	int num = 0;//设置按钮序号 
	welcome_view();
	mouseinit(); //初始化鼠标
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if(MouseX>600&&MouseX<635&&MouseY>5&&MouseY<40)
		{
			if(mouse_press(600,5,635,40) == 2){
				if (num == 0)
				{
					MouseS = 1;
					num = 3;
					button_change(num);
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
				button_recover(num);//页面恢复 
				num = 0;
			}
			continue;
		}
	}
}

/**
  * @brief  不点击按钮触发按钮颜色改变的事件
  * @param  num_X: where x can be (1,2,3) to select the model of the button situation.
  * @retval None 
  */
void button_change(int num_X)
{
	clrmous(MouseX, MouseY);
	delay(10);

	setlinestyle(0, 0, 1);
	setcolor(BLACK);

	switch(num_X)
	{
		case 3:
			setfillstyle(SOLID_FILL, RED);
			bar(640, 0, 595, 45);
			setlinestyle(0, 0, 3);
			setcolor(WHITE);
			line(635, 5, 600, 40);
			line(635, 5, 600, 5);
			line(635, 5, 635, 40);
			line(600, 40, 635, 40);
			line(600, 40, 600, 5);
			line(600, 5, 635, 40); 
			break;
	}
}

/**
  * @brief  鼠标离开后重置按键 
  * @param  num_X: where x can be (1,2,3) to select the model of the button situation.
  * @retval None 
  */
void button_recover(int num_X){
	clrmous(MouseX, MouseY);
	delay(10);

	setlinestyle(0, 0, 1);
	setcolor(BLACK);
	
	switch(num_X){
		case 3:
			setfillstyle(SOLID_FILL, WHITE);
			bar(640, 0, 595, 45);
			setlinestyle(0, 0, 3);
			setcolor(BLACK);
			line(635, 5, 600, 40);
			line(635, 5, 600, 5);
			line(635, 5, 635, 40);
			line(600, 40, 635, 40);
			line(600, 40, 600, 5);
			line(600, 5, 635, 40);
			break;
		default:
			closegraph();
			printf("wrong syntax");
			exit(1);
			break;
	}
} 
