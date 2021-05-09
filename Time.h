#pragma once
#include <string>
using namespace std;
class Time
{
	private:
		int currentHour;
		int currentMinute;
		int currentSecond;
		string timeConvention;

	public:
		//Constructor
		Time();
		Time(int _currentHour, int _currentMinute, int _currentSecond, string _timeConvention);

		//Getter Methods
		int getHour();
		int getMinute();
		int getSecond();
		string getTimeConvention();
		string getTime();
};

