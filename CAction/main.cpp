#include<stdio.h>
#include<stdlib.h>
#include"main.h"
#include"Practise1/Practise1.h"
#include"Practise2/Practise2.h"
#include"Practise3/Practise3.h"
#include"Practise4/Practise4.h"
#include"Practise4/Practise4.h"
#include"Practise5/Practise5.h"
#include"Practise6/Practise6.h"
#include"Practise7/Practise7.h"



int main() {
	while (true) {
		int key;
		printf("************************************\n");
		printf("*********1.进入实战一模块***********\n");
		printf("*********2.进入实战二模块***********\n");
		printf("*********3.进入实战三模块***********\n");
		printf("*********4.进入实战四模块***********\n");
		printf("*********5.进入实战五模块***********\n");
		printf("*********6.进入实战六模块***********\n");
		printf("*********7.进入实战七模块***********\n");
		printf("*********8.进入实战八模块***********\n");
		printf("*********9.退出程序      ***********\n");
		scanf("%d", &key);
		switch (key) {
		case 1: HandlePractise1();
			break;
		case 2: HandlePractise2();
			break;
		case 3:HandlePractise3();
			break;
	    case 4:HandlePractise4();
			break;
		case 5:HandlePractise5();
			break;
		case 6:HandlePractise6();
			break;
		/*case 7:HandlePractise6();
			break;
		case 8:HandlePractise6();
			break;
		*/
		case 9: exit(0);
			break;
		default: printf("输入有错误,请重新选择\n");
		}
	}




}