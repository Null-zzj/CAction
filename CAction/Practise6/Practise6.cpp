#include<stdio.h>
#include<stdlib.h>
#include<math.h> 
#include<time.h>
#include"Practise6.h"
#include"yuesefu/yuesefu.h"
#include"bankAappointmentAsystem/bankAappointmentAsystem.h"


//实战五的接口函数
void HandlePractise6() {
	int key;
	while (true) {
		key = Practise6Menu();
		switch (key) {
		//case 1:    //学生信息表
		//	break;
		//case 2: huochedingpiao();   //火车订票系统
		//	break;
		//case 3: riqijisuan();  //日期计算
		//	break;
		case 4:
			bankAappointmentAsystem();
			break;
		case 5: return;         //返回上一级
		case 0: exit(0);		//退出程序
		}

	}

}

//实战五菜单界面
static int Practise6Menu() {
	int key;
	printf("---------项目实战----------\n");
	printf("1.三角形问题\n");
	printf("2.三角形问题(扩展面积)\n");
	printf("3.四则运算问题\n");
	printf("4.银行排号系统\n");
	printf("5.返回上一级\n");
	printf("0.退出程序\n");
	printf("输入相应数字开始相应实战\n");
	scanf("%d", &key);
	return key;

}