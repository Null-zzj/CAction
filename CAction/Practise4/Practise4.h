#pragma once
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void HandlePractise4();
static int Practise4Menu();
#define N 5                                    //Լɪ������ȫ�ֱ���
#define LEN1 10 
void YueSeFu();                                //Լɪ������
void JosephProblem(char ary[][LEN1], int K);

void YueSeFuAdd();                             //Լɪ��������չ


void FenLeiTongJi();          //����ͳ��
void Count(char ary[]);

void FenLeiTongJiAdd();       //����ͳ����չ

#define N1 50                 //��������ȫ�ֱ���
#define M1 26
void DanCiPaiYu();            //��������
void WordSort(char word[][M1], int n);
void print(const char word[][M1], int n);

void DanCiPaiYuAdd();         //����������չ
void WordSortAdd(char word[][M1], int n);
void printAdd(const char word[][M1], int n);

void ShuZiChaZhao();          //��չ��Ŀ ���ֲ���