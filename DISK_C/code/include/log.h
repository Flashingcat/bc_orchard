#ifndef _log.h_
#define _log.h_
#include "struct.h"
int user_log(User *worker);//员工登录控制函数
void draw_user(char flag);//绘制其他人员登录界面
int admin_log(void);//管理员登录控制函数
void draw_admin(void);//绘制管理员登录界面
#endif