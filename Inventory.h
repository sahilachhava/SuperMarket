#pragma once
#include "Warehouse.h"
#include <string>
using namespace std;

class Inventory : public Warehouse
{
	private:
		int orderNumber;
		string orderType;
		int totalNoOfProducts;
		int* productIDs;
		int* productQtys;
		double totalCostOfProducts;
	
	public:
		//Constructors
		Inventory(int _orderNumber, string _orderType, int _totalNoOfProducts, int _productIDs[], int _productQtys[], double _totalCost);
		~Inventory();

		//Getter Methods
		int getOrderNumber();
		string getOrderType();
		int getTotalNoOfProducts();
		int* getProductIDs();
		int* getProductQtys();
		double getCostOfProducts();
};

