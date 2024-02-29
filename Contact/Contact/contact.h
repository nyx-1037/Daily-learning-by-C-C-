#pragma once


#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30


#define MAX 1000

#define DEFAULT_SZ 3
#define INC_SZ 2


//���͵Ķ���
typedef struct PeoInfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
}PeoInfo;

//ͨѶ¼-��̬�汾
//typedef struct Contact
//{
//	PeoInfo data[MAX];//�����ӽ������˵���Ϣ
//	int sz;//��¼���ǵ�ǰͨѶ¼����Ч��Ϣ�ĸ���
//}Contact;

//��̬�汾
typedef struct Contact
{
	PeoInfo *data;//ָ��̬����Ŀռ䣬���������ϵ�˵���Ϣ
	int sz;//��¼���ǵ�ǰͨѶ¼����Ч��Ϣ�ĸ���
	int capacity;//��¼��ǰͨѶ¼���������
}Contact;


//��ʼ��ͨѶ¼
void InitContact(Contact* pc);

//������ϵ��
void AddContact(Contact* pc);

//��ӡ��ϵ����Ϣ
void PrintContact(const Contact* pc);

//ɾ����ϵ�˵���Ϣ
void DelContact(Contact* pc);

//����ָ����ϵ��
void SearchContact(Contact* pc);

//�޸�ָ����ϵ��
void ModifyContact(Contact* pc);

//����ͨѶ¼
void DestoryContact(Contact* pc);

//����ͨѶ¼��Ϣ���ļ�
void SaveContact(Contact* pc);

//�����ļ����ݵ�ͨѶ¼
void LoadContact(Contact* pc);

//������ݵ�����
void CheckCapacity(Contact* pc);