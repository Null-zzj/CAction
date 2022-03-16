#include"studentmessage.h"
char choice = 0;              //用户选择的项
char dir = 0;                 //用户排序方向(1:升序,2:降序)
int i;                        //用于循环的变量
Student stu[N2];               //存放N个学生信息的数组

Student sorted[N2];            //存放排序后的学生
void studentmessage() {
	InputStudent();
	//输入学生信息
	while (1) {
		DisplayMenu();                 // 显示菜单
		if ('0' == choice)             //选择操作“0”，则退出程序
		{
			exit(0);
		}
		else if ('9' == choice)
		{
			OutputStudent(stu);        //选择操作“9”，则输出全部原始信息

		}
		else                           //其他操作，按选定属性排序
			GetOrderDir(); // 显示用户选择排序方向
		if ('0' == dir) exit(0);
		SortStudent();//排序学生信息
		OutputStudent(sorted); //输出学生信息
	}
}


void InputStudent() {                                //输人学生信息 
	for (i = 0; i < N2; i++) {
		printf("\n请输人第%d/%d个学生信息: \n", i + 1, N2);
		printf("---------------------------\n");
		printf("学号(12个字符以内):\t");
		scanf("%s", stu[i].id);
		stu[i].id[IDLen - 1] = 0;             	//最后一个字符强行加一-个结束符
		printf("姓名(10个字符以内):\t");
		scanf("%s", stu[i].name);
		stu[i].name[NameLen - 1] = 0;           //最后一个字符强行加一一个结束符
		printf("性别(4个字符以内):\t");
		scanf("%s", stu[i].sex);
		stu[i].sex[SexLen - 1] = 0;             //最后一个字符强行加一个结束符
		printf("年龄(整数) ;\t\t");
		scanf("%d", &stu[i].age);
		printf("《C语言》成绩(整数):\t");
		scanf("%d", &stu[i].score.cp);
		printf("《英语》成绩(整数);\t");
		scanf("%d", &stu[i].score.en);
		printf("《高数》成绩(整数):\t");
		scanf("%d", &stu[i].score.math);
		stu[i].avg = (stu[i].score.cp + stu[i].score.en + stu[i].score.math) / 3.0;
		printf("---------------------------------------------------------------------\n");
	}
	for (i = 0; i < N2; i++) {
		sorted[i] = stu[i];
	}
}

//显示操作菜单字师来一步，(图1 出8

void DisplayMenu() {

	while (1) {

		printf("\n请选择排序字段: \n");

		printf("------------------------------------\n");
		printf("(1)学号\t(2)姓名\t (3)性别\t(4)年龄\n");
		printf("(5)C语言\t(6)英语\t(7)高数\t(8)平均分\n");
		printf("(9)显示全部原始信息\t\t(0)退出程序\n");
		printf("------------------------------------\n");
		choice = _getche();
		if ((choice - '0') < 0 || (choice - '0') > 9)
			printf("\n 请选择正确的操作\n");
		else
			return;
	}
}



void GetOrderDir() {// 显示用户选择排序方向:1升序  2降序

	while (1) {
		printf("\n请选择排序方向: \n");
		printf("------------------------------------");
		printf("(1)升序\t (2)降序\t (0)退出程序\n");
		printf("------------------------------------");
		dir = _getche();
		if ((dir - '0') < 0 || (dir - '0') > 2)
			printf("\n请选择正确的操作!");
		else
			return;
	}
}
//对学生信息stu[]进行排序，结果存人sorted[]中

void SortStudent() {
	Student s;                 //临时变量, 用于交换
	int j;              //循环变量
	int f;           //是否交换:0不交换1交换
	//从索引0到N- 1,按排序字段的降序排列
	//如果要求升序排列，则输出时倒序输出即可

	for (i = 0; i < N2; i++) {
		for (j = N2 - 1; j > i; j++) {
			f = 0;
			switch (choice)
			{
			case 1:
				if (strcmp(sorted[i].id, sorted[j].id) < 0)
					f = 1;
				break;
			case 2:
				if (strcmp(sorted[i].name, sorted[j].name) < 0)
					f = 1;
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				break;
			default:
				printf("错误,请选择正确操作!\n");
				break;
			}
			if (f == 1) {
				s = sorted[i];
				sorted[i] = sorted[j];
				sorted[j] = s;
			}
		}
	}
}


void OutputStudent(Student s[]) {                 //输出学生信息
	printf("\n%s的学生信息:\n============\n", '9' == choice ? "原始" : "排序后");
	printf("学号姓名性别年龄c语言英语高数平均分\n");
	printf("----------------------------------\n");
	if ('1' == dir) {       // 升序

		for (i = N2 - 1; i >= 0; i--) {
			printf("%-15s%-14s%-7s%-7d", s[i].id, s[i].name, s[i].sex, s[i].age);
			printf("%-7d%-7d%-7d%4.lf\n", s[i].score.cp, s[i].score.en, s[i].score.math, s[i].avg);
		}
	}
	else {
		for (i = 0; i < N2; i++) {
			printf("%-15s%-14s%-7s%-7d", s[i].id, s[i].name, s[i].sex, s[i].age);
			printf("%-7d%-7d%-7d%4.1f\n", s[i].score.cp, s[i].score.en, s[i].score.math, s[i].avg);
		}
	}
	dir = 0;//每次排序后,将排序方向置为“0”
	printf("--------------------------------------------\n");
}