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
		int i = 0;    //第一录入车站信息的个数
		printf("\n本系統第一次运行，清添加站点及対座年票信息!");
		initialize(station, ticket);
		printf("\n请输人添加车站信息的个数:");
		scanf("%d", &i);
		if (i > 0) {
			addStation(station, ticket, i);
			flag = 1;
		}
		else start(flag);
		printf("\n");
		printf("\t\t*********************************************\n");
		printf("\t\t\t售票服各--------------------1\n");
		printf("\t\t\t系統管理--------------------2\n");
		printf("\t\t\t退出系統--------------------0\n");
		printf("\t\t*********************************************\n");
		printf("\t\t请选择:");
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
			printf("谢谢你的使用!\n");
			exit(0);
			break;
		default:
			printf("\n选择出错!\n");
			flag = 0;
			start(flag);
			break;
		}
	}
}
void huochedingpiao() {

	srand((unsigned)time(NULL));//随机种子
	while (1)start(flag);

}









