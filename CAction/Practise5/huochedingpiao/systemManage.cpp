#include"huochedingpiao.h"
//ϵͳ����˵�
void systemManage(Station& station, Ticket& ticket, Book& book, int& flag) {
	int option;
	printf("*********************\n");
	printf("\t\t\tվ���--------1\n");
	printf("\t\t\tƱ���--------2\n");
	printf("\t(t\t������һ����----0\n");
	printf("\t\t*****************\n");
	printf("\t\t��ѡ��:");
	scanf("%d", &option);
	switch (option) {
	case 1:
		stationManage(station, ticket, book, flag);
		break;
	case 2:
		ticketManage(station, ticket, book, flag);
		break;
	case 0:
		start(flag);
		break;
	default:
		printf("\nѡ�����!\n");
		systemManage(station, ticket, book, flag);
		break;
	}
}
