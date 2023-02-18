#pragma once
#include <iostream>
#include <string>

using namespace std;

#ifndef _ROOM_H_
#define _ROOM_H_

class Room
{
private:
    int m_num; //Số phòng
    int m_capacity; // Số người
    bool m_reserved; // Biến logic kiểm tra phòng đã được đặt hay chưa ( 0 / 1)
    double m_pricePerNight; // giá phòng 1 đêm 

public:
    //Constructor
    Room();
    Room(int num, int capacity, bool reserved, double pricePerNight) : m_num(num), m_capacity(capacity), m_reserved(reserved), m_pricePerNight(pricePerNight) {}

    //Get mothod
    int getNum();
    int getCapacity();
    bool getIsReserved();
    double getPricePerNight();


    //Set method
    void setNum(int m_num);
    void setCapacity(int m_capacity);
    void setIsReserved(bool m_reserved);
    void setPricePerNight(double m_pricePerNight);
    void reserve();
    void unreserve();

    friend ostream& operator<<(ostream& os, const Room& room);
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
