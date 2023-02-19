#pragma once
#include <iostream>
#include <string>
#include<iomanip>

using namespace std;

#ifndef _ROOM_H_
#define _ROOM_H_

class Room
{
private:
    int m_num;
    int m_capacity;
    bool m_reserved;
    double m_pricePerNight;

public:
    
    //Constructor
    Room() {} // Default constructor
    //Parameterized constructor
    Room(int num, int capacity, bool reserved, double pricePerNight) : m_num(num), m_capacity(capacity), m_reserved(reserved), m_pricePerNight(pricePerNight) {}


    //Get method
    int getNum() { return this->m_num; }

    int getCapacity() { return this->m_capacity; }

    bool getIsReserved() { return this->m_reserved; }

    double getPricePerNight() { return this->m_pricePerNight; }



    //Set method

    void setNum(int m_num)
    {
        this->m_num = m_num;
    }

    void setCapacity(int m_capacity)
    {
        this->m_capacity = m_capacity;
    }

    void setIsReserved(bool m_reserved)
    {
        this->m_reserved = m_reserved;
    }

    void setPricePerNight(double m_pricePerNight)
    {
        this->m_pricePerNight = m_pricePerNight;
    }

    void reserve() { m_reserved = true; }

    void unreserve() { m_reserved = false; }



    
    friend ostream &operator<<(ostream &os, const Room &room)
    {
        os << room.m_num << setw(20) << room.m_capacity << setw(20)  
            << room.m_pricePerNight << setw(20) << (room.m_reserved ? "yes" : "no");
        return os;
    }
    virtual void printRoomsid()
    {
        cout << "Room " << getNum() << endl;
        cout << "Capacity: " << getCapacity() << endl;
        cout << "Price per night : " << getPricePerNight() << "$" << endl;
    }
    friend double Money(Room room, int NightNumber);
    friend class Hotel;
};

#endif
