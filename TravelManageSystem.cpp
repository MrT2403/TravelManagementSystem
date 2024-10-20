#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>
#include <limits>

using namespace std;

void menu(string role);

class ManageMenu
{
protected:
    string userName;
    string role;

public:
    ManageMenu()
    {
        cout << "\n\nEnter Your Name: ";
        cin >> userName;

        cout << "Enter your role (admin/user): ";
        cin >> role;

        if (role != "admin" && role != "user")
        {
            cout << "Invalid role! Please restart the program.\n";
            exit(0);
        }

        system("CLS");
        menu(role);
    }
};

class Customers
{
public:
    string name, gender, address, mobileNumber;
    int age;
    static int cusID;
    string all;
    bool isValidNumber(const string &number)
    {
        if (number.length() != 10)
            return false;
        for (char c : number)
        {
            if (!isdigit(c))
                return false;
        }
        return true;
    }
    void getDetails()
    {
        ofstream out("old-customers.txt", ios::app);
        cout << "Enter Customer ID: ";
        cin >> cusID;

        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Age: ";
        while (!(cin >> age) || age <= 0)
        {
            cout << "Invalid age! Please enter a valid age: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter Mobile Number: ";
        while (true)
        {
            cin >> mobileNumber;
            if (isValidNumber(mobileNumber))
            {
                break;
            }
            else
            {
                cout << "Invalid number! Enter a 10-digit mobile number: ";
            }
        }

        cout << "Enter Address: ";
        cin.ignore();
        getline(cin, address);

        cout << "Enter Gender: ";
        cin >> gender;

        out << "\nCustomer ID: " << cusID
            << "\nName: " << name
            << "\nAge: " << age
            << "\nMobile Number: " << mobileNumber
            << "\nAddress: " << address
            << "\nGender: " << gender << "\n";
        out.close();

        cout << "\nSAVED! Your details have been saved for future reference.\n";
        cout << "\nPress any key to return to the main menu...";
        cin.ignore();
        cin.get();
        system("CLS");
        menu("user");
    }

    void showCustomerDetails()
    {
        ifstream in("old-customers.txt");
        if (!in)
        {
            cout << "File Error! No customer details available.\n";
        }
        else
        {
            while (getline(in, all))
            {
                cout << all << endl;
            }
        }
        in.close();

        cout << "\nPress any key to return to the main menu...";
        cin.ignore();
        cin.get();
        system("CLS");
        menu("admin");
    }

    void searchCustomer()
    {
        ifstream in("old-customers.txt");
        if (!in)
        {
            cout << "File Error! No customer details available.\n";
            return;
        }

        string searchQuery;
        cout << "Enter Customer ID or Name to search: ";
        cin.ignore();
        getline(cin, searchQuery);

        bool found = false;
        string line;

        while (getline(in, line))
        {
            if (line.find(searchQuery) != string::npos)
            {
                found = true;
                cout << line << endl;
                // Hiển thị các dòng liên quan đến khách hàng
                for (int i = 0; i < 5; ++i)
                {
                    if (getline(in, line))
                    {
                        cout << line << endl;
                    }
                }
                cout << "--------------------------------\n";
            }
        }
        in.close();

        if (!found)
        {
            cout << "No customer found with the given query.\n";
        }

        cout << "\nPress any key to return to the main menu...";
        cin.get();
        system("CLS");
        menu("admin");
    }
};

int Customers::cusID = 0;

class Cabs
{
    int cabChoice;
    int kilometers;
    float cabCost;

public:
    static float lastCabCost;

    void cabDetail()
    {
        cout << "We collaborate with the fastest and safest cab service across the country.\n";
        cout << "-----------ABC Cabs----------\n";
        cout << "1. Rent a Standard Cab - Rs.15 per 1KM\n";
        cout << "2. Rent a Luxury Cab - Rs.25 per 1KM\n";

        cout << "\nEnter which kind of cab you need: ";
        cin >> cabChoice;

        cout << "Enter kilometers you have to travel: ";
        while (!(cin >> kilometers) || kilometers <= 0)
        {
            cout << "Invalid input! Please enter a positive number for kilometers: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (cabChoice == 1)
        {
            cabCost = kilometers * 15;
            cout << "\nYour tour will cost " << cabCost << " USD for a Standard Cab.\n";
        }
        else if (cabChoice == 2)
        {
            cabCost = kilometers * 25;
            cout << "\nYour tour will cost " << cabCost << " USD for a Luxury Cab.\n";
        }
        else
        {
            cout << "Invalid Input! Redirecting to Main Menu.\n";
            Sleep(999);
            system("CLS");
            menu("user");
            return;
        }

        lastCabCost = cabCost;
        cout << "\nYou have successfully hired a cab.\n";
        cout << "\nPress any key to return to the main menu...";
        cin.ignore();
        cin.get();
        system("CLS");
        menu("user");
    }
};

float Cabs::lastCabCost = 0;

class Booking
{
public:
    int choiceHotel;
    int packChoice;
    static float hotelCost;

    void hotels()
    {
        string hotelNo[] = {"Avendra", "ChoiceYou", "ElephanBay"};

        for (int i = 0; i < 3; i++)
        {
            cout << (i + 1) << ". Hotel " << hotelNo[i] << endl;
        }

        cout << "\nPress the number of the hotel you want to book: ";
        cin >> choiceHotel;

        if (choiceHotel < 1 || choiceHotel > 3)
        {
            cout << "Invalid Input! Redirecting to previous menu.\n";
            Sleep(1000);
            system("CLS");
            hotels();
            return;
        }

        cout << "You selected Hotel " << hotelNo[choiceHotel - 1] << ".\n";
        cout << "1. Standard Pack - Rs.5000\n2. Premium Pack - Rs.11000\n3. Luxury Pack - Rs.15000\n";
        cout << "Enter package number: ";
        cin >> packChoice;

        switch (packChoice)
        {
        case 1:
            hotelCost = 5000.00;
            break;
        case 2:
            hotelCost = 11000.00;
            break;
        case 3:
            hotelCost = 15000.00;
            break;
        default:
            cout << "Invalid Input! Redirecting to previous menu.\n";
            Sleep(1000);
            system("CLS");
            hotels();
            return;
        }

        cout << "\nYou have successfully booked a package.\n";
        cout << "\nPress any key to return to the main menu...";
        cin.ignore();
        cin.get();
        system("CLS");
        menu("user");
    }
};

float Booking::hotelCost = 0;

void menu(string role)
{
    int mainChoice;
    cout << "--------- Main Menu ---------\n";
    cout << "1. Customer Information\n2. Cab Booking\n3. Hotel Booking\n4. Exit\n";
    if (role == "admin")
    {
        cout << "5. Show Customer Details\n";
        cout << "6. Search Customer\n";
    }
    cout << "Enter your choice: ";
    cin >> mainChoice;

    system("CLS");

    Customers customer;
    Cabs cab;
    Booking booking;

    switch (mainChoice)
    {
    case 1:
        customer.getDetails();
        break;
    case 2:
        cab.cabDetail();
        break;
    case 3:
        booking.hotels();
        break;
    case 4:
        cout << "Thank you for using our service!\n";
        exit(0);
    case 5:
        if (role == "admin")
        {
            customer.showCustomerDetails();
        }
        else
        {
            cout << "Access Denied! Admins only.\n";
            menu(role);
        }
        break;
    case 6:
        if (role == "admin")
        {
            customer.searchCustomer();
        }
        else
        {
            cout << "Access Denied! Admins only.\n";
            menu(role);
        }
        break;
    default:
        cout << "Invalid choice! Redirecting to Main Menu.\n";
        Sleep(1000);
        system("CLS");
        menu(role);
    }
}

int main()
{
    ManageMenu startObj;
    return 0;
}
