#include<stdio.h>
#include<stdlib.h>
#include<math.h> 
#include<time.h>
#include"Practise6.h"
#include"yuesefu/yuesefu.h"
#include"bankAappointmentAsystem/bankAappointmentAsystem.h"


//ʵս��Ľӿں���
void HandlePractise6() {
	int key;
	while (true) {
		key = Practise6Menu();
		switch (key) {
		//case 1:    //ѧ����Ϣ��
		//	break;
		//case 2: huochedingpiao();   //�𳵶�Ʊϵͳ
		//	break;
		//case 3: riqijisuan();  //���ڼ���
		//	break;
		case 4:
			bankAappointmentAsystem();
			break;
		case 5: return;         //������һ��
		case 0: exit(0);		//�˳�����
		}

	}

}

//ʵս��˵�����
static int Practise6Menu() {
	int key;
	printf("---------��Ŀʵս----------\n");
	printf("1.����������\n");
	printf("2.����������(��չ���)\n");
	printf("3.������������\n");
	printf("4.�����ź�ϵͳ\n");
	printf("5.������һ��\n");
	printf("0.�˳�����\n");
	printf("������Ӧ���ֿ�ʼ��Ӧʵս\n");
	scanf("%d", &key);
	return key;

}