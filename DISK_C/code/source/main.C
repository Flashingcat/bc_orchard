#include"common.h"
#include"main.h"

void main(){

	int page = WELCOME;//初始界面 
    int gdriver = VGA;
	int gmode = VGAHI;
	User *worker=NULL;
	
    worker=(User*)malloc(sizeof(User));

	initgraph(&gdriver, &gmode, "C:\\BORLANDC\\BGI"); //初始化图形界面640*480

	while (1)
	{
		switch (page)
		{
		case WELCOME://进入初始画面 
			{
			    page = welcome_page();
			    break;
			}
		case USER_LOG://进入用户登录画面
		    {
				page=user_log(worker);
                break;
			}
		case ADMIN_LOG://进入管理员登录画面
		    {
				page=admin_log();
                break;
			}
		}
	}
}
