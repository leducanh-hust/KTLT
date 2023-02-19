#pragma once
#include <iostream>
#include <string>

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
    Room() {}
    Room(int num, int capacity, bool reserved, double pricePerNight) : m_num(num), m_capacity(capacity), m_reserved(reserved), m_pricePerNight(pricePerNight) {}

    int getNum() { return this->m_num; }
    int getCapacity() { return this->m_capacity; }
    bool getIsReserved() { return this->m_reserved; }
    double getPricePerNight() { return this->m_pricePerNight; }
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
        os << "Room " << room.m_num << " - capacity: " << room.m_capacity << ", Price for 1 night: " << room.m_pricePerNight << ", reserved: " << (room.m_reserved ? "yes" : "no");
        return os;
    }
    virtual void printRoomsid()
    {
        cout << "Room " << getNum() << endl;
        cout << "Capacity: " << getCapacity() << endl;
        cout << "Price for 1 night : " << getPricePerNight() << "$" << endl;
    }
    friend double Money(Room room, int NightNumber);
    friend class Hotel;
};

#endif
