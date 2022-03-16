#include"huochedingpiao.h"
//系统管理菜单
void systemManage(Station& station, Ticket& ticket, Book& book, int& flag) {
	int option;
	printf("*********************\n");
	printf("\t\t\t站点操--------1\n");
	printf("\t\t\t票务操--------2\n");
	printf("\t(t\t返回上一级菜----0\n");
	printf("\t\t*****************\n");
	printf("\t\t请选择:");
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
		printf("\n选择出错!\n");
		systemManage(station, ticket, book, flag);
		break;
	}
}
