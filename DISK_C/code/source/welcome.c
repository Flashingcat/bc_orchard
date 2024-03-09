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
	bar(200-75,340-50,200+75,340+50);
	bar(480-75,340-50,480+75,340+50);//�û������Ա����״ 
	
	puthz(200-30, 330, "�û�", 24, 32, BLACK);		 //�û�
	puthz(480-38, 330, "����Ա", 24, 28, BLACK); //����Ա

	setfillstyle(SOLID_FILL, WHITE);
	bar(640, 0, 595, 45);
	setlinestyle(0, 0, 3);
	setcolor(BLACK);
	line(635, 5, 600, 40);
	line(635, 5, 600, 5);
	line(635, 5, 635, 40);
	line(600, 40, 635, 40);
	line(600, 40, 600, 5);
	line(600, 5, 635, 40); //�˳���ť
	
	
}

/**
  * @brief  ��ӭ�����˻��������� 
  			the man-machine interaction of the welcome interface
  * @param  None 
  * @retval the num of page 
  */
int welcome_page(){
	int num = 0;//���ð�ť��� 
	welcome_view();
	mouseinit(); //��ʼ�����
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
				button_recover(num);//ҳ��ָ� 
				num = 0;
			}
			continue;
		}
	}
}

/**
  * @brief  �������ť������ť��ɫ�ı���¼�
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
  * @brief  ����뿪�����ð��� 
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
