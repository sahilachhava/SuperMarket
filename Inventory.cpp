#include "Inventory.h"

Inventory::Inventory(int _orderNumber, string _orderType, int _totalNoOfProducts, int _productIDs[], int _productQtys[], double _totalCost) 
{
    productIDs = _productIDs;
    productQtys = _productQtys;
    orderNumber = _orderNumber;
    orderType = _orderType;
    totalNoOfProducts = _totalNoOfProducts;
    totalCostOfProducts = _totalCost;
}

Inventory::~Inventory()
{
    //Releasing the memory of productID and productQty
    delete productIDs;
    delete productQtys;
}

int Inventory::getOrderNumber()
{
    return orderNumber;
}

string Inventory::getOrderType()
{
    return orderType;
}

int Inventory::getTotalNoOfProducts()
{
    return totalNoOfProducts;
}

int* Inventory::getProductIDs()
{
    return productIDs;
}

int* Inventory::getProductQtys()
{
    return productQtys;
}

double Inventory::getCostOfProducts() {
    return totalCostOfProducts;
}
