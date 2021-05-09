#pragma once
#include "Products.h"

class Warehouse
{
	private:
		Products** allProducts;
		int totalNumberOfProducts;

	public:
		//Constructors
		Warehouse();
		~Warehouse();

		//Getter Methods
		int getTotalNumberOfProducts();
		Products** getAllProducts();
		Products* getProduct(int _productID);
};

