#include<stdio.h>
#include<stdlib.h>
#include<math.h> 
#include<time.h>
#include"Practise5.h"
#include"studentmessage/studentmessage.h"
#include"huochedingpiao/huochedingpiao.h"
#include"tuozhan/tuozahn.h"

//ʵս��Ľӿں���
void HandlePractise5() {
	int key;
	while (true) {
		key = Practise5Menu();
		switch (key) {
		case 1: studentmessage();   //ѧ����Ϣ��
			break;
		case 2: huochedingpiao();   //�𳵶�Ʊϵͳ
			break;
		case 3: riqijisuan();  //���ڼ���
			break;
		case 4: return;         //������һ��
		case 5: exit(0);		//�˳�����
		}

	}

}

//ʵս��˵�����
static int Practise5Menu() {
	int key;
	printf("---------��Ŀʵս----------\n");
	printf("1.ѧ����Ϣ��\n");
	printf("2.�𳵶�Ʊϵͳ\n");
	printf("3.���ڼ���\n");
	printf("4.������һ��\n");
	printf("5.�˳�����\n");
	printf("������Ӧ���ֿ�ʼ��Ӧʵս\n");
	scanf("%d", &key);
	return key;

}