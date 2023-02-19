#include <iostream>
#include<Windows.h>
#include <string>
#include <stdio.h>
#include <vector>
#include "Room.h"
#include "LuxuryRoom.h"
#include "Suite.h"
#include "Hotel.h"

using namespace std;

// Other function
void displayMenu(); // Menu

double Money(Room room, int NightNumber);

void Edit()
{
    for (int i = 0; i < 30; i++)
    {
        cout << "-";
    }
    cout << endl;
}

int check(string num); // Check input

int main()
{
    Hotel h("My Hotel", 10);
    for (int i = 0; i < 8; i++)
    {
        h.getM_rooms()[i]->setPricePerNight(20);
    }
    h.getM_rooms()[8]->setPricePerNight(100);
    h.getM_rooms()[9]->setPricePerNight(200);
    LuxuryRoom Lx(h.getM_rooms()[8]->getNum(), h.getM_rooms()[8]->getCapacity(),
                  h.getM_rooms()[8]->getIsReserved(), h.getM_rooms()[8]->getPricePerNight(), 7, 1, false);

    Suite S(h.getM_rooms()[9]->getNum(), h.getM_rooms()[9]->getCapacity(),
            h.getM_rooms()[9]->getIsReserved(), h.getM_rooms()[9]->getPricePerNight(), 8, true, true, true);

    // Menu
    cout << "****************************************************" << endl;
    cout << "*            HOTEL MANAGEMENT SYSTEM           *" << endl;
    cout << "****************************************************" << endl << endl;
    displayMenu();

    // Choose
    string option;
    int option_;
    bool check_option = true;

    while (check_option)
    {
        cout << "Choose a number: ";
        cin >> option;
        option_ = check(option);
        while (option_ < 1 || option_ > 10)
        {
            cout << "Must be between 1 and 10, enter again: ";
            cin >> option;
            option_ = check(option);
        }

        switch (option_)
        {
        case 1:
        {
            Edit();
            int num;
            cout << "Enter room number: ";
            cin >> num;
            h.reserveRoom(num);
            Edit();
            displayMenu();
            break;
        }
        case 2:
        {
            Edit();
            int num;
            cout << "Enter room number: ";
            cin >> num;
            h.unreserveRoom(num);
            displayMenu();
            break;
        }
        case 3:
            Edit();
            h.printRooms();
            Edit();
            Sleep(3000);
            displayMenu();
            break;
        case 4:
        {
            int capacity;
            cout << "Enter room capacity: ";
            cin >> capacity;
            cout << endl;
            double money;
            cout << "Enter per for night: ";
            cin >> money;
            h.addRoom(capacity, money);
            Edit();
            displayMenu();
            break;
        }
        case 5:
        {
            Edit();
            int num;
            cout << "Enter room number: ";
            cin >> num;
            h.deleteRoom(num);
            Edit();
            displayMenu();
            break;
        }
        case 6:
        {
            Edit();
            int num;
            cout << "Enter room number: ";
            cin >> num;
            int NightNumber;
            cout << "Enter night number: ";
            cin >> NightNumber;
            h.Roomcharge(NightNumber, num);
            Edit();
            break;
        }
        case 7:
        {
            Edit();
            int NightNumber;
            cout << "Enter night number: ";
            cin >> NightNumber;
            double money;
            cout << "Enter the amount you want to pay: ";
            cin >> money;
            h.findRoominBudget(money, NightNumber);
            Edit();
            break;
        }
        case 8:
        {
            Edit();
            int find = 0;
            string s2;
            cout << endl;
            cout << "Would you like to serve meals?" << endl;
            cout << "1.Yes" << endl;
            cout << "2.No" << endl;
            while (find != 2 && find != 1)
            {
                cout << "Enter your choice: ";
                cin >> s2;
                find = check(s2);
                switch (find)
                {
                case 1:
                {
                    Edit();
                    Lx.setPricePerNight(120);
                    Lx.setFood(true);
                    Lx.printRoomsid();
                    cout << "We added 20$ meal fee per day" << endl;
                    break;
                }
                case 2:
                {
                    Edit();
                    Lx.setFood(false);
                    Lx.printRoomsid();
                    break;
                }

                default:
                {
                    cout << "Invalid choice. Please try again." << endl;
                    break;
                }
                }
            }
            Edit();
            Sleep(1500);
            displayMenu();
            break;
        }
        case 9:
            Edit();
            S.printRoomsid();
            Edit();
            Sleep(2000);
            displayMenu();
            break;
        case 10:
            check_option = false;
        }
    }
    cout << "Done! Thanks for using our services!";
    return 0;
}

void displayMenu()
{
    cout << "----------------------------------------------------------------" << endl;
    cout << "\t\t\t\t\t\tWelcome to Hotel Del Luna!" << endl;
    cout << "What would you like to do?" << endl;
    cout << "1. Reserve a room" << endl;
    cout << "2. Unreserve a room" << endl;
    cout << "3. View room list" << endl;
    cout << "4. Add a room" << endl;
    cout << "5. Delete a room" << endl;
    cout << "6. Roomcharge " << endl;
    cout << "7. Find a room with the amount you want " << endl;
    cout << "8. View luxury room amenities " << endl;
    cout << "9. View suite room amenities" << endl;
    cout << "10. Exit." << endl;
    cout << "----------------------------------------------------------------" << endl;
}

double Money(Room room, int NightNumber)
{
    return room.m_pricePerNight * NightNumber;
}

int check(string num)
{

    bool check_ = 1;
    while (check_)
    {
        int strlen = num.length();
        int count = 0;
        try
        {
            for (int i = 0; i < strlen; i++)
            {
                if (num[i] < '0' || num[i] > '9')
                {
                    throw(num);
                    break;
                }
                else
                {
                    count++;
                }
            }
        }
        catch (...)
        {
            cout << "Invaild value, enter again: ";
            cin >> num;
        }
        if (count == strlen)
            check_ = 0;
    }
    return stoi(num);
}
