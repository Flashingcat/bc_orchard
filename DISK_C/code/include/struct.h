/**
  ******************************************************************************
  * @file   struct.h
  * @brief   This file provides all structure
  ******************************************************************************
  */
#ifndef _struct_H_
#define _struct_H_

typedef struct Working//封装员工工作绩效
{      
	char work_time[15];	//本月工作时间
	int salary;         //本月应付薪水
	char record[20];	//最近一次工作记录
	char rate[2];		//员工绩效评价
}Working;

typedef struct User//封装员工信息
{
    Working worker;     //对应员工绩效	
	char ID[20];		//18位，身份证
	char password[20];	//8-16位，密码
	char telephone[15];	//11位，电话号码
	char name[20];		//用户名
}User;

typedef struct Admin//封装管理员信息
{	   	
	char password[20];	//8-16位，密码
	char telephone[15];	//11位，电话号码
	char name[20];		//用户名
}Admin;

typedef struct Fruit//封装采摘林果信息
{
	char name[10];		    //水果名称
	char date[15];		    //采摘日期
	int weight;		        //果重
	char description[20];	//描述
	char rate[2];		    //水果评级
}Fruit;

typedef struct Fruit_list//采摘林果的链表
{
	struct Fruit_list *next;//指向下一个林果
	int num;				//林果数量
	Fruit fruit;			//林果特征
}Fruit_node;

typedef struct Mail//封装信息
{
	char tittle[30];	//信息标题
	char content[201];	//信息内容
	char time[20];		//信息发送时间
	int reading;		//判断是否已读参数
	int sender;         //确定发送信息者是系统，管理员还是其他员工
}MAIL;

#endif
