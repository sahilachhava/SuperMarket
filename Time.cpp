#pragma once
#include "Time.h"
#include "Utility.h"

Time::Time() {
	timeConvention = "AM";

	struct tm now = Utility::getCurrentTime();

	currentSecond = now.tm_sec;
	currentMinute = now.tm_min;

	if (now.tm_hour >= 12) {
		//PM 
		if (now.tm_hour == 12) {
			currentHour = now.tm_hour;
		}
		else {
			currentHour = now.tm_hour - 12;
		}
		timeConvention = "PM";
	}
	else {
		//AM
		if (now.tm_hour == 0) {
			currentHour = 12;
		}
		else {
			currentHour = now.tm_hour;
		}
	}
}

Time::Time(int _currentHour, int _currentMinute, int _currentSecond, string _timeConvention)
{
	currentHour = _currentHour;
	currentMinute = _currentMinute;
	currentSecond = _currentSecond;
	timeConvention = _timeConvention;
}

int Time::getHour()
{
	return currentHour;
}

int Time::getMinute()
{
	return currentMinute;
}

int Time::getSecond()
{
	return currentSecond;
}

string Time::getTimeConvention()
{
	return timeConvention;
}

string Time::getTime()
{
	string time = "";
	if (currentHour < 10) {
		time += "0" + to_string(currentHour) + ":";
	}
	else {
		time += to_string(currentHour) + ":";
	}

	if (currentMinute < 10) {
		time += "0" + to_string(currentMinute) + ":";
	}
	else {
		time += to_string(currentMinute) + ":";
	}

	if (currentSecond < 10) {
		time += "0" + to_string(currentSecond) + " ";
	}
	else {
		time += to_string(currentSecond) + " ";
	}

	time += timeConvention;

	return time;
}
