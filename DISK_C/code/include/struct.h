/**
  ******************************************************************************
  * @file   struct.h
  * @brief   This file provides all structure
  ******************************************************************************
  */
#ifndef _struct_H_
#define _struct_H_

typedef struct Working//��װԱ��������Ч
{      
	char work_time[15];	//���¹���ʱ��
	int salary;         //����Ӧ��нˮ
	char record[20];	//���һ�ι�����¼
	char rate[2];		//Ա����Ч����
}Working;

typedef struct User//��װԱ����Ϣ
{
    Working worker;     //��ӦԱ����Ч	
	char ID[20];		//18λ�����֤
	char password[20];	//8-16λ������
	char telephone[15];	//11λ���绰����
	char name[20];		//�û���
}User;

typedef struct Admin//��װ����Ա��Ϣ
{	   	
	char password[20];	//8-16λ������
	char telephone[15];	//11λ���绰����
	char name[20];		//�û���
}Admin;

typedef struct Fruit		//��װ��ժ�ֹ���Ϣ
{
	int num;				//����
	int weight;		        //����
	char* description;		//����
	char* rate;		    	//ˮ������
}Fruit;

typedef struct Fruit_list	//��ժһ���ֹ�������
{
	struct Fruit_list *next;
	int last_month;			//����ʱ��
	int first_data;			//��ժʱ��
	Fruit fruit;		   	//ˮ����Ϣ
}Fruit_node;

typedef struct kind_list	//���Ե��ֹ�
{
	struct kind_list *next; //ָ����һ���ֹ�
	char name[10];		    //ˮ������
	int time;				//�ȱ������β�ժ��¼
	int num;				//�ֹ�����
	Fruit_node* fruit_list;	//�ֹ���ժ����
}kind_node;

typedef struct Mail//��װ��Ϣ
{
	char tittle[30];	//��Ϣ����
	char content[201];	//��Ϣ����
	char time[20];		//��Ϣ����ʱ��
	int reading;		//�ж��Ƿ��Ѷ�����
	int sender;         //ȷ��������Ϣ����ϵͳ������Ա��������Ա��
}MAIL;

#endif
