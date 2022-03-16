#include"bankAappointmentAsystem.h"
person* head;                    //����ͷָ�� 
person* body;					 //���ڴ���������
person* last;					 //ָ�����һ���ڵ�,�Է��㴴����һ���ڵ�
int option;
int j = 0;                           //�������
int n = 1;								 //���ں��ж�λ

void bankAappointmentAsystem() {                 //�ź�ϵͳ�˵�
	do {
		printf("\n");
		printf("\t\t\t�����ź�ϵͳ\n");
		printf("\t\t*********************************\n");
		printf("\t\t*\t1.�鿴�ź��б�\t\t*\n");
		printf("\t\t*\t2.����ͻ���Ϣ\t\t*\n");
		printf("\t\t*\t3.ɾ���ͻ���Ϣ\t\t*\n");
		printf("\t\t*\t4.�޸Ŀͻ���Ϣ\t\t*\n");
		printf("\t\t*\t5.���пͻ�\t\t*\n");
		printf("\t\t*\t0.�˳�ϵ�y\t\t*\n");
		printf("\t\t*********************************\n");
		printf("\t\t��ѡ��:");
		scanf("%d", &option);
		switch (option) {
		case 1:
			checkList();                 //�鿴�ź��б�
			option = 0;
			break;
		case 2:
			if (addMessage())             //�����û�
				printf("\t\t��ӳɹ�\n\n\n");
			else
				printf("\t\t���ʧ��\n\n\n");
			option = 0;
			break;
		case 3:                           //ɾ���û�
			if (deleMessage())
				printf("\t\tɾ���ɹ�\n\n\n");
			else
				printf("\t\tɾ��ʧ��\n\n\n");
			option = 0;
			break;
		case 4:                           //������Ϣ
			if (alterMessage())
				printf("\t\t���ĳɹ�\n\n\n");

			else
				printf("\t\tɾ��ʧ��\n\n\n");
			option = 0;
			break;
		case 5:                           //�����û�
			call();
			break;
		case 0:
			printf("\t\tлл���ʹ��!\n\n\n");
			exit(0);
			break;
		default:
			printf("\n\t\tѡ�����!\n\n\n");
			option = 0;
			break;
		}
	} while (true);
}


bool addMessage() {     //����ͻ���Ϣ
	if (head == NULL) {
		// ������һ���ڵ㣬�����ͷָ��Ϊhead
		head = (person*)malloc(sizeof(person));
		printf("\n\t\t������ͻ���Ϣ:\n");
		printf("\t\tId(������10���ַ�):");
		scanf("%s", head->Id);
		printf("\t\t����(������5���ַ�):");
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
		printf("\n\t\t������ͻ���Ϣ:\n");			 //��ʼ���û���Ϣ
		printf("\t\tId(������10���ַ�):");
		scanf("%s", body->Id);
		printf("\t\t����(������5���ַ�):");
		scanf("%s", body->name);

		if (judge(body->Id)) {
			body->numeral = last->numeral + 1;        //��ǰ���е��ź�����һ���źż�һ
			last->next = body;                        //��һ���ڵ��nextָ����һ���ڵ�
			body->prior = last;
			body->next = NULL;                        //ʹ���ǰ�ڵ�һ���ڵ�ָ���
			last = body;                              //lastʼ��ָ�����һ���ڵ��Է��㴴������
			j++;
			return true;
		}
		else {
			printf("\t\t����Id����\n");
			return false;
		}
	}
	return false;
}

void checkList() {       //�鿴�ͻ�����
	person* check = head;
	printf("\t\t���\t����\t\tId\n");
	while (check != NULL) {
		printf("\t\t%-8d%-16s%s\n", check->numeral, check->name, check->Id);
		check = check->next;
	}

}

bool deleMessage() {							//ɾ������
	int i = 0;
	person* check = head;
	printf("\n\n\t\t������Ҫɾ�������:");
	scanf("%d", &i);
	if (i > 1 && i < j) {
		while (check->numeral != i) check = check->next;				//��λ��������ڵ�����
		(check->prior)->next = check->next;     //ʹ��һ������nextָ����һ������
		(check->next)->prior = check->prior;    //ʹ��һ������priorָ����һ������
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
		while (check->numeral != i) check = check->next;	//��λ��������ڵ�����
		(check->prior)->next = NULL;			//ʹ��һ������nextָ���
		sort(j);
		free(check);
		return true;
	}
	return false;

}

bool alterMessage() {     //�޸�
	int num;
	person* check = head;
	printf("��������Ҫ�޸ĵ����");
	scanf("%d", &num);
	while (check->numeral != num) check = check->next;	//��λ��������ڵ�����
	printf("\t\t�����û�Id\n");
	scanf("%s", check->Id);
	printf("\t\t�����û�����\n");
	scanf("%s", check->name);
	if (judge(check->Id)) {
		return true;
	}
	return false;
}

void call() {                                           //�����û�
	person* check = head;
	if (n > j) {
		printf("\t\t�Ѻ��������û�\n\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (i == n) {
			printf("\t\t��%d��%s��ǰ̨����ҵ��", check->numeral, check->name);
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

bool judge(char id[]) {      //�ж�����Id�Ƿ���֮ǰ�����Id�Ƿ���ͬ
	person* check = head;
	for (int i = 0; i < j; i++) {
		if (strcmp(id, check->Id) == 0)
			return false;
	}
	return true;
}