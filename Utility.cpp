#include "SSNMart.h"

struct tm Utility::getCurrentTime()
{
    struct tm now;
    time_t nowTime = time(0);
    localtime_s(&now, &nowTime);
    return now;
}

int Utility::getInt(string message)
{
    int number;
    do {
        cout << message << " ";
        cin >> number;
        if (cin.fail() || cin.peek() != '\n') {
            cin.clear();
            cin.ignore(512, '\n');
            cout << "Error: Please enter integer only." << endl << endl;
        }
        else if (number < 0) {
            cout << "Error: Please enter positive integer only." << endl << endl;
        }
        else {
            break;
        }
    } while (true);
    return number;
}

int Utility::getMenuChoice(int min, int max, string message, string errorMessage)
{
    int number;
    do {
        cout << message << " ";
        cin >> number;
        if (cin.fail() || cin.peek() != '\n') {
            cin.clear();
            cin.ignore(512, '\n');
            cout << "Error: Please enter integer only." << endl << endl;
        }
        else if (number < 0) {
            cout << "Error: Please enter positive integer only." << endl << endl;
        }
        else if (number < min || number > max) {
            cout << errorMessage << endl << endl;
        }
        else {
            break;
        }
    } while (true);
    return number;
}

double Utility::getDouble(string message)
{
    double number;
    do {
        cout << message << " ";
        cin >> number;
        if (cin.fail() || cin.peek() != '\n') {
            cin.clear();
            cin.ignore(512, '\n');
            cout << "Error: Please enter doubles only." << endl << endl;
        }
        else if (number < 0) {
            cout << "Error: Please enter positive doubles only." << endl << endl;
        }
        else {
            break;
        }
    } while (true);
    return number;
}

string Utility::getString(string message)
{
    string str;
    cout << message;
    getline(cin, str);
    return str;
}

void Utility::headerUI(string _screenTitle)
{
    system("cls"); //clearing terminal above

    cout << string(84, '*') << endl;
    cout << string(84, '*') << endl;
    cout << string(7, '*') << string(51, ' ') << "Time: " << manageMart.currentTime->getTime() << "  *******" << endl;
    cout << "*******" << string(32, ' ') << "SSN Mart" << string(30, ' ') << "*******" << endl;
    cout << "*******" << string(31, ' ') << "----------" << string(29, ' ') << "*******" << endl;
    cout << "*******" << string(70, ' ') << "*******" << endl;
    cout << string(84, '*') << endl;
    cout << "*******" << string(70, ' ') << "*******" << endl;
    cout << _screenTitle << endl;
    cout << "*******" << string(70, ' ') << "*******" << endl;
    cout << string(84, '*') << endl;
    cout << "*******" << string(70, ' ') << "*******" << endl;
}

void Utility::mainMenuScreen()
{
    Utility::headerUI("*******" + string(31, ' ') + "Main Menu" + string(30, ' ') + "*******");
    cout << "*******  " << string(23, ' ') << "1. Search Product" << string(26, ' ') << "  *******" << endl;
    cout << "*******  " << string(23, ' ') << "2. Manage Warehouse" << string(24, ' ') << "  *******" << endl;
    cout << "*******  " << string(23, ' ') << "3. Pay Salary" << string(30, ' ') << "  *******" << endl;
    cout << "*******  " << string(23, ' ') << "4. Back to Overview" << string(24, ' ') << "  *******" << endl;
    cout << "*******  " << string(23, ' ') << "5. Exit" << string(36, ' ') << "  *******" << endl;
    cout << "*******" << string(70, ' ') << "*******" << endl;
    cout << string(84, '*') << endl;
    cout << string(84, '*') << endl;
    cout << endl << endl;
}
