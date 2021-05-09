#pragma once
#include "Utility.h"
#include "Warehouse.h"
#include "Time.h"
#include "Inventory.h"

struct SSNMart
{
	Time* currentTime;
	Time* lastPaymentTime;
	Warehouse* warehouse;
	Inventory** allOrders;

	//Member Variables for Keep Track of Counts
	int totalOrders;
	double totalEmployeePayment;
	double wagePerMinute;

	//Constructor
	SSNMart();
	~SSNMart();

	//Setter Methods
	void setLastPaymentTime(Time* _lastPaymentTime);
	void setEmployeeSalary(double _newTotalSalaryAmount);

	//Getter Methods
	Inventory** getAllOrders();
	int getNoOfOrdersByType(string _orderType);
	double getCostOfOrdersByType(string _orderType);
	double getTotalPaidSalary();
	double getWagePerMinute();
	double getTotalExpenses();
	double getNetProfit();
	int getProductIDByName(string _productName);

	//Other Methods
	void addNewOrder(Inventory* _newOrder);
	bool createNewOrder(string _orderType);
	void searchProduct();
	bool paySalary();
};

//Single Instance of Mart to manage all the functionalities in the system
static SSNMart manageMart; //globally declared
