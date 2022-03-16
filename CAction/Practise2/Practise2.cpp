#include<stdio.h>
#include<stdlib.h>
#include<math.h> 
#include<time.h>
#include"Practise2.h"

int m = 0;

//实战二的接口函数
void HandlePractise2() {
	int key;
	while (true) {
		key = Practise2Menu();
		switch (key) {
		case 1: jiecheng();              //阶乘
			break;
		case 2:  fib();                  //斐波那契数列
			break;
		case 3: houzichitao();           //猴子吃桃
			break;
		case 4: houzichitaoAdd();        //猴子吃桃(扩展)
				break;
		case 5: hannuota();              //汉诺塔
				break;
			case 6: hannuotaAdd();    //汉诺塔(扩展)
				break;
		case 7: zoulouti();              //走楼梯
			break;
		case 8: return;         //返回上一级
		case 9: exit(0);		//退出程序
		
		}
	}

}
//实战二菜单界面
static int Practise2Menu() {
	int key;
	printf("---------项目实战----------\n");
	printf("1.阶乘\n");
	printf("2.斐波那契数列\n");
	printf("3.猴子吃桃\n");
	printf("4.猴子吃桃(扩展)\n");
	printf("5.汉诺塔\n");
	printf("6.汉诺塔(拓展)\n");
	printf("7.拓展项目\n");
	printf("8.返回上一级\n");
	printf("9.退出程序\n");
	printf("输入相应数字开始相应实战\n");
	scanf("%d", &key);
	return key;
}
//**********************************************
static void jiecheng() {  //阶乘
	int i;
	printf("请输入一个整数进行阶乘运算\n");
	scanf("%d", &i);
	printf("%d的阶乘是%d\n", i, jiecheng1(i));
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
static void fib() {  //斐波那契数列
	int n;
	printf("输入需要第几项数\n");
	scanf("%d", &n);
	printf("斐波那契数列第%d项是%d\n\n", n, fib1(n));
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
static void houzichitao() {  //猴子吃桃
	int n = 10, sum = 0;
	printf("请输入猴子吃桃子的天数(默认为10)\n");
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
//猴子吃桃拓展
static void houzichitaoAdd() {
	int n = 10, sum = 0;
	printf("请输入猴子吃桃子的天数(默认为10)\n");
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
static void hannuota() {         //汉诺塔
	int n;
	m = 0;
	printf("请输入汉诺塔的层数:\n");
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
static void hannuotaAdd() {      //汉诺塔扩展
	int n;
	printf("请输入汉诺塔的层数:\n");
	scanf("%d", &n);
	hannuota1(n, 'A', 'B', 'C');
}
void hannuota1Add(int n, char A, char B, char C) {
	if (n == 1)     //退出递归 
	{
		if (abs(A - C) == 1)  //相邻柱 
		{
			m++;
			printf("第%d步: %c->%c\n", m, A, C);
		}
		if (abs(A - C) == 2)  //非相邻柱 
		{
			m++;
			printf("第%d步: %c->%c\n", n, A, B);
			m++;
			printf("第%d步: %c->%c\n", n, B, C);
		}
	}
	else                //递归调用 
	{
		hannuota1Add(n - 1, A, B, C);
		hannuota1Add(1, A, C, B);
		hannuota1Add(n - 1, C, B, A);
		hannuota1Add(1, B, A, C);
		hannuota1Add(n - 1, A, B, C);
	}
}
//******************************************************************************
void zoulouti() {//走楼梯
	printf("为题 一楼梯共有n级,每次走一级或两级,共有多少种走法\n");
	int i; m = 0;
	printf("请输入楼梯共有几层\n");
	scanf("%d", &i);
	zoulouti1(i,0);
	printf("走%d层共有%d种走法\n",i,m);
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
