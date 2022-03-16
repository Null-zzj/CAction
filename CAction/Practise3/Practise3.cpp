#include<stdio.h>
#include<stdlib.h>
#include<math.h> 
#include<time.h>
#include"Practise3.h"

//实战三 的接口函数
void HandlePractise3() {
	int key;
	while (true) {
		key = Practise3Menu();
		switch (key) {
		//case 1: jiecheng();              //阶乘
		//	break;
		//case 2:  fib();                  //斐波那契数列
		//	break;
		//case 3: houzichitao();           //猴子吃桃
		//	break;
		//case 4: houzichitaoAdd();        //猴子吃桃(扩展)
		//	break;
		//case 5: hannuota();              //汉诺塔
		//	break;
		//case 6: hannuotaAdd();    //汉诺塔(扩展)
		//	break;
		//case 7: zoulouti();              //走楼梯
		//	break;
		case 8: return;         //返回上一级
		case 9: exit(0);		//退出程序

		}
	}

}
//实战三菜单界面
static int Practise3Menu() {
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