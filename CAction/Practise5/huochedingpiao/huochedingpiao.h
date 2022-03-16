#pragma once
#ifndef _TICKET_H
#define _TICKET_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#define STATION_NUM 100
#define TICKET_NUM 1000
#define STR_LEN 11
typedef struct {
	int stationId;
	char from[STR_LEN];							//��Ʊ���
	char to[STR_LEN];							//��Ʊ�յ�
	int money;									//Ʊ��
	int numbers;								//Ʊ��
}StationInfo;									//��վƱ����Ϣ

typedef struct {
	StationInfo station[STATION_NUM];           //�ṹ������
	int count;                                  //������
}Station;

typedef struct {
	int stationId;                              //��վ��
	int seatId;                                 //��λ�ţ���Ʊ�����
	int ticketId;                               //��Ʊ���
	char trainId[STR_LEN];                      //�𳵳���
	char date[STR_LEN];                         //��������
	char time[STR_LEN];                         //����ʱ��
}TicketInfo;                                    //��Ʊ��Ϣ

typedef struct {
	TicketInfo ticket[TICKET_NUM];
	int count;
}Ticket;

typedef struct {
	int autoId;                                 //������ɵĶ�Ʊ��,��Ʊʹ��
	char name[STR_LEN];							//��Ʊ������
	TicketInfo ticketInfo;						//��Ʊ��Ϣ
}Bookinfo;

typedef struct {
	Bookinfo book[TICKET_NUM];
	int count;
}Book;

/*����ģ���ļ��õ��ĺ���ģ��*/
void huochedingpiao();                          //�ӿں���
void start(int &flag);							//ϵͳ��ʼ����
void initialize(Station &station, Ticket &ticket);

/*ϵͳ����ģ���ļ�systemManage. c�õ��ĺ���ģ��*/
void systemManage(Station &station, Ticket &ticket, Book &book, int &flag);

/*վ�����ģ���ļ�stationManage.C�õ��ĺ���ģ��*/
void addStation(Station& station, Ticket& ticket, int i);                        //��ӳ�վ
void printStation(Station& station);//��ʾ��վ��Ϣ
void stationManage(Station& station, Ticket &ticket, Book &book, int &flag);     //վ�����
void updateStation(Station& station, Ticket &sticket);						   //���³�վ��Ϣ
void updateTicketltPrice(Station& s, int stationId);						   //���³�Ʊ�۸�
void updateTicketNum(Station &s, int stationId, Ticket &t);					   //���³�Ʊ����

/*Ʊ�����ģ���ļ�ticketManage. c*/
void addTicket(int stationId, int count, Ticket& ticket);                       //��ӳ�Ʊ��Ϣ
void deleteTicket(int stationId, Ticket& ticket);
void showOnsaledTickets(Station& station);										//��ʾ���۳�Ʊ
void showSaledTickets(Book b);													//��ʾ���۳�Ʊ
void ticketManage(Station& station, Ticket& ticket, Book& book, int& flag);     //Ʊ�����

/*�ͻ�Ʊ�����ģ���ļ�ticketServices. c�õ��ĺ���ģ��*/
void ticketBook(Book& book, Ticket& ticket, Station& s);							//��Ʊ
void addBookInfo(Book& b, Ticket& t, int stationId, int bookNum);				//��Ӷ�Ʊ��Ϣ
void ticketInquire(Station s, Ticket ticket);									//��ѯƱ����Ϣ
void ticketServices(Station& s, Ticket& t, Book& b, int& flag);					//Ʊ�����
#endif