#include"common.h"
#include"log.h"

/***********************************************
函数：void draw_user(char flag)
作用：绘制其他人员登录界面
***********************************************/
void draw_user(char flag)
{
	clrmous(MouseX,MouseY);
	delay(10);
	cleardevice();
	setbkcolor(GREEN);
	puthz(170,50,"员工登录",32,50,WHITE);
	setfillstyle(1,DARKGRAY);
	bar(60,160,180,200);
	bar(60,160+60,180,200+60);
	bar(60,160+120,180,200+120);
	setfillstyle(1,WHITE);
	bar(180,160,180+400,200);
	bar(180,220,180+400,260);
	bar(180,280,180+400,320);
	setlinestyle(0,0,3);
	setcolor(DARKGRAY);
	line(60,160,580,160);
	line(60,200,580,200);
	line(60,160,60,200);
	line(580,160,580,200);
	line(60,220,580,220);
	line(60,260,580,260);
	line(60,220,60,260);
	line(580,220,580,260);
	line(60,280,580,280);
	line(60,320,580,320);
	line(60,280,60,320);
	line(580,280,580,320);
	puthz(70,170,"身份证号",24,24,WHITE);
	puthz(90,230,"账号",24,24,WHITE);
	puthz(90,290,"密码",24,24,WHITE);
	draw_button(60,330,210,360,7);
	draw_button(440,330,540,360,7);
	draw_button(280,400,360,440,7);
	draw_button(300,330,400,360,7);
	draw_button(580,0,640,30,WHITE);
	puthz(80,335,"身份证号注册",16,16,WHITE);
	puthz(320,335,"记住密码",16,16,WHITE);
	puthz(460,335,"忘记密码",16,16,WHITE);
	puthz(290,407,"登录",24,32,WHITE);
	puthz(590,5,"返回",16,16,DARKGRAY);
	if(flag=='1')
	    setfillstyle(1,RED);
    else
		setfillstyle(1,WHITE);
 	sector(280,345,0,360,10,10);
}


/***********************************************
函数：void draw_admin(void)
作用：绘制管理员登录界面
***********************************************/
void draw_admin(void)
{
	clrmous(MouseX,MouseY);
	delay(10);
	cleardevice();
	setbkcolor(RED);
	puthz(190,60,"管理员登录",32,50,WHITE);
	setfillstyle(1,DARKGRAY);
	bar(60,200,180,240);
	bar(60,160+120,180,200+120);
	setfillstyle(1,WHITE);
	bar(180,200,180+400,240);
	bar(180,280,180+400,320);
	setlinestyle(0,0,3);
	setcolor(DARKGRAY);
	line(60,200,580,200);
	line(60,240,580,240);
	line(60,200,60,240);
	line(580,200,580,240);
	line(60,280,580,280);
	line(60,320,580,320);
	line(60,280,60,320);
	line(580,280,580,320);
	puthz(85,210,"用户名",24,24,WHITE);
	puthz(90,290,"密码",24,24,WHITE);
	draw_button(280,400,360,440,7);
	draw_button(580,0,640,30,WHITE);
	puthz(290,407,"登录",24,32,WHITE);
	puthz(590,5,"返回",16,16,DARKGRAY);
}


/***********************************************
函数：int user_log(User *u)
作用：员工登录
***********************************************/
int user_log(User *u)
{   draw_user('1');
	getchar();
	return 0;
	/*char  flag;
	int i,len;
	cleardevice();
	clrmous(MouseX,MouseY);
	delay(100);
	memset(u,0,sizeof(User));
	get_u_recode(&flag,u);
	draw_user(flag);
	
	if(flag=='1')                                     //若flag为1，则
	{
		settextjustify(LEFT_TEXT,TOP_TEXT);
	    settextstyle(3,0,3);
	    setcolor(DARKGRAY);
		outtextxy(190,160,u->ID);
		outtextxy(190,220,u->name);
		len = strlen(u->password);
		for(i=0;i<len;i++)
		{	
		    outtextxy(190+15*i,280,"*");
		}
	}
	
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if(MouseS!=0)
			MouseS=0;
		if(MouseX>=180&&MouseX<=180+400&&MouseY>=160&&MouseY<=200)//身份证号输入
		{
			if(mouse_press(180,160,180+400,200)==2)
			{
				MouseS=2;
				continue;
			}
			else if(mouse_press(180,160,180+400,200)==1)
			{
				MouseS=0;
				u->ID[0] = '\0';
				in_visible2(180,160,18,18,400,40,u->ID,'X');  
				if(judge_ID1(u->ID)==0)
				{
					clearinput(180,160,400,40,u->ID);
					puthz(180,160,"未注册",32,32,RED);
				}
				continue;					
			}
		}
		
		else if(MouseX>=180&&MouseX<=180+400&&MouseY>=220&&MouseY<=260)//账号输入
		{
			if(mouse_press(180,220,180+400,260)==2)
			{
				MouseS=2;
				continue;
			}
			else if(mouse_press(180,220,180+400,260)==1)
			{
				MouseS=0;
				u->name[0] = '\0';
				in_visible1(180,220,10,1,400,40,u->name);  
				continue;					
			}
		}
		
		else if(MouseX>=180&&MouseX<=180+400&&MouseY>=280&&MouseY<=320)//密码输入
		{
			if(mouse_press(180,280,180+400,320)==2)
			{
				MouseS=2;
				continue;
			}
			else if(mouse_press(180,280,180+400,320)==1)
			{
				MouseS=0;
				u->password[0] = '\0';
				in_hidden(180,280,16,8,400,40,u->password);  
				continue;					
			}
		}
		
		else if(MouseX>=60&&MouseX<=210&&MouseY>=330&&MouseY<=360)//注册
		{
			if(mouse_press(60,330,210,360)==2)
			{
				MouseS=1;
				continue;
			}
			else if(mouse_press(60,330,210,360)==1)
			{
				push_button(60,330,210,360);
				*ppage=5;
				re_button(60,330,210,360);
				clrmous(MouseX,MouseY);
				delay(100);
				return;					
			}
		}
		
		else if(MouseX>=300&&MouseX<=400&&MouseY>=330&&MouseY<=360)//记住密码
		{
			if(mouse_press(300,330,400,360)==2)
			{
				MouseS=1;
				continue;
			}
			else if(mouse_press(300,330,400,360)==1)
			{
				push_button(300,330,400,360);				
				re_button(300,330,400,360);
				if(flag=='1')
				{
					flag='0';
					setfillstyle(1,WHITE);
					sector(280,345,0,360,10,10);
				}
                else
                {
                    flag='1';
                    setfillstyle(1,RED);
                    sector(280,345,0,360,10,10);
                }					
			}
		}
		
		else if(MouseX>=440&&MouseX<=540&&MouseY>=330&&MouseY<=360)//忘记密码
		{
			if(mouse_press(440,330,540,360)==2)
			{
				MouseS=1;
				continue;
			}
			else if(mouse_press(440,330,540,360)==1)
			{
				push_button(440,330,540,360);
				*ppage=6;
				re_button(440,330,540,360);
				clrmous(MouseX,MouseY);
				delay(100);
				return;					
			}
		}
		
		else if(MouseX>=280&&MouseX<=360&&MouseY>=400&&MouseY<=440)//登录
		{
			if(mouse_press(280,400,360,440)==2)
			{
				MouseS=1;
				continue;
			}
			else if(mouse_press(280,400,360,440)==1)
			{
				push_button(280,400,360,440);
				re_button(280,400,360,440);
				if(judge_ID2(u)==1)
				{
					save_u_recode(flag,u);
					if(flag=='0')
						 clear_u_recode();
					*ppage=7;
					clrmous(MouseX,MouseY);
					delay(100);
					return;
				}
				else
				{
					clrmous(MouseX,MouseY);
					setcolor(LIGHTGRAY);
					bar(160,120,480,360);
					setlinestyle(0,0,3);
					setcolor(DARKGRAY);
					line(160,120,480,120);
					line(160,360,480,360);
					line(160,120,160,360);
					line(480,120,480,360);
					puthz(250,230,"输入错误",32,32,BLUE);
					delay(2000);
					*ppage = 2;
					return;
				}
			}
		}
		
		else if(MouseX>=580&&MouseX<=640&&MouseY>=0&&MouseY<=30)//退出
		{
			if(mouse_press(580,0,640,30)==2)
			{
				MouseS=1;
				continue;
			}
			else if(mouse_press(580,0,640,30)==1)
			{
				push_button(580,0,640,30);
				*ppage=1;
				re_button(580,0,640,30);
				clrmous(MouseX,MouseY);
				delay(100);
				return;					
			}
		}
	}*/
}


/***********************************************
函数：int admin_log(void)
作用：管理员登录
***********************************************/
int admin_log(void)
{   
    draw_admin();
	getchar();
	return 0;
	/*char name[10];
	char password[15];
	
	cleardevice();
	clrmous(MouseX,MouseY);
	delay(100);
	draw_admin();	
	
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if(MouseS!=0)
			MouseS=0;
		if(MouseX>=180&&MouseX<=180+400&&MouseY>=200&&MouseY<=240)//用户名输入
		{
			if(mouse_press(180,200,180+400,240)==2)
			{
				MouseS=2;
				continue;
			}
			else if(mouse_press(180,200,180+400,240)==1)
			{
				name[0] = '\0';
				in_visible1(180,200,9,1,400,40,name);
				continue;					
			}
		}
		
		else if(MouseX>=180&&MouseX<=180+400&&MouseY>=280&&MouseY<=320)//密码输入
		{
			if(mouse_press(180,280,180+400,320)==2)
			{
				MouseS=2;
				continue;
			}
			else if(mouse_press(180,280,180+400,320)==1)
			{
				password[0] = '\0';
				in_hidden(180,280,16,4,400,40,password);
				continue;					
			}
		}
		
		else if(MouseX>=280&&MouseX<=360&&MouseY>=400&&MouseY<=440)//登录
		{
			if(mouse_press(280,400,360,440)==2)
			{
				MouseS=1;
				continue;
			}
			else if(mouse_press(280,400,360,440)==1)
			{
				push_button(280,400,360,440);
				re_button(280,400,360,440);
				if(strcmp(name,"a")==0 && strcmp(password,"123456")==0)
				{
					*ppage=8;
					clrmous(MouseX,MouseY);
					delay(100);
					return;	
				}
				else
				{
					setcolor(LIGHTGRAY);
					bar(160,120,480,360);
					setlinestyle(0,0,3);
					setcolor(DARKGRAY);
					line(160,120,480,120);
					line(160,360,480,360);
					line(160,120,160,360);
					line(480,120,480,360);
					puthz(250,230,"输入错误",32,32,RED);
					delay(2000);
					clrmous(MouseX,MouseY);
					delay(100);
					draw_admin();
					continue;
				}				
			}
		}
		
		else if(MouseX>=580&&MouseX<=640&&MouseY>=0&&MouseY<=30)//退出
		{
			if(mouse_press(580,0,640,30)==2)
			{
				MouseS=1;
				continue;
			}
			else if(mouse_press(580,0,640,30)==1)
			{
				push_button(580,0,640,30);
				*ppage=1;
				re_button(580,0,640,30);
				return;					
			}
		}
		
	}*/
}

