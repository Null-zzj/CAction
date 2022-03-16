#include"huochedingpiao.h"
//车站管理
void stationManage(Station& station, Ticket& ticket, Book& book, int& flag) {
	int option, i = 0;
	printf("\t\t***************************\n");
	printf("\t\t\t查看车站信息------------1\n");
	printf("\t\t\t添加车站信息------------2\n");
	printf("\t\t\t修改车站信息------------3\n"); 			//要求修改票价和余票量
	printf("\t\t\t删除车站信息------------4\n");
	printf("\t\t\t返回上一级菜单----------5\n");
	printf("\t\t***************************\n");
	printf("\t\t请选择:");
	scanf("%d", &option);
	switch (option) {
	case 1:
		printStation(station);
		break;
	case 2:
		printf("请输入添加添加车站信息的个数：");
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
		printf("\n选择出错! \n");
		break;
	}
}

void addStation(Station& s, Ticket& t, int snum) {//添加站点 //snum: 添加车站的数量
	int i = s.count;
	int end = s.count + snum;
	printf("\n请输入%d个车站信息:\n", snum);
	for (; i < end; i++) {
		printf("------------------------\n");
		printf("\n请输人第%d个车站信息", snum);
		printf("\tl.请输人起始站名称:\t");
		scanf("%s", &s.station[i].from);
		printf("\t2.请输人终点站名称:\t");
		scanf("%s", &s.station[i].to);
		printf("\t3.请输人票价:\t\t");
		scanf("%d", &s.station[i].money);
		printf("\t4.请输人票数:\t\t");
		scanf("%d", &s.station[i].numbers);
		s.station[i].stationId = rand()%1000;
		printf("\n\t5.请添加票务信息:\n");
		addTicket(s.station[i].stationId, s.station[i].numbers, t);
		printf("**第%d个车站信息和票务信息添加记录成功!**\n",i+1);
		printf("----------------------------------\n");
		s.count++;
	}
}
void printStation(Station& s) {	//函数功能:打印站点信息
	int i;
	printf("\nit\t车站编号\t起站\t终站\t票价\t剩余票数\n");
	printf("\t\t-------------------------------\n");
	for (i = 0; i < s.count; i++) {
		if (!s.station[i].stationId) {
			printf("无车站信息! \n");
			break;
		}
		printf("\t\t%d\t%s\t%s\t%d\t%d\n", s.station[i].stationId, s.station[i].from, s.station[i].to, s.station[i].money, s.station[i].numbers);
		printf("\t\t-------------------------------\n");
	}
}

void updateStation(Station &s,Ticket &t) {		//更新车站信息
	int stationId;
	printStation(s);
	printf("选择要修改的车站序号:");
	scanf("%d", &stationId);
}
