#include"Practise4.h"
//*********************����ͳ��ȫ�ֱ���
#define LEN2 100
int lc = 0, uc = 0, d = 0, s = 0, o = 0;


//ʵսһ�Ľӿں���
void HandlePractise4() {
	int key;
	while (true) {
		key = Practise4Menu();
		switch (key) {
		case 1: YueSeFu();               //Լɪ������
			break;
		case 2: YueSeFuAdd();            //Լɪ��������չ
			break;
		case 3: FenLeiTongJi();          //����ͳ��
			break;
		case 4: FenLeiTongJiAdd();       //����ͳ����չ
			break;
		case 5: DanCiPaiYu();            //��������
			break;
		case 6: DanCiPaiYuAdd();         //����������չ
			break;
		case 7: ShuZiChaZhao();          //��չ��Ŀ ���ֲ���
			break;
		case 8: return;         //������һ��
		case 9: exit(0);		//�˳�����
		}



	}

}

//ʵսһ�˵�����
static int Practise4Menu() {
	int key;
	printf("---------��Ŀʵս----------\n");
	printf("1.Լɪ������\n");
	printf("2.Լɪ��������չ\n");
	printf("3.����ͳ���ַ��������ַ�����\n");
	printf("4.����ͳ���ַ��������ַ�������չ\n");
	printf("5.�������N����������\n");
	printf("6.�������N������������չ\n");
	printf("7.��չ��Ŀ\n");
	printf("8.������һ��\n");
	printf("9.�˳�����\n");
	printf("������Ӧ���ֿ�ʼ��Ӧʵս\n");
	scanf("%d", &key);
	return key;

}

//*************************************************************
void YueSeFu() {              //Լɪ������
	char name[N][LEN1];
	int i, k;
	printf("����������%d������(ÿ������������10���ַ�):\n",N);
	for (i = 0; i < N; i++) {
		scanf("%s", name[i]);
	}
	printf("\n�����뵽�ڼ���ʱ�˳�:");
	scanf("%d", &k);
	JosephProblem(name, k);
	puts("Press any key to exit...");
	_getch();


}        
void JosephProblem(char ary[][LEN1], int K) {
	int out = 0;
	int counter = 0;
	int idx = -1;
	while (out < N) {
		idx++;
		if (idx == N)
			idx = 0;
		if (strcmp(ary[idx], "\0") == 0) {
			continue;
		}
		else {
			counter++;
			if (counter == K) {
				out++;
				printf("��%2d���˳���:%s\n", out, ary[idx]);
				strcpy(ary[idx], "\0");
				counter = 0;
			}
		}
	}
	
}

void YueSeFuAdd() {           //Լɪ��������չ
	int P, M, pwd;
	int i, mark, count;
	int r[31], out[31];
	printf("������������( <= 30 )����ʼ��M(������)��ֵ:��5,3\n");
	scanf("%d%d", &P, &M);
	printf("��ֱ�����ÿ���˵�����(�ÿո�ֿ�)\n");
	for( i = 1; i <= P ;i++){
		scanf("%d", &pwd);
		r[i] = pwd;
	}
	mark = 0;
	count = 0;
	while (1) {
		for (i = 1; i <= P; i++) {
			if (r[i] > 0) {
				mark++;
				if (mark == M) {
					count++;
					out[count] = i;
					M = r[i];
					r[i] = 0;
					mark = 0;
				}
			}
		}
		if (count == P) {
			break;
		}
	}
	printf("���е��Ⱥ�����Ϊ:\n");
	for (i = 1; i < P; i++) {
		printf("%d\n", out[i]);
	}


}


//************************************************************
void FenLeiTongJi() {         //����ͳ��
	char ary[LEN2 + 1];
	printf("������100�����ڵ������ַ���\n");
	printf("�����򰴴�Сд��ĸ,����,�ո�������ַ�����ͳ��.\n");
	printf("�������100���ַ�,����ֻ��ǰ100���ַ�����ͳ��:\n");
	_getch();
	gets_s(ary);
	Count(ary);
	printf("Сд��ĸ:%d\n", lc);
	printf("��д��ĸ:%d\n", uc);
	printf("0-9����: % d\n", d);
	printf("�ո�:%d\n", s);
	printf("�����ַ�:%d\n", o);
	printf("��������˳�...");
	_getch();
}
void Count(char ary[]) {
	int i = 0;
	char c;
	while (ary[i]) {
		c = ary[i];
		if(c >= '0' && c <= '9') {
			d++;
		}
		else if(c >= 'a'&& c <= 'z') {
			lc++;
		}
		else if(c >= 'A' && c <= 'Z') {
			uc++;
		}
		else if (c == ' ') {
			s++;
		}
		else {
			o++;
		}
		i++;
	}
}

void FenLeiTongJiAdd() {      //����ͳ����չ
	int cc;
	printf("�������ַ����Ĵ�С");
	scanf("%d", &cc);
	char *ary = new char[cc];
	printf("������100�����ڵ������ַ���\n");
	printf("�����򰴴�Сд��ĸ,����,�ո�������ַ�����ͳ��.\n");
	printf("�������100���ַ�,����ֻ��ǰ100���ַ�����ͳ��:\n");
	_getch();
	gets_s(ary,cc);
	Count(ary);
	printf("Сд��ĸ:%d\n", lc);
	printf("��д��ĸ:%d\n", uc);
	printf("0-9����: % d\n", d);
	printf("�ո�:%d\n", s);
	printf("�����ַ�:%d\n", o);
	printf("��������˳�...");
	_getch();
}
void CountAdd(char ary[]) {
	int i = 0;
	char c;
	while (ary[i]) {
		c = ary[i];
		if (c >= '0' && c <= '9') {
			d++;
		}
		else if (c >= 'a' && c <= 'z') {
			lc++;
		}
		else if (c >= 'A' && c <= 'Z') {
			uc++;
		}
		else if (c == ' ') {
			s++;
		}
		else {
			o++;
		}
		i++;
	}
}

//***********************************************************
void DanCiPaiYu() {           //��������
	char word[N1][M1];
	int m = M1 - 1;
	int count = N;
	int n = 0, i;
	while (n < 1 || N>50)
	{
		printf("��������Ҫ����ĵ�����:(1 - %d)\n", count);
		scanf("%d", &n);
	}
	printf("������%d������,�Կո�ֿ�\n(���ʳ��Ȳ�����%d,ŵ����,������Զ����Գ�������)\n",n,m);
	for (i = 0; i < n; i++) {
		scanf("%s", &word[i]);
		word[i][M1 - 1] = '\0';
	}
	WordSort(word, n);
	print(word, n);
	printf("�������,��Ҫ�Ը�����߸����ĵ����������޸�N,M��ֵ\n");
}
void WordSort(char word[][M1], int n) {
	char key[M1];
	int i, j;
	for (i = 1; i < n; i++) {
		strcpy(key, word[i]);
		j = i;
		while (j >= 1 && strcmp(word[j - 1], key) > 0) {
			strcpy(word[j], word[j - 1]);
			j--;
		}
		strcpy(word[j], key);
	}
}
void print(const char word[][M1], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%s\n", word[i]);
	}

}


void DanCiPaiYuAdd() {        //����������չ
	char word[N1][M1];
	int n = 0, j = 0,k = 0;
	char sc[N1*M1] = "";
	printf("������һ�仰��n������,�Կո�ֿ�\n(���ʳ��Ȳ�����%d,������,������Զ����Գ�������)\n", n);
	getchar();
	gets_s(sc);
	char* s = sc;
	while(*s != '\0') {
		while (*s != '\0')//��ȡ����
		{
			j = 0;
			while (*s == ' ' || *s==',' && *s != '\0')  //��������ĸ����
				s++;
			while (*s != ' ' && *s != '\0' && *s != ',')
			{

				word[k][j++] = *s++;

			}
			word[k][j] = '\0';
			k++;
		}
	} 
	WordSort(word, k);
	print(word, k);
	printf("�������,��Ҫ�Ը�����߸����ĵ����������޸�N,M��ֵ\n");
}
void WordSortAdd(char word[][M1], int n) {
	char *key;
	int i, j;
	for (i = 0; i < n; i++) {
		for(j = 0;j<n-1;j++){
			if (strcmp(word[j], word[j + 1]) > 0) {

			key = word[j];
			strcpy(word[j], word[j + 1]);  
			strcpy(word[j + 1] , key);

			}
		}
	}
}
void printAdd(const char word[][M1], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%s\n", word[i]);
	}

}
//***********************************************************
void ShuZiChaZhao() {         //���ֲ���    
	int arr[100];
	int n;
	printf("������Ҫ���뼸����\n");
	scanf("%d", &n);
	printf("������n������\n");
	for (int i = 0; i < n; i++) {
		scanf("%d",&arr[i]);
	}
	int dex;
	printf("��������Ҫ���ҵ���\n");
	scanf("%d", &dex);
	for (int i = 0; i < n; i++) {
		if (arr[i] == dex) {
			printf("���������%d\n",dex);
			break;
		}
		else if(i == n - 1){
			printf("û���������%d\n", dex);
		}
	}

	
}