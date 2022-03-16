//#include"yuesefu.h"
//int num = 0;
//void yuesefu() {
//	InputPersons();
//	while (true) {
//		ShowMenu();
//		switch (choice)
//		{
//		case '1':
//			DisplayLink();     //显示链表信息
//			break;
//		case '2':
//			ResetPwd();        //重输密码
//			break;
//		case '3':
//			CountAndQuit();    //开始约瑟夫游戏
//			break;
//		default:
//			printf("输入错误,请重新输入\n");
//			break;
//		}
//	}
//
//}
//
//void InputPersons() {
//	char name[LEN];
//	Person* p;    //新增加的人
//	head = tail;  //一开始,首尾都是NULL
//	while (true) {
//		printf("请输入第%d个人的信息,输入%s结束:\n", num + 1, OVER);
//		printf("人名(<=%d个字符):", LEN - 1);
//		scanf("%s", name);
//		if (strcmp(name, OVER) == 0)
//			return;
//		p = (Person*)malloc(sizeof(Person));
//		strcpy(p->name, name);
//
//		//输入密码k
//		printf("密码(整数):");
//		scanf("%d", &p->pwd);
//		p->next = head;           //首尾相连,形成循环
//
//		//创建链表
//
//		if (NULL == head) {
//			head = tail = p;
//			p->next = head;
//		}
//		else {
//			tail->next = p;
//			tail = p;
//		}
//		num++;   //新人添加到链表后,计数器才加1
//		printf("\n");
//	}
//}
//
////显示操作菜单
//void ShowMenu() {
//	while (true) {
//		printf("\n\n请选择操作:");
//		printf("\n==============================");
//		printf("\n(1)显示信息");
//		printf("\n(2)重新输人每个人的密码");
//		printf("\n(3)开始“数N退出”游戏");
//		printf("\n(0)退出程序");
//		printf("\n========================\n"); choice = getche();
//		if ('O' == choice)
//			exit(0);
//		else if ((choice - '0') >= 1 && (choice - '0') <= 3)return;
//
//	}
//}
//
////显示链表信息
//void DisplayLink() {
//	int i = 0;
//}
