#include "Products.h"

Products::Products(int _productID, string _productName, INFINITE _productStock, double _productPrice)
{
	productID = _productID;
	productName = _productName;
	productStock = _productStock;
	productPrice = _productPrice;
}

int Products::getProductID()
{
	return productID;
}

string Products::getProductName()
{
	return productName;
}

INFINITE Products::getProductStock()
{
	return productStock;
}

double Products::getProductPrice()
{
	return productPrice;
}

bool Products::setProductStock(INFINITE _productStock)
{
	if (_productStock < 0) {
		return false;
	}
	else {
		productStock = _productStock;
		return true;
	}
}
