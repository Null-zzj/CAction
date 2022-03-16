#include"huochedingpiao.h"
//车票管理

void ticketManage(Station& station, Ticket& ticket, Book& book, int& flag) {
	int option;
	printf("\t\t************************\n");
	printf("\t\t\t已售车票-------------1\n");
	printf("\t\t\t剩余车票-------------2\n");
	printf("\t\t\t返回上一级菜---------0\n");
	printf("\t\t************************\n");
	printf("\t\t请选择:");
	scanf("%d", &option);
	switch (option) {
	case 1:
		showSaledTickets(book);
		break;
	case 2:
		showOnsaledTickets(station);
		break;
	case 0:
		systemManage(station, ticket, book, flag);
		break;
	default:
		printf("\n选择出错! \n");
		ticketManage(station, ticket, book, flag);
		break;
	}
}

void addTicket(int stationId, int number, Ticket& t) {
	int i = t.count;
	int end = t.count + number;
	char trainId[STR_LEN], date[STR_LEN], time[STR_LEN];
	printf("\t\t列车车次(%d个字符以内):", STR_LEN);
	scanf("%s", trainId);
	printf("\t\t列车出发日期(%d个字符以内):", STR_LEN);
	scanf("%s", date);
	printf("\t\t列车出发时间(%d个字符以内):", STR_LEN);
	scanf("%s", time);
	for (; i < end; i++) {
		t.ticket[i].stationId = stationId;
		t.ticket[i].seatId = rand() / 100; 
		t.ticket[i].ticketId = rand()% 10000;
		strcpy(t.ticket[i].date, date);
		strcpy(t.ticket[i].time, time);
		strcpy(t.ticket[i].trainId, trainId);
		t.count++;
	}
}

void deleteTicket(int stationId, Ticket& t) {  //删除站点对应的车票信息
	int i, j;
	for (i = 0; i < t.count; i++) {
		if (t.ticket[i].stationId == stationId) {
			for (j = i; j < t.count; j++)
				t.ticket[j] = t.ticket[j + 1];
		}
	}
}

void showSaledTickets(Book b) {           //显示已售车票
	int i;
	printf("\t\t售票情况如下:\n");
	printf("\t\t--------------------------\n");
	printf("\t订票号\t车次(t出发日期\t出发时间\t座号\t订票人\n");
	printf("\t\t--------------------------\n");
	for (i = 0; i < b.count; i++) {
		printf("\t\t%d\t%d\t%s\t%s\t%d\t%s\n", b.book[i].autoId,
			b.book[i].ticketInfo.ticketId, b.book[i].ticketInfo.date,
			b.book[i].ticketInfo.time, b.book[i].ticketInfo.seatId,
			b.book[i].name);
		printf("\t\t-----------------------\n");
	}
}
void showOnsaledTickets(Station& s) {      //显示待售车票
	printStation(s);
	_getch();
}