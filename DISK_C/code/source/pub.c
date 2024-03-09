/**************************************
函数名：draw_button
输入参数：x,y,x1,y1,color
函数描述：绘制矩形按钮
返回值：无
****************************************/
void draw_button(int x,int y,int x1,int y1,int color)
{
	setfillstyle(1,color);
	bar(x,y,x1,y1);
	setlinestyle(0,0,3);
	setcolor(WHITE);
	line(x-1,y-1,x1+1,y-1);
	line(x-1,y-1,x-1,y1+1);
	setcolor(DARKGRAY);
	line(x1+1,y1+1,x1+1,y-1);
	line(x1+1,y1+1,x-1,y1+1);
}



/**************************************
函数名：push_button
输入参数：x,y,x1,y1
函数描述：绘制矩形按钮按下后的动态感
返回值：无
****************************************/
void push_button(int x,int y,int x1,int y1)
{
	setlinestyle(0,0,3);
	setcolor(DARKGRAY);
	line(x-1,y-1,x1+1,y-1);
	line(x-1,y-1,x-1,y1+1);
	setcolor(WHITE);
	line(x1+1,y1+1,x1+1,y-1);
	line(x1+1,y1+1,x-1,y1+1);
	delay(500);
}



/**************************************
函数名：re_button
输入参数：x,y,x1,y1
函数描述：恢复矩形按钮
返回值：无
****************************************/
void re_button(int x,int y,int x1,int y1)
{
	setlinestyle(0,0,3);
	setcolor(WHITE);
	line(x-1,y-1,x1+1,y-1);
	line(x-1,y-1,x-1,y1+1);
	setcolor(DARKGRAY);
	line(x1+1,y1+1,x1+1,y-1);
	line(x1+1,y1+1,x-1,y1+1);
	delay(100);
}



/*********************************************
 函数名:refram 
 输入参数:x,y,length,wide 
 函数描述：绘制输入框 
 返回值:无 
 ***********************************************/
void refram(int x,int y,int length,int wide)
{
	setlinestyle(0,0,3);
	setcolor(DARKGRAY);
	line(x,y,x+length,y);
	line(x,y,x,y+wide);
	line(x+length,y,x+length,y+wide);
	line(x,y+wide,x+length,y+wide);
}



/*********************************************
 函数名:in_visible1 
 输入参数:x,y,max,min,length,wide,con
 函数描述：输入不需要隐藏的信息(不限输入内容) 
 返回值:无 
 ***********************************************/
void in_visible1(int x,int y,int max,int min,int length, int wide,char *con)
{
	long j=0;
	int flag=0;
	int i=0;
	int size;
	char c;
	clrmous(MouseX, MouseY);
	setfillstyle(1,WHITE);
	bar(x,y,x+length,y+wide);
	setcolor(DARKGRAY);
	settextjustify(LEFT_TEXT,TOP_TEXT);//前期准备，规定对齐方式
	if(length<300)
	{
		settextstyle(3,0,2);
		size = 14;
	}
	else 
	{
		settextstyle(3,0,3);
		size = 16;
	}
	while(bioskey(1))
	{
		bioskey(0);
	}
	while(1)
	{
		if(kbhit())
		{
			j=0;
			bar(x+size/4+i*size,y,x+size/2+i*size,y+wide);
			c=bioskey(0);
			if(c!='\n'&&c!='\r'&&c!=' '&&c!='m')//不输入回车和空格时
			{
				if(i<max)
				{
					if(c!='\b')//不输入退格键时
					{
						*(con+i)=c;
						*(con+i+1)='\0';
						outtextxy(x+size/2+i*size,y,con+i);//输入值
						i++;
					}
					else if(c=='\b'&&i>0)//输入退格键
					{
						*(con+i-1)='\0';
						bar(x-size/2+i*size,y,x+size/2+i*size,y+wide);//遮盖文字
						i--;
					}
				}
				else if(i>=max)
				{
					if(c=='\b'&&i>0)
					{
						*(con+i-1)='\0';
						bar(x-size/2+i*size,y,x+size/2+i*size,y+wide);//遮盖文字
						i--;
					}
					else
					{
						continue;
					}
				}
			}
			else if(c=='\r'||c=='\n')//输入回车时
			{
				if(i<min)
				{
					bar(x,y,x+length,y+wide);
					puthz(x+length-50,y+3,"过短",24,24,LIGHTGRAY);
					con[0]='\0';
					break;
				}
				else
				{
					refram(x,y,length,wide);
					break;
				}
			}
			else if(c == ' ' || c == 'm')//输入空格时
				continue;
		}
		else
		{
	        if(j==0)
			{
				outtextxy(x+size/4+i*size,y,"|");
				flag=0;
				delay(100);
				setfillstyle(1,WHITE);
			    bar(x+size/4+i*size,y,x+size/2+i*size,y+wide);
		    }
			j++;
			if(j>300000)
			{
				j=1;
				if(flag==0)
				{
				    setfillstyle(1,WHITE);
			        bar(x+size/4+i*size,y,x+size/2+i*size,y+wide);
					flag=1;
				}
				else 
				{
					outtextxy(x+size/4+i*size,y,"|");
					flag=(flag+1)%3;
				}
			}
		}
	}
}




void in_hidden(int x,int y,int max, int min,int length,int wide,char *con)
{
	long j=0;
	int i=0;
	int flag=0;
	char c;
	clrmous(MouseX, MouseY);
	setfillstyle(1,WHITE);
	bar(x,y,x+length,y+wide);
	setcolor(DARKGRAY);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	settextstyle(3,0,3);
	while(bioskey(1))
	{
		bioskey(0);
	}
	while(1)
	{
		if(kbhit())
		{
			j=0;
			bar(x+4+i*16,y,x+8+i*16,y+wide);
			c=bioskey(0);
			if(c!='\n'&&c!='\r'&&c!=' '&&c!='m')
			{
				if(i<max)
				{
					if(c!='\b')
					{
						*(con+i)=c;
						*(con+i+1)='\0';
						outtextxy(x+8+i*16,y,con+i);
						delay(100);
						bar(x+8+i*16,y,x+19+i*16,y+wide);
						delay(10);
						outtextxy(x+8+i*16,y,"*");//输入*
						i++;
					}
					else if(c=='\b'&&i>0)//输入退格键
					{
						*(con+i-1)='\0';
						bar(x-8+i*16,y,x+8+i*16,y+wide);//遮盖
						i--;
					}
				}
				else if(i>=max)
				{
					if(c=='\b'&&i>0)
					{
						*(con+i-1)='\0';
						bar(x-8+i*16,y,x+8+i*16,y+wide);//遮盖
						i--;
					}
					else
					{
						continue;
					}
				}	
			}
			else if(c=='\r'||c=='\n')
			{			
				if(i<min)
				{
					bar(x,y,x+length,y+wide);
					puthz(500,y+3,"过短",24,24,LIGHTGRAY);
					con[0]='\0';
					break;
				}
				else
				{
					refram(x,y,length,wide);
					break;
				}
			}
			else if(c == ' ' || c == 'm')
				continue;
		}
		else
		{
	        if(j==0)
			{
				outtextxy(x+4+i*16,y,"|");
				flag=0;
				delay(100);
				setfillstyle(1,WHITE);
			    bar(x+4+i*16,y,x+8+i*16,y+wide);
		    }
			j++;
			if(j>300000)
			{
				j=1;
				if(flag==0)
				{
				    setfillstyle(1,WHITE);
			        bar(x+4+i*16,y,x+8+i*16,y+wide);
					flag=1;
				}
				else 
				{
					outtextxy(x+4+i*16,y,"|");
					flag=(flag+1)%3;
				}
			}
		}
	}
}



/*********************************************
 函数名:clearinput 
 输入参数:x,y,length,wide,a
 函数描述：清除已输入的信息
 返回值:无 
 ***********************************************/
void clearinput (int x,int y,int length,int wide,char *a)
{
	setfillstyle(1,WHITE);
	bar(x,y,x+length,y+wide);//用白色遮盖x之后length个像素
	a[0]='\0';
}
