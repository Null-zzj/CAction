#include<stdio.h>
#include<stdlib.h>
#include<math.h> 
#include<time.h>
#include"Practise3.h"

//ʵս�� �Ľӿں���
void HandlePractise3() {
	int key;
	while (true) {
		key = Practise3Menu();
		switch (key) {
		//case 1: jiecheng();              //�׳�
		//	break;
		//case 2:  fib();                  //쳲���������
		//	break;
		//case 3: houzichitao();           //���ӳ���
		//	break;
		//case 4: houzichitaoAdd();        //���ӳ���(��չ)
		//	break;
		//case 5: hannuota();              //��ŵ��
		//	break;
		//case 6: hannuotaAdd();    //��ŵ��(��չ)
		//	break;
		//case 7: zoulouti();              //��¥��
		//	break;
		case 8: return;         //������һ��
		case 9: exit(0);		//�˳�����

		}
	}

}
//ʵս���˵�����
static int Practise3Menu() {
	int key;
	printf("---------��Ŀʵս----------\n");
	printf("1.�׳�\n");
	printf("2.쳲���������\n");
	printf("3.���ӳ���\n");
	printf("4.���ӳ���(��չ)\n");
	printf("5.��ŵ��\n");
	printf("6.��ŵ��(��չ)\n");
	printf("7.��չ��Ŀ\n");
	printf("8.������һ��\n");
	printf("9.�˳�����\n");
	printf("������Ӧ���ֿ�ʼ��Ӧʵս\n");
	scanf("%d", &key);
	return key;
}