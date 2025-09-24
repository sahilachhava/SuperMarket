#include "SSNMart.h"

//Default Constructor
SSNMart::SSNMart()
{
	const int INITIAL_SIZE = 0;

	totalOrders = 0;
	wagePerMinute = 2600;
	totalEmployeePayment = 0;

	warehouse = new Warehouse();
	allOrders = new Inventory * [INITIAL_SIZE];
	currentTime = new Time();
	lastPaymentTime = new Time();

    int* productIDs = new int[6]{ 1001, 1002, 1003, 1004, 1005, 1006 };
    int* productQtys = new int[6]{ 90, 25, 50, 15, 200, 75 };

    Inventory* _buyOrder = new Inventory(101, "Buy", 6, productIDs, productQtys, 24025);
    addNewOrder(_buyOrder);
}

//Destructor
SSNMart::~SSNMart()
{
	//Deleting Inventories Orders from Heap
	for (int index = 0; index < totalOrders; index++) {
		delete allOrders[index];
	}
	delete[] allOrders;

	//Deleting Warehouse Object
	delete warehouse;

	//Deleting Time Objects
	delete currentTime;
	delete lastPaymentTime;
}

//Setter Method Defination
void SSNMart::setLastPaymentTime(Time* _lastPaymentTime)
{
	lastPaymentTime = _lastPaymentTime;
}

void SSNMart::setEmployeeSalary(double _newTotalSalaryAmount)
{
    totalEmployeePayment = _newTotalSalaryAmount;
}


//Getter Methods Definations
int SSNMart::getNoOfOrdersByType(string _orderType)
{
	int totalParticularProducts = 0;

	for (int index = 0; index < totalOrders; index++) {
		if (allOrders[index]->getOrderType() == _orderType) {
			totalParticularProducts += allOrders[index]->getTotalNoOfProducts();
		}
	}

	return totalParticularProducts;
}

Inventory** SSNMart::getAllOrders()
{
    return allOrders;
}

double SSNMart::getCostOfOrdersByType(string _orderType)
{
	double costOfParticularProducts = 0;
	
	for (int index = 0; index < totalOrders; index++) {
		if (allOrders[index]->getOrderType() == _orderType) {
			costOfParticularProducts += allOrders[index]->getCostOfProducts();
		}
	}

	return costOfParticularProducts;
}

double SSNMart::getTotalPaidSalary()
{
	return totalEmployeePayment;
}

double SSNMart::getWagePerMinute()
{
	return wagePerMinute;
}

double SSNMart::getTotalExpenses()
{
	return (getCostOfOrdersByType("Buy") + getTotalPaidSalary());
}

double SSNMart::getNetProfit()
{
	return (getCostOfOrdersByType("Sell") - getTotalExpenses());
}

int SSNMart::getProductIDByName(string _productName)
{
	transform(_productName.begin(), _productName.end(), _productName.begin(), ::tolower);
	Products** products = warehouse->getAllProducts();
	for (int index = 0; index < warehouse->getTotalNumberOfProducts(); index++) {
		string productName = products[index]->getProductName();
		transform(productName.begin(), productName.end(), productName.begin(), ::tolower);
		if (productName == _productName) {
			return products[index]->getProductID();
		}
	}

	return 0;
}

//Other Methods Defination
void SSNMart::addNewOrder(Inventory* _newOrder)
{
	Inventory** tempOrders = new Inventory * [totalOrders];
	for (int index = 0; index < totalOrders; index++) {
		tempOrders[index] = allOrders[index];
	}

	const int NEW_SIZE = totalOrders + 1;
	allOrders = new Inventory * [NEW_SIZE];
	for (int index = 0; index < totalOrders; index++) {
		allOrders[index] = tempOrders[index];
	}

	allOrders[totalOrders] = _newOrder;
	totalOrders++;

	delete[] tempOrders;
}

void SSNMart::searchProduct()
{
    Utility::headerUI("*******" + string(27, ' ') + "Search Product" + string(25, ' ') + "*******");

    int productID = 0;
    int selectOption = Utility::getMenuChoice(0, 1, "Search Product?\nIf by ID: Press (1), If By Name: Press (0) -> ", "Error: Please Enter Valid Option");

    Utility::getString(""); //works like cin.ignore();
    if (selectOption == 1) {
        productID = Utility::getMenuChoice(1001, warehouse->getTotalNumberOfProducts() + 1000, string(25, ' ') + "Enter Product ID -> ", string(25, ' ') + "Error: Enter valid product ID");
    }
    else {
        while (true) {
            productID = getProductIDByName(Utility::getString(string(25, ' ') + "Enter Product Name -> "));
            if (productID == 0) {
                cout << string(25, ' ') << "Error: Product Doesn't Exists" << endl;
            }
            else {
                break;
            }
        }
    }

    Products* selectedProduct = warehouse->getProduct(productID);
    int totalPurchaseQty = 0, totalSoldQty = 0;

    for (int index = 0; index < totalOrders; index++) {
        int* orderProductIDs = allOrders[index]->getProductIDs();
        int* orderProductQtys = allOrders[index]->getProductQtys();

        if (allOrders[index]->getOrderType() == "Buy") {
            for (int buyIndex = 0; buyIndex < allOrders[index]->getTotalNoOfProducts(); buyIndex++) {
                if (orderProductIDs[buyIndex] == productID) {
                    totalPurchaseQty += orderProductQtys[buyIndex];
                }
            }
        }
        else if(allOrders[index]->getOrderType() == "Sell") {
            for (int sellIndex = 0; sellIndex < allOrders[index]->getTotalNoOfProducts(); sellIndex++) {
                if (orderProductIDs[sellIndex] == productID) {
                    totalSoldQty += orderProductQtys[sellIndex];
                }
            }
        }
    }

    cout << "*******" << string(70, ' ') << "*******" << endl;
    cout << string(84, '*') << endl << endl;
    cout << "*******" << string(70, ' ') << "*******" << endl;
    cout << "*******" << string(10, ' ') << "Total Purchased (in Qty) -> " << setw(8) << totalPurchaseQty << string(24, ' ') << "*******" << endl;
    cout << "*******" << string(10, ' ') << "Total Sold (in Qty) -> " << setw(13) << totalSoldQty << string(24, ' ') << "*******" << endl;
    cout << "*******" << string(10, ' ') << "Current Stock (in Qty) -> " << setw(10) << selectedProduct->getProductStock() << string(24, ' ') << "*******" << endl;
    cout << "*******" << string(70, ' ') << "*******" << endl;
    cout << string(84, '*') << endl << endl;
    system("pause");
}

bool SSNMart::paySalary()
{
    Utility::headerUI("*******" + string(27, ' ') + "Employee Payment" + string(27, ' ') + "*******");

    int choice = 0;

    cout << "*******" << string(25, ' ') << "1. Pay Wage " << setw(40) << "*******" << endl;
    cout << "*******" << string(25, ' ') << "2. Back to Main Menu " << setw(31) << "*******" << endl;
    cout << "*******" << string(70, ' ') << "*******" << endl;
    cout << string(84, '*') << endl << endl;

    do {
        choice = Utility::getMenuChoice(1, 2, string(30, ' ') + "Enter Your Choice -> ", string(30, ' ') + "Please enter valid action.");

        if (choice == 1) {
            Time nowTime;
            int hour = nowTime.getHour(), minute = nowTime.getMinute(), totalSecond = 0;

            if ((nowTime.getHour() - lastPaymentTime->getHour()) != 0) {
                totalSecond += (nowTime.getHour() - lastPaymentTime->getHour()) * 60 * 60;
            }
            if ((nowTime.getMinute() - lastPaymentTime->getMinute()) != 0) {
                totalSecond += (nowTime.getMinute() - lastPaymentTime->getMinute()) * 60;
            }
            if ((nowTime.getSecond() - lastPaymentTime->getSecond()) != 0) {
                totalSecond += (nowTime.getSecond() - lastPaymentTime->getSecond());
            }

            if (totalSecond < 60) {
                cout << endl << string(30, ' ') << "It's not been a minute yet," << endl << string(30, ' ') << "Please try again after 1 minute" << endl;
                return false;
            }
            else {
                int newSecond = 0;
                string timeConvention = nowTime.getTimeConvention();
                int remainingSecond = totalSecond % 60; 
                if (nowTime.getSecond() < remainingSecond) {
                    newSecond = (nowTime.getSecond() + 60) - remainingSecond;
                    minute--;
                    if (minute < 0) {
                        hour--;
                        minute = 59;
                        if (hour == 11 && nowTime.getTimeConvention() == "AM") {
                            timeConvention = "PM";
                        }
                        else if (hour == 11 && nowTime.getTimeConvention() == "PM") {
                            timeConvention = "AM";
                        }
                    }
                }
                else {
                    newSecond = nowTime.getSecond() - remainingSecond;
                }
                /*
                    Worst Timing Possible for Paying Salary:

                    If last payment time is: 11:58:45 PM
                    the next cycle is: 11:59:45 PM
                    But we paid on 12:00:01 AM
                    Remaining Seconds = 16 (diffrence between 45 to 01)
                    Paid time second is 01 which is less then 45
                    NewSecond = (01+60) - 16 (diffrence) we will get exact cycle second 45
                    then we will decrese minute by -1, so it will be convert from 00 to -1
                    then check minute is less than 0, so it means hour also changed
                    then hour decrease by 1, and set minute to 59
                    so the time is now (12-1) so 11, then minute 59, and second 45
                    so we got 11:59:45 AM, then we change the convention
                    so if hour is 11 and current convention is AM, so we set PM
                    we got 11:59:45 PM as our last payment time.
                */

                Time* _newTime = new Time(hour, minute, newSecond, timeConvention);
                setLastPaymentTime(_newTime);
                setEmployeeSalary(getTotalPaidSalary() + ((totalSecond / 60) * getWagePerMinute()));

                cout << endl << string(30, ' ') << "Current Payment Time -> " << lastPaymentTime->getTime() << endl;
                cout << endl << string(30, ' ') << "Amount Paid ->  $" << ((totalSecond / 60) * getWagePerMinute()) << endl;
            }
            return true;
        }
        else {
            return false;
        }
    } while (choice != 2);
}
