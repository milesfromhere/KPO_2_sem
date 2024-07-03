#include "stdafx.h"

int Finding_number_day(int day, int month, int year) {
	int day_month_not[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day_month_yes[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day_number = 0;
	if (year % 4 == 0) {
		for (int i = 0; i < month - 1; i++) {
			day_number = day_month_yes[i];
		}
	}
	else {
		for (int i = 0; i < month - 1; i++) {
			day_number += day_month_not[i];
		}
	}
	day_number += day;
	return day_number;
}