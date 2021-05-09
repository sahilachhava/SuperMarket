#pragma once
#include <string>
using std::string;

//Infinite Space 
typedef unsigned int INFINITE;

class Products
{
	private:
		int productID;
		string productName;

	public:
		INFINITE productStock;
		double productPrice;

		//Constructors
		Products(int _productID, string _productName, INFINITE _productStock, double _productPrice);

		//Getter Functions
		int getProductID();
		string getProductName();
		INFINITE getProductStock();
		double getProductPrice();

		//Setter Functions
		bool setProductStock(INFINITE _productStock);
};

