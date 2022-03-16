#include"bankAappointmentAsystem.h"
person* head;                    //链表头指针 
person* body;					 //用于创建新链表
person* last;					 //指向最后一个节点,以方便创建下一个节点
int option;
int j = 0;                           //链表计数
int n = 1;								 //用于呼叫定位

void bankAappointmentAsystem() {                 //排号系统菜单
	do {
		printf("\n");
		printf("\t\t\t银行排号系统\n");
		printf("\t\t*********************************\n");
		printf("\t\t*\t1.查看排号列表\t\t*\n");
		printf("\t\t*\t2.输入客户信息\t\t*\n");
		printf("\t\t*\t3.删除客户信息\t\t*\n");
		printf("\t\t*\t4.修改客户信息\t\t*\n");
		printf("\t\t*\t5.呼叫客户\t\t*\n");
		printf("\t\t*\t0.退出系統\t\t*\n");
		printf("\t\t*********************************\n");
		printf("\t\t请选择:");
		scanf("%d", &option);
		switch (option) {
		case 1:
			checkList();                 //查看排号列表
			option = 0;
			break;
		case 2:
			if (addMessage())             //输入用户
				printf("\t\t添加成功\n\n\n");
			else
				printf("\t\t添加失败\n\n\n");
			option = 0;
			break;
		case 3:                           //删除用户
			if (deleMessage())
				printf("\t\t删除成功\n\n\n");
			else
				printf("\t\t删除失败\n\n\n");
			option = 0;
			break;
		case 4:                           //更改信息
			if (alterMessage())
				printf("\t\t更改成功\n\n\n");

			else
				printf("\t\t删除失败\n\n\n");
			option = 0;
			break;
		case 5:                           //呼叫用户
			call();
			break;
		case 0:
			printf("\t\t谢谢你的使用!\n\n\n");
			exit(0);
			break;
		default:
			printf("\n\t\t选择出错!\n\n\n");
			option = 0;
			break;
		}
	} while (true);
}


bool addMessage() {     //输入客户信息
	if (head == NULL) {
		// 创建第一个节点，链表的头指针为head
		head = (person*)malloc(sizeof(person));
		printf("\n\t\t请输入客户信息:\n");
		printf("\t\tId(不超过10个字符):");
		scanf("%s", head->Id);
		printf("\t\t姓名(不超过5个字符):");
		scanf("%s", head->name);
		head->next = NULL;
		head->prior = NULL;
		head->numeral = 1;
		last = head;
		j++;
		return true;
	}
	else {
		body = (person*)malloc(sizeof(person));
		printf("\n\t\t请输入客户信息:\n");			 //初始化用户信息
		printf("\t\tId(不超过10个字符):");
		scanf("%s", body->Id);
		printf("\t\t姓名(不超过5个字符):");
		scanf("%s", body->name);

		if (judge(body->Id)) {
			body->numeral = last->numeral + 1;        //当前序列的排号是上一个排号加一
			last->next = body;                        //上一个节点的next指向下一个节点
			body->prior = last;
			body->next = NULL;                        //使最后当前节点一个节点指向空
			last = body;                              //last始终指向最后一个节点以方便创建链表
			j++;
			return true;
		}
		else {
			printf("\t\t输入Id错误\n");
			return false;
		}
	}
	return false;
}

void checkList() {       //查看客户队列
	person* check = head;
	printf("\t\t序号\t姓名\t\tId\n");
	while (check != NULL) {
		printf("\t\t%-8d%-16s%s\n", check->numeral, check->name, check->Id);
		check = check->next;
	}

}

bool deleMessage() {							//删除队列
	int i = 0;
	person* check = head;
	printf("\n\n\t\t请输入要删除的序号:");
	scanf("%d", &i);
	if (i > 1 && i < j) {
		while (check->numeral != i) check = check->next;				//定位到序号所在的链表
		(check->prior)->next = check->next;     //使上一个链表next指向下一个链表
		(check->next)->prior = check->prior;    //使下一个链表prior指向上一个链表
		sort(j);
		free(check);
		return true;
	}
	else if (i == 1) {
		head = head->next;
		sort(j);
		free(check);
		return true;
	}
	else if (i == j) {
		while (check->numeral != i) check = check->next;	//定位到序号所在的链表
		(check->prior)->next = NULL;			//使上一个链表next指向空
		sort(j);
		free(check);
		return true;
	}
	return false;

}

bool alterMessage() {     //修改
	int num;
	person* check = head;
	printf("请输入你要修改的序号");
	scanf("%d", &num);
	while (check->numeral != num) check = check->next;	//定位到序号所在的链表
	printf("\t\t输入用户Id\n");
	scanf("%s", check->Id);
	printf("\t\t输入用户姓名\n");
	scanf("%s", check->name);
	if (judge(check->Id)) {
		return true;
	}
	return false;
}

void call() {                                           //呼叫用户
	person* check = head;
	if (n > j) {
		printf("\t\t已呼叫所有用户\n\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (i == n) {
			printf("\t\t请%d号%s到前台办理业务", check->numeral, check->name);
			n++;
			return;
		}
		check = check->next;
	}
}

void sort(int j) {
	j--;
	int i = 0;
	person* check = head;
	for (int k = 0; i < j; k++) {
		check->numeral = ++i;
		check = check->next;
	}
}

bool judge(char id[]) {      //判断输入Id是否与之前输入的Id是否相同
	person* check = head;
	for (int i = 0; i < j; i++) {
		if (strcmp(id, check->Id) == 0)
			return false;
	}
	return true;
}