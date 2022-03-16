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
	char from[STR_LEN];							//车票起点
	char to[STR_LEN];							//车票终点
	int money;									//票价
	int numbers;								//票数
}StationInfo;									//车站票务信息

typedef struct {
	StationInfo station[STATION_NUM];           //结构体数组
	int count;                                  //计数器
}Station;

typedef struct {
	int stationId;                              //车站号
	int seatId;                                 //座位号，与票数相关
	int ticketId;                               //车票编号
	char trainId[STR_LEN];                      //火车车次
	char date[STR_LEN];                         //出发日期
	char time[STR_LEN];                         //出发时间
}TicketInfo;                                    //车票信息

typedef struct {
	TicketInfo ticket[TICKET_NUM];
	int count;
}Ticket;

typedef struct {
	int autoId;                                 //随机生成的订票号,退票使用
	char name[STR_LEN];							//订票人姓名
	TicketInfo ticketInfo;						//定票信息
}Bookinfo;

typedef struct {
	Bookinfo book[TICKET_NUM];
	int count;
}Book;

/*主调模块文件用到的函数模块*/
void huochedingpiao();                          //接口函数
void start(int &flag);							//系统开始函数
void initialize(Station &station, Ticket &ticket);

/*系统管理模块文件systemManage. c用到的函数模块*/
void systemManage(Station &station, Ticket &ticket, Book &book, int &flag);

/*站点管理模块文件stationManage.C用到的函数模块*/
void addStation(Station& station, Ticket& ticket, int i);                        //添加车站
void printStation(Station& station);//显示车站信息
void stationManage(Station& station, Ticket &ticket, Book &book, int &flag);     //站点管理
void updateStation(Station& station, Ticket &sticket);						   //更新车站信息
void updateTicketltPrice(Station& s, int stationId);						   //更新车票价格
void updateTicketNum(Station &s, int stationId, Ticket &t);					   //更新车票数量

/*票务管理模块文件ticketManage. c*/
void addTicket(int stationId, int count, Ticket& ticket);                       //添加车票信息
void deleteTicket(int stationId, Ticket& ticket);
void showOnsaledTickets(Station& station);										//显示待售车票
void showSaledTickets(Book b);													//显示已售车票
void ticketManage(Station& station, Ticket& ticket, Book& book, int& flag);     //票务管理

/*客户票务服务模块文件ticketServices. c用到的函数模块*/
void ticketBook(Book& book, Ticket& ticket, Station& s);							//订票
void addBookInfo(Book& b, Ticket& t, int stationId, int bookNum);				//添加订票信息
void ticketInquire(Station s, Ticket ticket);									//查询票务信息
void ticketServices(Station& s, Ticket& t, Book& b, int& flag);					//票务服务
#endif