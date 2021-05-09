#include "SSNMart.h"

int main()
{
    int menuChoice = 0, actionFlag = false;

	Utility::overviewScreen();

    do {
        Utility::mainMenuScreen();

        menuChoice = Utility::getMenuChoice(1, 5, string(25, ' ') + "Enter Your Choice -> ", string(25, ' ') + "Error: Invalid Option Selected");

        switch (menuChoice) {
            case 1: 
                manageMart.searchProduct();
                break;
            case 2:
                Utility::warehouseScreen();
                break;
            case 3:
                actionFlag = manageMart.paySalary();
                if (!actionFlag) {
                    cout << endl << string(30, ' ') << "Error: Something Went Wrong!" << endl;
                }
                else {
                    cout << endl << string(30, ' ') << "Success: Salary Paid Successfully!" << endl;
                }
                cout << endl;
                system("pause");
                break;
            case 4:
                main();
                break;
            case 5:
                cout << endl << string(30, ' ') << "Thank you for using the system." << endl << endl;
                exit(0);
                break;
            default:
                cout << endl << string(30, ' ') << "Invalid Choice!" << endl << endl;
                break;
        }
    } while (menuChoice != 5);

	return 0;
}

//Overview Screen UI
void Utility::overviewScreen()
{
    Utility::headerUI("*******" + string(32, ' ') + "Overview" + string(30, ' ') + "*******");
    cout << "*******  " << "Total Items Bought:\t" << manageMart.getNoOfOrdersByType("Buy") << setw(28) << "Total Expenses:  $" << manageMart.getTotalExpenses() << setw(18) << "  *******" << endl;
    cout << "*******" << string(70, ' ') << "*******" << endl;
    cout << "*******  " << "Cost of Purchased:\t$" << manageMart.getCostOfOrdersByType("Buy") << setw(26) << "Total Salary Paid:  $" << manageMart.getTotalPaidSalary() << setw(19) << "  *******" << endl;
    cout << "*******" << string(70, ' ') << "*******" << endl;
    cout << "*******  " << "Total Items Sold:\t" << manageMart.getNoOfOrdersByType("Sell") << setw(30) << "Total Net Profit:  $" << manageMart.getNetProfit() << setw(15) << " *******" << endl;
    cout << "*******" << string(70, ' ') << "*******" << endl;
    cout << "*******  " << "Cost of Sales:\t\t$" << manageMart.getCostOfOrdersByType("Sell") << setw(50) << "  *******" << endl;
    cout << "*******" << string(70, ' ') << "*******" << endl;
    cout << "*******" << string(18, ' ') << "Press any key to visit Main Menu..." << string(17, ' ') << "*******" << endl;
    cout << "*******" << string(70, ' ') << "*******" << endl;
    cout << string(84, '*') << endl;
    cout << string(84, '*') << endl;
    system("pause");
}

//Manage Warehouse UI
void Utility::warehouseScreen()
{
    int menuChoice = 0, actionFlag = false;
    do {
        Utility::headerUI("*******" + string(27, ' ') + "Manage Warehouse" + string(27, ' ') + "*******");
        cout << "*******  " << string(23, ' ') << "1. Show Product" << string(28, ' ') << "  *******" << endl;
        cout << "*******  " << string(23, ' ') << "2. Buy Inventory" << string(27, ' ') << "  *******" << endl;
        cout << "*******  " << string(23, ' ') << "3. Sell Inventory" << string(26, ' ') << "  *******" << endl;
        cout << "*******  " << string(23, ' ') << "4. Show Inventory" << string(26, ' ') << "  *******" << endl;
        cout << "*******  " << string(23, ' ') << "5. Back to Main Menu" << string(23, ' ') << "  *******" << endl;
        cout << "*******" << string(70, ' ') << "*******" << endl;
        cout << string(84, '*') << endl;
        cout << string(84, '*') << endl;
        cout << endl << endl;

        menuChoice = Utility::getMenuChoice(1, 5, string(25, ' ') + "Enter Your Choice -> ", string(25, ' ') + "Error: Invalid Option Selected");

        switch (menuChoice) {
        case 1:
            showProducts();
            break;
        case 2:
            actionFlag = manageMart.createNewOrder("Buy");
            if (!actionFlag) {
                cout << endl << string(30, ' ') << "Error: Something Went Wrong!" << endl;
            }
            else {
                cout << endl << string(30, ' ') << "Success: Inventory Bought Successfully!" << endl;
            }
            cout << endl;
            system("pause");
            break;
        case 3:
            actionFlag = manageMart.createNewOrder("Sell");
            if (!actionFlag) {
                cout << endl << string(30, ' ') << "Error: Something Went Wrong!" << endl;
            }
            else {
                cout << endl << string(30, ' ') << "Success: Inventory Sold Successfully!" << endl;
            }
            cout << endl;
            system("pause");
            break;
        case 4:
            showOrders();
            break;
        case 5:
            mainMenuScreen();
            break;
        default:
            cout << endl << string(30, ' ') << "Error: Invalid Choice" << endl << endl;
            break;
        }
    } while (menuChoice != 5);
}

void Utility::showProducts()
{
    Utility::headerUI("*******" + string(29, ' ') + "All Products" + string(29, ' ') + "*******");

    Products** products = manageMart.warehouse->getAllProducts();

    cout << "*******" << string(7, ' ') << "ID" << setw(20) << "Name" << setw(20) << "Stock" << setw(14) << "Price" << setw(14) << "*******" << endl;

    for (int index = 0; index < manageMart.warehouse->getTotalNumberOfProducts(); index++) {
        cout << "*******" << string(6, ' ') << products[index]->getProductID() << setw(20) << products[index]->getProductName() << setw(17) << products[index]->getProductStock() << setw(13) << "$" << products[index]->getProductPrice() << setw(15) << "*******" << endl;
    }
    cout << "*******" << string(70, ' ') << "*******" << endl;
    cout << "*******" << string(70, ' ') << "*******" << endl;
    cout << string(84, '*') << endl << endl;
    system("pause");
}

void Utility::showOrders()
{
    Utility::headerUI("*******" + string(30, ' ') + "All Orders" + string(30, ' ') + "*******");

    Inventory** orders = manageMart.getAllOrders();

    cout << "*******" << string(7, ' ') << "ID" << setw(20) << "Type" << setw(20) << "Total Products" << setw(14) << "Total Cost" << setw(14) << "*******" << endl;
    for (int index = 0; index < manageMart.totalOrders; index++) {
        cout << "*******" << string(7, ' ') << orders[index]->getOrderNumber() << setw(19) << orders[index]->getOrderType() << setw(12) << orders[index]->getTotalNoOfProducts() << setw(15) << "$" << orders[index]->getCostOfProducts() << setw(17) << "*******" << endl;
    }
    cout << "*******" << string(70, ' ') << "*******" << endl;
    cout << "*******" << string(70, ' ') << "*******" << endl;
    cout << string(84, '*') << endl << endl;
    system("pause");
}
