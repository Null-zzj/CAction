#pragma once
#include<stdio.h>
#include<conio.h>   //getch
#include<string.h>  //�ַ�������
#include<malloc.h>  //malloc()
#include<stdlib.h>  //exit()

#define IdLEN 10
#define nameLEN 10
typedef struct person {
	struct person* prior;        //ָ����һ����
	int numeral;
	char Id[IdLEN];
	char name[nameLEN];
	struct person* next;		//ָ����һ����
}person;                 //�ͻ���Ϣ




void bankAappointmentAsystem();//�ӿ�
bool addMessage();         //����ͻ���Ϣ
void checkList();         //�鿴�ͻ�����
bool deleMessage();       //ɾ������
bool alterMessage();      //�޸���Ϣ
void call();              //�����û�
void sort(int j);         //��������������
bool judge(char id[]);    //�ж�����Id�Ƿ���֮ǰ�����Id�Ƿ���ͬ