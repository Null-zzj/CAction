#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<conio.h> 
#include<string.h>
#define N2 3
#define IDLen 13
#define NameLen 11
#define SexLen 5
//�洢ѧ���ɼ��Ľṹ��
struct Score {
	int cp;
	int en;
	int math;
};

typedef struct Stu {
	char id[IDLen];           //ѧ��
	char name[NameLen];       //����
	char sex[SexLen];         //�Ա�
	int age;                  //����
	struct Score score;       //����ɼ��Ľṹ��
	double avg;               //ƽ����
}Student;



void studentmessage();        //ʵս�ӿ�
void InputStudent();          //����ѧ����Ϣ�Ĳ���

void DisplayMenu();           //��ʾѡ��� ��

void GetOrderDir();           //��ʾ�û�ѡ��������

void SortStudent();           //��ѧ����Ϣstu[]��������, �������sorted[]�� 
void OutputStudent(Student s[]); //���ѧ����Ϣ
