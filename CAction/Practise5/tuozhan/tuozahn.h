#pragma once
#include<stdio.h>
typedef struct {
	int year;
	int mon;
	int day;
}date;

typedef struct {
	int Jan;
	int Feb1;
	int Feb2;
	int Mar;
	int Apr;
	int May;
	int Jun;
	int Jul;
	int Aug;
	int Sep;
	int Oct;
	int Nov;
	int Dec;
}month;
int days(date day);
void riqijisuan();
int days(date day);