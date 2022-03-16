#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<conio.h> 
#include<string.h>
#define N2 3
#define IDLen 13
#define NameLen 11
#define SexLen 5
//存储学生成绩的结构体
struct Score {
	int cp;
	int en;
	int math;
};

typedef struct Stu {
	char id[IDLen];           //学号
	char name[NameLen];       //姓名
	char sex[SexLen];         //性别
	int age;                  //年龄
	struct Score score;       //储存成绩的结构体
	double avg;               //平均分
}Student;



void studentmessage();        //实战接口
void InputStudent();          //输人学生信息的操作

void DisplayMenu();           //显示选择菜 单

void GetOrderDir();           //显示用户选择排序方向

void SortStudent();           //对学生信息stu[]进行排序, 结果存人sorted[]中 
void OutputStudent(Student s[]); //输出学生信息
