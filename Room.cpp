#include <iostream>
#include <string>
#include "Room.h"

using namespace std;

Room::Room() 
{
    m_num = 0;
    m_capacity = 0;
    m_reserved = false;
    m_pricePerNight = 0.0;
}

int Room::getNum()
{
    return this->m_num;
}

int Room::getCapacity()
{
    return this->m_capacity;
}

bool Room::getIsReserved()
{
    return this->m_reserved;
}

double Room::getPricePerNight()
{
    return this->m_pricePerNight;
}




void Room::setNum(int m_num)
{
    this->m_num = m_num;
}

void Room::setCapacity(int m_capacity)
{
    this->m_capacity = m_capacity;
}

void Room::setIsReserved(bool m_reserved)
{
    this->m_reserved = m_reserved;
}

void Room::setPricePerNight(double m_pricePerNight)
{
    this->m_pricePerNight = m_pricePerNight;
}

void Room::reserve()
{
    m_reserved = true;
}

void Room::unreserve()
{
    m_reserved = false;
}


std::ostream& operator<<(ostream& os, const Room& room)
{
    os << "Room " << room.m_num << " - capacity: " << room.m_capacity << ", Price for 1 night: " << room.m_pricePerNight << ", reserved: " << (room.m_reserved ? "yes" : "no");
    return os;
}
