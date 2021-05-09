#include "Warehouse.h"

Warehouse::Warehouse()
{
	//Initializing Member Variable
	const int TOTAL_PRODUCTS = 6;
	allProducts = new Products*[TOTAL_PRODUCTS];
	totalNumberOfProducts = 0;

	//Static Product Data
	int productIDs[] = { 1001, 1002, 1003, 1004, 1005, 1006 };
	string productNames[] = { "Chocalate", "Milk", "Coffee", "Sugar", "Biscuits", "Noodles" };
	int productQtys[] = { 90, 25, 50, 15, 200, 75 };
	int productPrices[] = { 70, 50, 60, 40, 25, 45 };

	//Adding static data into our main Array
	for (int index = 0; index < TOTAL_PRODUCTS; index++) {
		allProducts[index] = new Products(productIDs[index], productNames[index], productQtys[index], productPrices[index]);
		totalNumberOfProducts++;
	}
}

Warehouse::~Warehouse()
{
	for (int i = 0; i < totalNumberOfProducts; i++) {
		delete allProducts[i];
	}

	delete[] allProducts;
}

int Warehouse::getTotalNumberOfProducts()
{
	return totalNumberOfProducts;
}

Products** Warehouse::getAllProducts()
{
	return allProducts;
}

Products* Warehouse::getProduct(int _productID)
{
	for (int i = 0; i < totalNumberOfProducts; i++) {
		if (allProducts[i]->getProductID() == _productID) {
			return allProducts[i];
			break;
		}
	}
	return nullptr;
}











