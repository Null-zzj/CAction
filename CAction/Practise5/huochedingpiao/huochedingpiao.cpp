#include"huochedingpiao.h"
Station station;
Ticket ticket;
Book book;
int flag = 1;
void initialize(Station& station, Ticket& ticket) {
	station.count = 0;
	ticket.count = 0;
	book.count = 0;
}

void start(int& flag) {
	int option;
	if (flag) {
		int i = 0;    //��һ¼�복վ��Ϣ�ĸ���
		printf("\n��ϵ�y��һ�����У������վ�㼰������Ʊ��Ϣ!");
		initialize(station, ticket);
		printf("\n��������ӳ�վ��Ϣ�ĸ���:");
		scanf("%d", &i);
		if (i > 0) {
			addStation(station, ticket, i);
			flag = 1;
		}
		else start(flag);
		printf("\n");
		printf("\t\t*********************************************\n");
		printf("\t\t\t��Ʊ����--------------------1\n");
		printf("\t\t\tϵ�y����--------------------2\n");
		printf("\t\t\t�˳�ϵ�y--------------------0\n");
		printf("\t\t*********************************************\n");
		printf("\t\t��ѡ��:");
		scanf("%d", &option);
		switch (option) {
		case 1:
			ticketServices(station, ticket, book, flag);
			flag = 0;
			break;
		case 2:
			systemManage(station, ticket, book, flag);
			flag = 0;
			break;

		case 0:
			printf("лл���ʹ��!\n");
			exit(0);
			break;
		default:
			printf("\nѡ�����!\n");
			flag = 0;
			start(flag);
			break;
		}
	}
}
void huochedingpiao() {

	srand((unsigned)time(NULL));//�������
	while (1)start(flag);

}









