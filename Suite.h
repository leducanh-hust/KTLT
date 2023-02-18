#pragma once
#include "Room.h"

using namespace std;

#ifndef _SUITE_H_
#define _SUITE_H


class Suite : public Room
{
private:
    int NumberOfFloor;
    bool Pool;
    bool ShuttleBus;
    bool Food;

public:
    //Constructor
    Suite()
    {
        NumberOfFloor = 0;
        Pool = false;
        ShuttleBus = false;
        Food = false;
    }

    Suite(int m_num, int m_capacity, bool m_reserved, double m_pricePerNight,
        int NumberOfFloor, bool Pool, bool ShuttleBus, bool Food) : Room(m_num, m_capacity, m_reserved, m_pricePerNight)
    {
        this->NumberOfFloor = NumberOfFloor;
        this->Pool = Pool;
        this->ShuttleBus = ShuttleBus;
        this->Food = Food;
    }


    //Get method
    int getNumberOfFloor() { return NumberOfFloor; }

    bool getPool() { return Pool; }

    bool getShuttleBus() { return ShuttleBus; }

    bool getFood() { return Food; }


    //Set method
    void setNumberOfFloor(int NumberOfFloor)
    {
        this->NumberOfFloor = NumberOfFloor;
    }

    void setPool(bool Pool)
    {
        this->Pool = Pool;
    }

    void setShuttleBus(bool ShuttleBus)
    {
        this->ShuttleBus = ShuttleBus;
    }

    void setFood(bool Food)
    {
        this->Food = Food;
    }
    

    void printRoomsid()
    {
        Room::printRoomsid();
        cout << "located on the " << getNumberOfFloor() << "th floor" << endl;
        if (Pool == true)
        {
            cout << "Food is served" << endl;
        }
        else
        {
            cout << "Food is not served" << endl;
        }
        cout << "There is a shuttle to the place" << endl;
        if (Food == true)
        {
            cout << "Room with swimming pool" << endl;
        }
        else
        {
            cout << "Room without swimming pool" << endl;
        }
    }
};

#endif // !_SUITE_H_
