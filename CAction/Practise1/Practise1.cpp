#include<stdio.h>
#include<stdlib.h>
#include<math.h> 
#include<time.h>
#include"Practise1.h"



//ʵսһ�Ľӿں���
void HandlePractise1() {
	int key;
	while (true) {
		key = Practise1Menu();
		switch (key) {
		case 1: isTriangle();   //����������
			break;
		case 2: isTriangleAdd();   //����������(��չ)
			break;
		case 3: sizeyunsuan();  //����������
			break;
		case 4: sizeyunsuanADD();  //����������(��չ)
			break;
		case 5: houzichitao();  //���ӳ���
			break;
		case 6: houzichitaoAdd();  //���ӳ���(��չ)
			break;
		case 7: caishuyouxi();  //������Ϸ
			break;
		case 8: return;         //������һ��
		case 9: exit(0);		//�˳�����
		}

		

	}

}

//ʵսһ�˵�����
static int Practise1Menu() {
	int key;
	printf("---------��Ŀʵս----------\n");
	printf("1.����������\n");
	printf("2.����������(��չ���)\n");
	printf("3.������������\n");
	printf("4.������������(��չ�ݴη�)\n");
	printf("5.���ӳ�������\n");
	printf("6.���ӳ�������(��չ��)\n");
	printf("7.��չ��Ŀ(������Ϸ)\n");
	printf("8.������һ��\n");
	printf("9.�˳�����\n");
	printf("������Ӧ���ֿ�ʼ��Ӧʵս\n");
	scanf("%d", &key);
	return key;

}

//***********************************************************
static void isTriangle() {    //����������
	double a, b, c;
	printf("��������������0��ʵ��:(�Կո����)\n");
	scanf("%lf%lf%lf", &a, &b, &c);
	
	if ((a + b) > c && (b + c) > a && (a + c) > b) {
		printf("�ܹ���������\n");
	}
	else {
		printf("���ܹ���������\n");
	}
}
static void isTriangleAdd() {    //��չ,�����
	double a, b, c;
	printf("��������������0��ʵ��:(�Կո����)\n");
	scanf("%lf%lf%lf", &a, &b, &c);
	double p = (a + b + c) / 2;
	if ((a + b) > c && (b + c) > a && (a + c) > b) {
		double p = (a + b + c) / 2;
		double s = sqrt(p*(p - a)*(p - b)*(p - c));
		printf("�ܹ���������\n���Ϊ:");
		printf("%.2lf",s);
	}
	else {
		printf("���ܹ���������\n");
	}


}

//**************************************************************
static void sizeyunsuan() { //����������
	int a, b;
	char key,answer = 'y';
	
	do{
		printf("-------���׼�����------\n");
		printf("���뽫Ҫ�����������Ͳ�����\n");
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
		default:printf("�������������,����������\n");
			break;
		}
		printf("�Ƿ���Ҫ�ٴμ���,�����Ҫ,����y,����n\n");
		getchar();
		scanf("%c", &answer);
	} while (answer == 'y');
}
//������������չ  ���ݴη�
static void sizeyunsuanADD() {
	int i = 0,a, b,c;
	
	char key, answer = 'y';

	do {
		printf("-------���׼�����------\n");
		printf("���뽫Ҫ�����������Ͳ�����\n");
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
		default:printf("�������������,����������\n");
			break;
		}
		printf("�Ƿ���Ҫ�ٴμ���,�����Ҫ,����y,����n\n");
		getchar();
		scanf("%c", &answer);
	} while (answer == 'y');
}


//*************************************************************
static void houzichitao() {    //���ӳ���
	long long count = 1,n;
	printf("����������ڵڼ��컹ʣ1������\n");
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		count = (count + 1) * 2;
	}
	printf("���ӵ�һ�칲ժ��%lld������\n",count);
}
//���ӳ�����չ
static void houzichitaoAdd() {
	int n = 10,count = 1;
	for (int i = 1; i < n; i++) {
		count = (count + 1) * (count + 1);
	}
	printf("���ӵ�һ�칲ժ��%d������\n", count);
}





//��չ��Ŀ ������Ϸ
static void caishuyouxi(){
	srand(time(0));
	int answer = rand() % 10;
	int count;
	printf("��������Ҫ�µ���:(��Χ0-10)\n");
	while (true) {
		scanf("%d", &count);
		if (count > answer) {
			printf("��µ�������.\n");
		}
		else if (count < answer) {
			printf("��µ���С��.\n");
		}
		else {
			printf("����ȷ�������%d.\n",answer);
			return;
		}
	}
}

