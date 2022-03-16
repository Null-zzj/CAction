#include<stdio.h>
#include<stdlib.h>
#include<math.h> 
#include<time.h>
#include"Practise1.h"



//实战一的接口函数
void HandlePractise1() {
	int key;
	while (true) {
		key = Practise1Menu();
		switch (key) {
		case 1: isTriangle();   //三角形问题
			break;
		case 2: isTriangleAdd();   //三角形问题(扩展)
			break;
		case 3: sizeyunsuan();  //简单四则运算
			break;
		case 4: sizeyunsuanADD();  //简单四则运算(扩展)
			break;
		case 5: houzichitao();  //猴子吃桃
			break;
		case 6: houzichitaoAdd();  //猴子吃桃(扩展)
			break;
		case 7: caishuyouxi();  //猜数游戏
			break;
		case 8: return;         //返回上一级
		case 9: exit(0);		//退出程序
		}

		

	}

}

//实战一菜单界面
static int Practise1Menu() {
	int key;
	printf("---------项目实战----------\n");
	printf("1.三角形问题\n");
	printf("2.三角形问题(扩展面积)\n");
	printf("3.四则运算问题\n");
	printf("4.四则运算问题(扩展幂次方)\n");
	printf("5.猴子吃桃问题\n");
	printf("6.猴子吃桃问题(扩展新)\n");
	printf("7.拓展项目(猜数游戏)\n");
	printf("8.返回上一级\n");
	printf("9.退出程序\n");
	printf("输入相应数字开始相应实战\n");
	scanf("%d", &key);
	return key;

}

//***********************************************************
static void isTriangle() {    //三角形问题
	double a, b, c;
	printf("请输入三个大于0的实数:(以空格隔开)\n");
	scanf("%lf%lf%lf", &a, &b, &c);
	
	if ((a + b) > c && (b + c) > a && (a + c) > b) {
		printf("能构成三角形\n");
	}
	else {
		printf("不能构成三角形\n");
	}
}
static void isTriangleAdd() {    //扩展,求面积
	double a, b, c;
	printf("请输入三个大于0的实数:(以空格隔开)\n");
	scanf("%lf%lf%lf", &a, &b, &c);
	double p = (a + b + c) / 2;
	if ((a + b) > c && (b + c) > a && (a + c) > b) {
		double p = (a + b + c) / 2;
		double s = sqrt(p*(p - a)*(p - b)*(p - c));
		printf("能构成三角形\n面积为:");
		printf("%.2lf",s);
	}
	else {
		printf("不能构成三角形\n");
	}


}

//**************************************************************
static void sizeyunsuan() { //简单四则运算
	int a, b;
	char key,answer = 'y';
	
	do{
		printf("-------简易计算器------\n");
		printf("输入将要两个运算数和操作符\n");
		scanf("%d%c%d", &a, &key, &b);
		switch (key)
		{
		case '+': printf("%d + %d = %d\n", a, b, a + b);
			break;
		case '-': printf("%d - %d = %d\n", a, b, a - b);
			break;
		case '*': printf("%d * %d = %d\n", a, b, a * b);
			break;
		case '/': printf("%d / %d = %d\n", a, b, a / b);
			break;
		default:printf("输入错误的运算符,请重新输入\n");
			break;
		}
		printf("是否需要再次计算,如果需要,键入y,否则n\n");
		getchar();
		scanf("%c", &answer);
	} while (answer == 'y');
}
//简单四则运算扩展  求幂次方
static void sizeyunsuanADD() {
	int i = 0,a, b,c;
	
	char key, answer = 'y';

	do {
		printf("-------简易计算器------\n");
		printf("输入将要两个运算数和操作符\n");
		scanf("%d%c%d", &a, &key, &b);
		
		switch (key)
		{
		case '+': printf("%d + %d = %d\n", a, b, a + b);
			break;
		case '-': printf("%d - %d = %d\n", a, b, a - b);
			break;
		case '*': printf("%d * %d = %d\n", a, b, a * b);
			break;
		case '/': printf("%d / %d = %d\n", a, b, a / b);
			break;
		case '^': {
			c = a;
			for (i = 1; i < b; i++) {
			a = a * c;
			}
				printf("%d ^ %d = %d\n",c,b,a);
		}
			break;
		default:printf("输入错误的运算符,请重新输入\n");
			break;
		}
		printf("是否需要再次计算,如果需要,键入y,否则n\n");
		getchar();
		scanf("%c", &answer);
	} while (answer == 'y');
}


//*************************************************************
static void houzichitao() {    //猴子吃桃
	long long count = 1,n;
	printf("请输入猴子在第几天还剩1个桃子\n");
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		count = (count + 1) * 2;
	}
	printf("猴子第一天共摘了%lld个桃子\n",count);
}
//猴子吃桃扩展
static void houzichitaoAdd() {
	int n = 10,count = 1;
	for (int i = 1; i < n; i++) {
		count = (count + 1) * (count + 1);
	}
	printf("猴子第一天共摘了%d个桃子\n", count);
}





//拓展项目 猜数游戏
static void caishuyouxi(){
	srand(time(0));
	int answer = rand() % 10;
	int count;
	printf("请输入你要猜的数:(范围0-10)\n");
	while (true) {
		scanf("%d", &count);
		if (count > answer) {
			printf("你猜的数大了.\n");
		}
		else if (count < answer) {
			printf("你猜的数小了.\n");
		}
		else {
			printf("答案正确这个数是%d.\n",answer);
			return;
		}
	}
}

