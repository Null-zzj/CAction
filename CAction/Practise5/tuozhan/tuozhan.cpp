#include"tuozahn.h"
month Mon = { 31,28,29,31,30,31,30,31,31,30,31,30,31 };
void riqijisuan() {
	date input;
	int day;
	printf("����������(��,��,��. �ÿո����):\n");
	scanf("%d%d%d", &input.year, &input.mon, &input.day);
	day = days(input);
	if (day == 0) {
		printf("��������,���鲢��������!\n");
	}
	else {
		printf("%d/%d/%d����һ��ĵ�%d��\n",input.year,input.mon,input.day,day);
	}


}

int days(date day) {
	int day1;
	if (((day.year % 4 == 0) && (day.year % 100 != 0)) || day.year % 400 == 0){
		switch (day.mon) {
		case 1:
			if (day.day > 31)
				return 0;
			day1 = day.day;
			break;
		case 2:
			if (day.day > 28)
				return 0;
			day1 = Mon.Jan + day.day;
			break;
		case 3:
			if (day.day > 31)
				return 0;
			day1 = Mon.Jan +Mon.Feb1 + day.day;
			break;
		case 4:
			if (day.day > 30)
				return 0;
			day1 = Mon.Jan + Mon.Feb1 +Mon.Mar + day.day;
			break;
		case 5:
			if (day.day > 31)
				return 0;
			day1 = Mon.Jan + Mon.Feb1 + Mon.Mar + Mon.Apr + day.day;
			break;
		case 6:
			if (day.day > 30)
				return 0;
			day1 = Mon.Jan + Mon.Feb1 + Mon.Mar + Mon.Apr +Mon.May + day.day;
			break;
		case 7:
			if (day.day > 31)
				return 0;
			day1 = Mon.Jan + Mon.Feb1 + Mon.Mar + Mon.Apr + Mon.May + Mon.Jun + day.day;
			break;
		case 8:
			if (day.day > 31)
				return 0;
			day1 = Mon.Jan + Mon.Feb1 + Mon.Mar + Mon.Apr + Mon.May + Mon.Jun +Mon.Jul + day.day;
			break;
		case 9:if (day.day > 30)
			return 0;
			day1 = Mon.Jan + Mon.Feb1 + Mon.Mar + Mon.Apr + Mon.May + Mon.Jun + Mon.Jul + Mon.Aug + day.day;
			break;
		case 10:
			if (day.day > 31)
				return 0;
			day1 = Mon.Jan + Mon.Feb1 + Mon.Mar + Mon.Apr + Mon.May + Mon.Jun + Mon.Jul + Mon.Oct + Mon.Sep + day.day;
			break;
		case 11:
			if (day.day > 30)
				return 0;
			day1 = Mon.Jan + Mon.Feb1 + Mon.Mar + Mon.Apr + Mon.May + Mon.Jun + Mon.Jul + Mon.Oct + Mon.Sep + Mon.Oct + day.day;
			break;
		case 12:
			if (day.day > 31)
				return 0;
			day1 = Mon.Jan + Mon.Feb1 + Mon.Mar + Mon.Apr + Mon.May + Mon.Jun + Mon.Jul + Mon.Oct + Mon.Sep + Mon.Oct + Mon.Nov + day.day;
			break;
		default: 
			return 0;
		}
	}
	else {
		switch (day.mon) {
		case 1:
			if (day.day > 31)
				return 0;
			day1 = day.day;
			break;
		case 2:
			if (day.day > 29)
				return 0;
			day1 = Mon.Jan + day.day;
			break;
		case 3:
			if (day.day > 31)
				return 0;
			day1 = Mon.Jan + Mon.Feb1 + day.day;
			break;
		case 4:
			if (day.day > 30)
				return 0;
			day1 = Mon.Jan + Mon.Feb1 + Mon.Mar + day.day;
			break;
		case 5:
			if (day.day > 31)
				return 0;
			day1 = Mon.Jan + Mon.Feb1 + Mon.Mar + Mon.Apr + day.day;
			break;
		case 6:
			if (day.day > 30)
				return 0;
			day1 = Mon.Jan + Mon.Feb1 + Mon.Mar + Mon.Apr + Mon.May + day.day;
			break;
		case 7:
			if (day.day > 31)
				return 0;
			day1 = Mon.Jan + Mon.Feb1 + Mon.Mar + Mon.Apr + Mon.May + Mon.Jun + day.day;
			break;
		case 8:
			if (day.day > 31)
				return 0;
			day1 = Mon.Jan + Mon.Feb1 + Mon.Mar + Mon.Apr + Mon.May + Mon.Jun + Mon.Jul + day.day;
			break;
		case 9:if (day.day > 30)
			return 0;
			day1 = Mon.Jan + Mon.Feb1 + Mon.Mar + Mon.Apr + Mon.May + Mon.Jun + Mon.Jul + Mon.Aug + day.day;
			break;
		case 10:
			if (day.day > 31)
				return 0;
			day1 = Mon.Jan + Mon.Feb1 + Mon.Mar + Mon.Apr + Mon.May + Mon.Jun + Mon.Jul + Mon.Oct + Mon.Sep + day.day;
			break;
		case 11:
			if (day.day > 30)
				return 0;
			day1 = Mon.Jan + Mon.Feb1 + Mon.Mar + Mon.Apr + Mon.May + Mon.Jun + Mon.Jul + Mon.Oct + Mon.Sep + Mon.Oct + day.day;
			break;
		case 12:
			if (day.day > 31)
				return 0;
			day1 = Mon.Jan + Mon.Feb1 + Mon.Mar + Mon.Apr + Mon.May + Mon.Jun + Mon.Jul + Mon.Oct + Mon.Sep + Mon.Oct + Mon.Nov + day.day;
			break;
		default:
			return 0;
		}
	}
	return day1;
	
}