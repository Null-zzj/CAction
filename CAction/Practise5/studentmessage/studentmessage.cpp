#include"studentmessage.h"
char choice = 0;              //�û�ѡ�����
char dir = 0;                 //�û�������(1:����,2:����)
int i;                        //����ѭ���ı���
Student stu[N2];               //���N��ѧ����Ϣ������

Student sorted[N2];            //���������ѧ��
void studentmessage() {
	InputStudent();
	//����ѧ����Ϣ
	while (1) {
		DisplayMenu();                 // ��ʾ�˵�
		if ('0' == choice)             //ѡ�������0�������˳�����
		{
			exit(0);
		}
		else if ('9' == choice)
		{
			OutputStudent(stu);        //ѡ�������9���������ȫ��ԭʼ��Ϣ

		}
		else                           //������������ѡ����������
			GetOrderDir(); // ��ʾ�û�ѡ��������
		if ('0' == dir) exit(0);
		SortStudent();//����ѧ����Ϣ
		OutputStudent(sorted); //���ѧ����Ϣ
	}
}


void InputStudent() {                                //����ѧ����Ϣ 
	for (i = 0; i < N2; i++) {
		printf("\n�����˵�%d/%d��ѧ����Ϣ: \n", i + 1, N2);
		printf("---------------------------\n");
		printf("ѧ��(12���ַ�����):\t");
		scanf("%s", stu[i].id);
		stu[i].id[IDLen - 1] = 0;             	//���һ���ַ�ǿ�м�һ-��������
		printf("����(10���ַ�����):\t");
		scanf("%s", stu[i].name);
		stu[i].name[NameLen - 1] = 0;           //���һ���ַ�ǿ�м�һһ��������
		printf("�Ա�(4���ַ�����):\t");
		scanf("%s", stu[i].sex);
		stu[i].sex[SexLen - 1] = 0;             //���һ���ַ�ǿ�м�һ��������
		printf("����(����) ;\t\t");
		scanf("%d", &stu[i].age);
		printf("��C���ԡ��ɼ�(����):\t");
		scanf("%d", &stu[i].score.cp);
		printf("��Ӣ��ɼ�(����);\t");
		scanf("%d", &stu[i].score.en);
		printf("���������ɼ�(����):\t");
		scanf("%d", &stu[i].score.math);
		stu[i].avg = (stu[i].score.cp + stu[i].score.en + stu[i].score.math) / 3.0;
		printf("---------------------------------------------------------------------\n");
	}
	for (i = 0; i < N2; i++) {
		sorted[i] = stu[i];
	}
}

//��ʾ�����˵���ʦ��һ����(ͼ1 ��8

void DisplayMenu() {

	while (1) {

		printf("\n��ѡ�������ֶ�: \n");

		printf("------------------------------------\n");
		printf("(1)ѧ��\t(2)����\t (3)�Ա�\t(4)����\n");
		printf("(5)C����\t(6)Ӣ��\t(7)����\t(8)ƽ����\n");
		printf("(9)��ʾȫ��ԭʼ��Ϣ\t\t(0)�˳�����\n");
		printf("------------------------------------\n");
		choice = _getche();
		if ((choice - '0') < 0 || (choice - '0') > 9)
			printf("\n ��ѡ����ȷ�Ĳ���\n");
		else
			return;
	}
}



void GetOrderDir() {// ��ʾ�û�ѡ��������:1����  2����

	while (1) {
		printf("\n��ѡ��������: \n");
		printf("------------------------------------");
		printf("(1)����\t (2)����\t (0)�˳�����\n");
		printf("------------------------------------");
		dir = _getche();
		if ((dir - '0') < 0 || (dir - '0') > 2)
			printf("\n��ѡ����ȷ�Ĳ���!");
		else
			return;
	}
}
//��ѧ����Ϣstu[]�������򣬽������sorted[]��

void SortStudent() {
	Student s;                 //��ʱ����, ���ڽ���
	int j;              //ѭ������
	int f;           //�Ƿ񽻻�:0������1����
	//������0��N- 1,�������ֶεĽ�������
	//���Ҫ���������У������ʱ�����������

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
				printf("����,��ѡ����ȷ����!\n");
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


void OutputStudent(Student s[]) {                 //���ѧ����Ϣ
	printf("\n%s��ѧ����Ϣ:\n============\n", '9' == choice ? "ԭʼ" : "�����");
	printf("ѧ�������Ա�����c����Ӣ�����ƽ����\n");
	printf("----------------------------------\n");
	if ('1' == dir) {       // ����

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
	dir = 0;//ÿ�������,����������Ϊ��0��
	printf("--------------------------------------------\n");
}