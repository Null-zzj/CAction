#include"huochedingpiao.h"
//��Ʊ����

void ticketManage(Station& station, Ticket& ticket, Book& book, int& flag) {
	int option;
	printf("\t\t************************\n");
	printf("\t\t\t���۳�Ʊ-------------1\n");
	printf("\t\t\tʣ�೵Ʊ-------------2\n");
	printf("\t\t\t������һ����---------0\n");
	printf("\t\t************************\n");
	printf("\t\t��ѡ��:");
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
		printf("\nѡ�����! \n");
		ticketManage(station, ticket, book, flag);
		break;
	}
}

void addTicket(int stationId, int number, Ticket& t) {
	int i = t.count;
	int end = t.count + number;
	char trainId[STR_LEN], date[STR_LEN], time[STR_LEN];
	printf("\t\t�г�����(%d���ַ�����):", STR_LEN);
	scanf("%s", trainId);
	printf("\t\t�г���������(%d���ַ�����):", STR_LEN);
	scanf("%s", date);
	printf("\t\t�г�����ʱ��(%d���ַ�����):", STR_LEN);
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

void deleteTicket(int stationId, Ticket& t) {  //ɾ��վ���Ӧ�ĳ�Ʊ��Ϣ
	int i, j;
	for (i = 0; i < t.count; i++) {
		if (t.ticket[i].stationId == stationId) {
			for (j = i; j < t.count; j++)
				t.ticket[j] = t.ticket[j + 1];
		}
	}
}

void showSaledTickets(Book b) {           //��ʾ���۳�Ʊ
	int i;
	printf("\t\t��Ʊ�������:\n");
	printf("\t\t--------------------------\n");
	printf("\t��Ʊ��\t����(t��������\t����ʱ��\t����\t��Ʊ��\n");
	printf("\t\t--------------------------\n");
	for (i = 0; i < b.count; i++) {
		printf("\t\t%d\t%d\t%s\t%s\t%d\t%s\n", b.book[i].autoId,
			b.book[i].ticketInfo.ticketId, b.book[i].ticketInfo.date,
			b.book[i].ticketInfo.time, b.book[i].ticketInfo.seatId,
			b.book[i].name);
		printf("\t\t-----------------------\n");
	}
}
void showOnsaledTickets(Station& s) {      //��ʾ���۳�Ʊ
	printStation(s);
	_getch();
}