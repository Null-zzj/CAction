#include"huochedingpiao.h"
//��վ����
void stationManage(Station& station, Ticket& ticket, Book& book, int& flag) {
	int option, i = 0;
	printf("\t\t***************************\n");
	printf("\t\t\t�鿴��վ��Ϣ------------1\n");
	printf("\t\t\t��ӳ�վ��Ϣ------------2\n");
	printf("\t\t\t�޸ĳ�վ��Ϣ------------3\n"); 			//Ҫ���޸�Ʊ�ۺ���Ʊ��
	printf("\t\t\tɾ����վ��Ϣ------------4\n");
	printf("\t\t\t������һ���˵�----------5\n");
	printf("\t\t***************************\n");
	printf("\t\t��ѡ��:");
	scanf("%d", &option);
	switch (option) {
	case 1:
		printStation(station);
		break;
	case 2:
		printf("�����������ӳ�վ��Ϣ�ĸ�����");
		scanf("%d", &i);
		printf("%d\n", i);
		if (i > 0) addStation(station, ticket, i);
		break;

	case 3:
		updateStation(station, ticket);
		break;

	case 4:
		/*deleteStation(station, ticket);*/
		break;
	case 0:
		systemManage(station, ticket, book, flag);
		break;

	default:
		printf("\nѡ�����! \n");
		break;
	}
}

void addStation(Station& s, Ticket& t, int snum) {//���վ�� //snum: ��ӳ�վ������
	int i = s.count;
	int end = s.count + snum;
	printf("\n������%d����վ��Ϣ:\n", snum);
	for (; i < end; i++) {
		printf("------------------------\n");
		printf("\n�����˵�%d����վ��Ϣ", snum);
		printf("\tl.��������ʼվ����:\t");
		scanf("%s", &s.station[i].from);
		printf("\t2.�������յ�վ����:\t");
		scanf("%s", &s.station[i].to);
		printf("\t3.������Ʊ��:\t\t");
		scanf("%d", &s.station[i].money);
		printf("\t4.������Ʊ��:\t\t");
		scanf("%d", &s.station[i].numbers);
		s.station[i].stationId = rand()%1000;
		printf("\n\t5.�����Ʊ����Ϣ:\n");
		addTicket(s.station[i].stationId, s.station[i].numbers, t);
		printf("**��%d����վ��Ϣ��Ʊ����Ϣ��Ӽ�¼�ɹ�!**\n",i+1);
		printf("----------------------------------\n");
		s.count++;
	}
}
void printStation(Station& s) {	//��������:��ӡվ����Ϣ
	int i;
	printf("\nit\t��վ���\t��վ\t��վ\tƱ��\tʣ��Ʊ��\n");
	printf("\t\t-------------------------------\n");
	for (i = 0; i < s.count; i++) {
		if (!s.station[i].stationId) {
			printf("�޳�վ��Ϣ! \n");
			break;
		}
		printf("\t\t%d\t%s\t%s\t%d\t%d\n", s.station[i].stationId, s.station[i].from, s.station[i].to, s.station[i].money, s.station[i].numbers);
		printf("\t\t-------------------------------\n");
	}
}

void updateStation(Station &s,Ticket &t) {		//���³�վ��Ϣ
	int stationId;
	printStation(s);
	printf("ѡ��Ҫ�޸ĵĳ�վ���:");
	scanf("%d", &stationId);
}
