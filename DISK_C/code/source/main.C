#include"common.h"
#include"main.h"

void main(){

	int page = WELCOME;//��ʼ���� 

	int gdriver = VGA;
	int gmode = VGAHI;


	initgraph(&gdriver, &gmode, "C:\\BORLANDC\\BGI"); //��ʼ��ͼ�ν���640*480


	while (1)
	{
		switch (page)
		{
		case WELCOME://�����ʼ���� 
			page = welcome_page();
			break;
		}
	}
	return 0;
}