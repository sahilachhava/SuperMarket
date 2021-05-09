#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip> //for setw() which will be used for setting width of text
#include <algorithm> //for transforming text to lowercase or uppercase

using namespace std;

class Utility
{
	public:
		//Getting Current Time
		static struct tm getCurrentTime();

		//Data Getter Methods
		static int getInt(string message);
		static int getMenuChoice(int min, int max, string message, string errorMessage);
		static double getDouble(string message);
		static string getString(string message);

		//Screen UIs Methods
		static void headerUI(string _screenTitle);
		static void overviewScreen();
		static void mainMenuScreen();
		static void warehouseScreen();
		static void showProducts();
		static void showOrders();
};

