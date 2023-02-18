#pragma once
#include<iostream>
#include<string>
#include "Room.h"

using namespace std;

#ifndef _LUXURYROOM_H_
#define _LUXURYROOM_H_

class LuxuryRoom : public Room
{
private:
    int NumberOfFloor; // Phòng ở tầng ...
    int TV; // số TV trong phòng
    bool Food;

public:
    //Constructor 
    LuxuryRoom()
    {
        NumberOfFloor = 0;
        TV = 0;
        Food = false;
    }; 

    LuxuryRoom(int m_num, int m_capacity, bool m_reserved, double m_pricePerNight, int NumberOfFloor, int TV, bool Food)
        : Room(m_num, m_capacity, m_reserved, m_pricePerNight)
    {
        this->NumberOfFloor = NumberOfFloor;
        this->TV = TV;
        this->Food = Food;
    }


    //Get method
    int getNumberOfFloor() { return NumberOfFloor; }
    int getTV() { return TV; }
    bool getFood() { return Food; }


    //Set method
    void setNumberOfFloor(int NumberOfFloor)
    {
        this->NumberOfFloor = NumberOfFloor;
    }

    void setTV(int TV)
    {
        this->TV = TV;
    }

    void setFood(bool Food)
    {
        this->Food = Food;
    }


    void UnFood() { Food = false; }

    void HaveFood() { Food = true; }

    void printRoomsid()
    {
        Room::printRoomsid();
        cout << "located on the " << getNumberOfFloor() << "th floor" << endl;
        cout << "Number of TV: " << getTV() << endl;
        if (Food == true)
        {
            cout << "Food is served" << endl;
        }
        else
        {
            cout << "Food is not served" << endl;
        }
    }
};

#endif