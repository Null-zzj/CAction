#pragma once
#include<stdio.h>
#include<conio.h>   //getch
#include<string.h>  //字符串处理
#include<malloc.h>  //malloc()
#include<stdlib.h>  //exit()

#define IdLEN 10
#define nameLEN 10
typedef struct person {
	struct person* prior;        //指向上一个表
	int numeral;
	char Id[IdLEN];
	char name[nameLEN];
	struct person* next;		//指向下一个表
}person;                 //客户信息




void bankAappointmentAsystem();//接口
bool addMessage();         //输入客户信息
void checkList();         //查看客户队列
bool deleMessage();       //删除队列
bool alterMessage();      //修改信息
void call();              //呼叫用户
void sort(int j);         //链表序列整理函数
bool judge(char id[]);    //判断输入Id是否与之前输入的Id是否相同