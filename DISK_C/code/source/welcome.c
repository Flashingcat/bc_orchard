#include"welcome.h" 
#include"common.h"

/**
  * @brief  ��ʼ����ӭ���� 
  			the initialization of the welcome screen
  * @param  None 
  * @retval None 
  */
void welcome_view()
{
	setlinestyle(0, 0, 1);
	setcolor(BLACK); //����
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	bar(0, 0, 640, 480); //����
	
	puthz(210, 100, "��ժϵͳ",48, 48, BLACK);

	setfillstyle(SOLID_FILL, WHITE);
	draw_button(200-75,340-50,200+75,340+50,LIGHTGREEN);
	draw_button(480-75,340-50,480+75,340+50,LIGHTGREEN);//�û������Ա����״ 
	
	puthz(200-30, 330, "�û�", 24, 32, BLACK);	 //�û�
	puthz(480-38, 330, "����Ա", 24, 28, BLACK); //����Ա
	
	ESC_draw();//�˳���ť
}

/**
  * @brief  ��ӭ�����˻��������� 
  			the man-machine interaction of the welcome interface
  * @param  None 
  * @retval the num of page 
  */
int welcome_page(){
	int num = 0;//���ð�ť���
/**
  *     @arg 1:user button
  *     @arg 2:master button 
  *     @arg 3:ESC
  */
	welcome_view();
	mouseinit(); //��ʼ�����
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		
		//�û�����
		if(MouseX>200-75&&MouseX<200+75&&MouseY>340-50&&MouseY<340+50)
		{
			if(mouse_press(200-75,340-50,200+75,340+50) == 2){
				if (num == 0)
				{
					MouseS = 1;
					num = 1;
					button_change(200-75,340-50,200+75,340+50);
				} //�û���ť 
				continue;
			}
			else if(mouse_press(200-75,340-50,200+75,340+50))//�û���ť
			{
				delay(1000);
				return 1;
			}
		}
		
		//����Ա����
		if(MouseX>480-75&&MouseX<480+75&&MouseY>340-50&&MouseY<340+50)
		{
			if(mouse_press(480-75,340-50,480+75,340+50) == 2){
				if (num == 0)
				{
					MouseS = 1;
					num = 2;
					button_change(480-75,340-50,480+75,340+50);
				} //����Ա��ť 
				continue;
			}
			else if(mouse_press(480-75,340-50,480+75,340+50))//�û���ť
			{
                delay(1000);
		     	return 2;
			}
		}
		
		//ESC���� 
		else if(MouseX>600&&MouseX<635&&MouseY>5&&MouseY<40)
		{
			if(mouse_press(600,5,635,40) == 2){
				if (num == 0)
				{
					MouseS = 1;
					num = 3;
					ESC_change();
				} //�˳���ťδ��
				continue;
			}
			else if(mouse_press(600,5,635,40) == 1)//�˳���ť 
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
						ESC_recover();//ҳ��ָ� 
						break;
				}
				num = 0;
			}
			continue;
		}
	}
}


