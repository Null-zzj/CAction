#include"Practise4.h"
//*********************分类统计全局变量
#define LEN2 100
int lc = 0, uc = 0, d = 0, s = 0, o = 0;


//实战一的接口函数
void HandlePractise4() {
	int key;
	while (true) {
		key = Practise4Menu();
		switch (key) {
		case 1: YueSeFu();               //约瑟夫问题
			break;
		case 2: YueSeFuAdd();            //约瑟夫问题扩展
			break;
		case 3: FenLeiTongJi();          //分类统计
			break;
		case 4: FenLeiTongJiAdd();       //分类统计扩展
			break;
		case 5: DanCiPaiYu();            //单词排序
			break;
		case 6: DanCiPaiYuAdd();         //单词排序扩展
			break;
		case 7: ShuZiChaZhao();          //拓展项目 数字查找
			break;
		case 8: return;         //返回上一级
		case 9: exit(0);		//退出程序
		}



	}

}

//实战一菜单界面
static int Practise4Menu() {
	int key;
	printf("---------项目实战----------\n");
	printf("1.约瑟夫问题\n");
	printf("2.约瑟夫问题扩展\n");
	printf("3.分类统计字符串各类字符个数\n");
	printf("4.分类统计字符串各类字符个数扩展\n");
	printf("5.对输入的N个单词排序\n");
	printf("6.对输入的N个单词排序扩展\n");
	printf("7.拓展项目\n");
	printf("8.返回上一级\n");
	printf("9.退出程序\n");
	printf("输入相应数字开始相应实战\n");
	scanf("%d", &key);
	return key;

}

//*************************************************************
void YueSeFu() {              //约瑟夫问题
	char name[N][LEN1];
	int i, k;
	printf("请依次输入%d个人名(每个人名不超过10个字符):\n",N);
	for (i = 0; i < N; i++) {
		scanf("%s", name[i]);
	}
	printf("\n请输入到第几任时退出:");
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
				printf("第%2d个退出者:%s\n", out, ary[idx]);
				strcpy(ary[idx], "\0");
				counter = 0;
			}
		}
	}
	
}

void YueSeFuAdd() {           //约瑟夫问题扩展
	int P, M, pwd;
	int i, mark, count;
	int r[31], out[31];
	printf("请输入总人数( <= 30 )及开始的M(正整数)的值:如5,3\n");
	scanf("%d%d", &P, &M);
	printf("请分别输入每个人的密码(用空格分开)\n");
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
	printf("出列的先后序列为:\n");
	for (i = 1; i < P; i++) {
		printf("%d\n", out[i]);
	}


}


//************************************************************
void FenLeiTongJi() {         //分类统计
	char ary[LEN2 + 1];
	printf("请输入100个以内的任意字符串\n");
	printf("将程序按大小写字母,数字,空格和其他字符进行统计.\n");
	printf("如果超过100个字符,程序将只对前100个字符进行统计:\n");
	_getch();
	gets_s(ary);
	Count(ary);
	printf("小写字母:%d\n", lc);
	printf("大写字母:%d\n", uc);
	printf("0-9数字: % d\n", d);
	printf("空格:%d\n", s);
	printf("其他字符:%d\n", o);
	printf("按任意键退出...");
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

void FenLeiTongJiAdd() {      //分类统计扩展
	int cc;
	printf("请输入字符串的大小");
	scanf("%d", &cc);
	char *ary = new char[cc];
	printf("请输入100个以内的任意字符串\n");
	printf("将程序按大小写字母,数字,空格和其他字符进行统计.\n");
	printf("如果超过100个字符,程序将只对前100个字符进行统计:\n");
	_getch();
	gets_s(ary,cc);
	Count(ary);
	printf("小写字母:%d\n", lc);
	printf("大写字母:%d\n", uc);
	printf("0-9数字: % d\n", d);
	printf("空格:%d\n", s);
	printf("其他字符:%d\n", o);
	printf("按任意键退出...");
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
void DanCiPaiYu() {           //单词排序
	char word[N1][M1];
	int m = M1 - 1;
	int count = N;
	int n = 0, i;
	while (n < 1 || N>50)
	{
		printf("请输入你要输入的单词数:(1 - %d)\n", count);
		scanf("%d", &n);
	}
	printf("请输入%d个单词,以空格分开\n(单词长度不超过%d,诺超出,程序会自动忽略超出部分)\n",n,m);
	for (i = 0; i < n; i++) {
		scanf("%s", &word[i]);
		word[i][M1 - 1] = '\0';
	}
	WordSort(word, n);
	print(word, n);
	printf("程序结束,若要对更多或者更长的单词排序请修改N,M的值\n");
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


void DanCiPaiYuAdd() {        //单词排序扩展
	char word[N1][M1];
	int n = 0, j = 0,k = 0;
	char sc[N1*M1] = "";
	printf("请输入一句话或n个单词,以空格分开\n(单词长度不超过%d,若超出,程序会自动忽略超出部分)\n", n);
	getchar();
	gets_s(sc);
	char* s = sc;
	while(*s != '\0') {
		while (*s != '\0')//提取单词
		{
			j = 0;
			while (*s == ' ' || *s==',' && *s != '\0')  //跳过非字母符号
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
	printf("程序结束,若要对更多或者更长的单词排序请修改N,M的值\n");
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
void ShuZiChaZhao() {         //数字查找    
	int arr[100];
	int n;
	printf("请输入要输入几个数\n");
	scanf("%d", &n);
	printf("请输入n个数字\n");
	for (int i = 0; i < n; i++) {
		scanf("%d",&arr[i]);
	}
	int dex;
	printf("请输入你要查找的数\n");
	scanf("%d", &dex);
	for (int i = 0; i < n; i++) {
		if (arr[i] == dex) {
			printf("有这个数字%d\n",dex);
			break;
		}
		else if(i == n - 1){
			printf("没有这个数字%d\n", dex);
		}
	}

	
}