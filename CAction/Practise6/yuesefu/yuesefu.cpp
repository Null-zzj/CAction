//#include"yuesefu.h"
//int num = 0;
//void yuesefu() {
//	InputPersons();
//	while (true) {
//		ShowMenu();
//		switch (choice)
//		{
//		case '1':
//			DisplayLink();     //��ʾ������Ϣ
//			break;
//		case '2':
//			ResetPwd();        //��������
//			break;
//		case '3':
//			CountAndQuit();    //��ʼԼɪ����Ϸ
//			break;
//		default:
//			printf("�������,����������\n");
//			break;
//		}
//	}
//
//}
//
//void InputPersons() {
//	char name[LEN];
//	Person* p;    //�����ӵ���
//	head = tail;  //һ��ʼ,��β����NULL
//	while (true) {
//		printf("�������%d���˵���Ϣ,����%s����:\n", num + 1, OVER);
//		printf("����(<=%d���ַ�):", LEN - 1);
//		scanf("%s", name);
//		if (strcmp(name, OVER) == 0)
//			return;
//		p = (Person*)malloc(sizeof(Person));
//		strcpy(p->name, name);
//
//		//��������k
//		printf("����(����):");
//		scanf("%d", &p->pwd);
//		p->next = head;           //��β����,�γ�ѭ��
//
//		//��������
//
//		if (NULL == head) {
//			head = tail = p;
//			p->next = head;
//		}
//		else {
//			tail->next = p;
//			tail = p;
//		}
//		num++;   //������ӵ������,�������ż�1
//		printf("\n");
//	}
//}
//
////��ʾ�����˵�
//void ShowMenu() {
//	while (true) {
//		printf("\n\n��ѡ�����:");
//		printf("\n==============================");
//		printf("\n(1)��ʾ��Ϣ");
//		printf("\n(2)��������ÿ���˵�����");
//		printf("\n(3)��ʼ����N�˳�����Ϸ");
//		printf("\n(0)�˳�����");
//		printf("\n========================\n"); choice = getche();
//		if ('O' == choice)
//			exit(0);
//		else if ((choice - '0') >= 1 && (choice - '0') <= 3)return;
//
//	}
//}
//
////��ʾ������Ϣ
//void DisplayLink() {
//	int i = 0;
//}
