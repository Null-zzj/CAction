#include"huochedingpiao.h"
void ticketServices(Station& s, Ticket& t, Book& b, int& flag) {
	int option;
	printf("\t\t************************\n");
	printf("\t\t\t查询车票-------------1\n");
	printf("\t\t\t预订车票-------------2\n");
	printf("\t\t\t退订车票-------------3\n");
	printf("\t\t\t返回上级菜单---------0\n");
	printf("\t\t************************\n");
	printf("\t\t请选择:");
	scanf("%d", &option);
	switch (option) {
	case 1:
		ticketInquire(s, t);
		break;
	case 2:
		ticketBook(b, t, s);
		break;
	case 3://退票服务;
		break;
	case 0:
		flag = 0;
		start(flag);
		break;
	default:
		printf("\n选择出错!\n");
		ticketServices(s, t, b, flag);
		break;
	}
}

void ticketInquire(Station s, Ticket t) {
	int i, k, j = 0;
	char from[STR_LEN], to[STR_LEN];
	char time[STR_LEN], date[STR_LEN], begin[STR_LEN], end[STR_LEN];
	int numbers, money, stationId;
	printf("\t请输人查询起点站名称:\t");
	scanf("%s", from);
	printf("\t请输人查询终点站名称:\t");
	scanf("%s", to);
	printf("\t站点序号\t起站\t终站\t日期C\t时间比票数:价格\n");
	printf("-----------------------------------------------------------\n");
	for (i = 0; i < s.count; i++) {
		if (strcmp(s.station[i].from, from) == 0 && strcmp(s.station[i].to, to) == 0) {
			stationId = s.station[i].stationId;
			numbers = s.station[i].numbers;
			money = s.station[i].money;
			strcpy(begin, from);
			strcpy(end, to);
			for (k = 0; k < t.count; k++) {
				if (t.ticket[k].stationId == stationId) {
					strcpy(time, t.ticket[k].time);
					strcpy(date, t.ticket[k].date);
					j++;
					break;
				}
			}
		}
	if (j) break;
	}
	printf("\t%d\t\t%s\t%s\t%s\t%s\t%d\t%d\n", stationId, begin, end, date, time, numbers, money);
	printf("\t-------------------------------------------------------");
}

//根据stationId 订购车票

void ticketBook(Book& b, Ticket& t, Station& s) {
	int i, stationId, bookNum;
	printStation(s);
	printf("\t\t请输人订票的车站编号:");
	scanf("%d", &stationId);
	printf("\t\t请输人订票数量:");
	scanf("%d", &bookNum);
	for (i = 0; i < s.count; i++) {
		if (s.station[i].stationId == stationId && s.station[i].numbers >= bookNum) {
			addBookInfo(b, t, stationId, bookNum);
			s.station[i].numbers -= bookNum;               //订票成功以后,剩余车票数量减去订票数量
		}
	}
}

//添加订票信息
void addBookInfo(Book& b, Ticket& t, int stationId, int bookNum) {
	int j, i = b.count, end = b.count + bookNum;
	for (; i < end; i++) {
		b.book[i].autoId = rand() % 10000;
		printf("\t\t订票人姓名(%d个字符以内) :", STR_LEN);
		scanf("%s", b.book[i].name);
		printf("\t\t%s的订票号为%d:\n", b.book[i].name, b.book[i].autoId);
		for (j = 0; j < t.count; j++) {
			if (t.ticket[j].stationId == stationId) {
				strcpy(b.book[i].ticketInfo.date, t.ticket[j].date);
				strcpy(b.book[i].ticketInfo.time, t.ticket[j].time);
				strcpy(b.book[i].ticketInfo.trainId, t.ticket[j].trainId);
				b.book[i].ticketInfo.ticketId = t.ticket[i].ticketId;
				b.book[i].ticketInfo.seatId = t.ticket[j].seatId;
				b.book[i].ticketInfo.stationId = t.ticket[j].stationId;
			}
			b.count++;
		}
	}
}