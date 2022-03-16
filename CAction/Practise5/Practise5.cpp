#include<stdio.h>
#include<stdlib.h>
#include<math.h> 
#include<time.h>
#include"Practise5.h"
#include"studentmessage/studentmessage.h"
#include"huochedingpiao/huochedingpiao.h"
#include"tuozhan/tuozahn.h"

//实战五的接口函数
void HandlePractise5() {
	int key;
	while (true) {
		key = Practise5Menu();
		switch (key) {
		case 1: studentmessage();   //学生信息表
			break;
		case 2: huochedingpiao();   //火车订票系统
			break;
		case 3: riqijisuan();  //日期计算
			break;
		case 4: return;         //返回上一级
		case 5: exit(0);		//退出程序
		}

	}

}

//实战五菜单界面
static int Practise5Menu() {
	int key;
	printf("---------项目实战----------\n");
	printf("1.学生信息表\n");
	printf("2.火车订票系统\n");
	printf("3.日期计算\n");
	printf("4.返回上一级\n");
	printf("5.退出程序\n");
	printf("输入相应数字开始相应实战\n");
	scanf("%d", &key);
	return key;

}