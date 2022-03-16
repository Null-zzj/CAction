#pragma once
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void HandlePractise4();
static int Practise4Menu();
#define N 5                                    //约瑟夫问题全局变量
#define LEN1 10 
void YueSeFu();                                //约瑟夫问题
void JosephProblem(char ary[][LEN1], int K);

void YueSeFuAdd();                             //约瑟夫问题扩展


void FenLeiTongJi();          //分类统计
void Count(char ary[]);

void FenLeiTongJiAdd();       //分类统计扩展

#define N1 50                 //单词排序全局变量
#define M1 26
void DanCiPaiYu();            //单词排序
void WordSort(char word[][M1], int n);
void print(const char word[][M1], int n);

void DanCiPaiYuAdd();         //单词排序扩展
void WordSortAdd(char word[][M1], int n);
void printAdd(const char word[][M1], int n);

void ShuZiChaZhao();          //拓展项目 数字查找