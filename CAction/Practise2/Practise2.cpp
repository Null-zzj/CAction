#include<stdio.h>
#include<stdlib.h>
#include<math.h> 
#include<time.h>
#include"Practise2.h"

int m = 0;

//ʵս���Ľӿں���
void HandlePractise2() {
	int key;
	while (true) {
		key = Practise2Menu();
		switch (key) {
		case 1: jiecheng();              //�׳�
			break;
		case 2:  fib();                  //쳲���������
			break;
		case 3: houzichitao();           //���ӳ���
			break;
		case 4: houzichitaoAdd();        //���ӳ���(��չ)
				break;
		case 5: hannuota();              //��ŵ��
				break;
			case 6: hannuotaAdd();    //��ŵ��(��չ)
				break;
		case 7: zoulouti();              //��¥��
			break;
		case 8: return;         //������һ��
		case 9: exit(0);		//�˳�����
		
		}
	}

}
//ʵս���˵�����
static int Practise2Menu() {
	int key;
	printf("---------��Ŀʵս----------\n");
	printf("1.�׳�\n");
	printf("2.쳲���������\n");
	printf("3.���ӳ���\n");
	printf("4.���ӳ���(��չ)\n");
	printf("5.��ŵ��\n");
	printf("6.��ŵ��(��չ)\n");
	printf("7.��չ��Ŀ\n");
	printf("8.������һ��\n");
	printf("9.�˳�����\n");
	printf("������Ӧ���ֿ�ʼ��Ӧʵս\n");
	scanf("%d", &key);
	return key;
}
//**********************************************
static void jiecheng() {  //�׳�
	int i;
	printf("������һ���������н׳�����\n");
	scanf("%d", &i);
	printf("%d�Ľ׳���%d\n", i, jiecheng1(i));
}
int jiecheng1(int i) {
	if ((i == 0) || (i == 1)) {
		return 1;
	}
	else {
		return i * jiecheng1(i - 1);
	}
}


//**********************************************
static void fib() {  //쳲���������
	int n;
	printf("������Ҫ�ڼ�����\n");
	scanf("%d", &n);
	printf("쳲��������е�%d����%d\n\n", n, fib1(n));
}
int fib1(int n) {
	if (n == 1 || n == 0) {
		return n;
	}
	else {
		return fib1(n - 1) + fib1(n - 2);
	}
}

//************************************************
static void houzichitao() {  //���ӳ���
	int n = 10, sum = 0;
	printf("��������ӳ����ӵ�����(Ĭ��Ϊ10)\n");
	scanf("%d", &n);
	printf("%d", houzichitao1(n, sum));
}
int houzichitao1(int n, int sum) {
	if (sum == n) {
		return 1;
	}
	else {
		return (houzichitao1(n, sum + 1) + 1) * 2;
	}
}
//���ӳ�����չ
static void houzichitaoAdd() {
	int n = 10, sum = 0;
	printf("��������ӳ����ӵ�����(Ĭ��Ϊ10)\n");
	scanf("%d", &n);
	double num;
	num = houzichitao1Add(n, sum);
	printf("%lf\n", &num);
}
double houzichitao1Add(int n, int sum) {
	if (sum == n - 1) {
		return 1;
	}
	else {
		return (houzichitao1Add(n, sum + 1) + 1)* (houzichitao1Add(n, sum + 1) + 1);
	}
}


//*******************************************************************
static void hannuota() {         //��ŵ��
	int n;
	m = 0;
	printf("�����뺺ŵ���Ĳ���:\n");
	scanf("%d", &n);
	hannuota1(n, 'A', 'B', 'C');
}
void hannuota1(int n,char A,char B,char C) {
	if (n == 1) {
		printf("step%d: %c -> %c\n",++m, A, C);
	}
	else {
		hannuota1(n - 1, A, C, B);
		printf("step%d: %c -> %c\n",++m, A,C);
		hannuota1(n - 1, B, A, C);

	}
}

//***************************************************************
static void hannuotaAdd() {      //��ŵ����չ
	int n;
	printf("�����뺺ŵ���Ĳ���:\n");
	scanf("%d", &n);
	hannuota1(n, 'A', 'B', 'C');
}
void hannuota1Add(int n, char A, char B, char C) {
	if (n == 1)     //�˳��ݹ� 
	{
		if (abs(A - C) == 1)  //������ 
		{
			m++;
			printf("��%d��: %c->%c\n", m, A, C);
		}
		if (abs(A - C) == 2)  //�������� 
		{
			m++;
			printf("��%d��: %c->%c\n", n, A, B);
			m++;
			printf("��%d��: %c->%c\n", n, B, C);
		}
	}
	else                //�ݹ���� 
	{
		hannuota1Add(n - 1, A, B, C);
		hannuota1Add(1, A, C, B);
		hannuota1Add(n - 1, C, B, A);
		hannuota1Add(1, B, A, C);
		hannuota1Add(n - 1, A, B, C);
	}
}
//******************************************************************************
void zoulouti() {//��¥��
	printf("Ϊ�� һ¥�ݹ���n��,ÿ����һ��������,���ж������߷�\n");
	int i; m = 0;
	printf("������¥�ݹ��м���\n");
	scanf("%d", &i);
	zoulouti1(i,0);
	printf("��%d�㹲��%d���߷�\n",i,m);
}
int zoulouti1(int i,int n) {
	if (n == i) {
		m++;
	}
	else if(n > i){
		return 0;
	}
	else {
		 zoulouti1(i,n + 1);
		 zoulouti1(i,n + 2);
	}
}
