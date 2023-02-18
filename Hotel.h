#pragma once
#include <string>
#include<vector>
#include<iostream>
#include "Room.h"

using namespace std;

#ifndef _HOTEL_H_
#define _HOTEL_H_


class Hotel
{
private:
    string m_name;
    int m_numRooms;
    vector<Room*> m_rooms;

public:
    Hotel() {}
    Hotel(const string& name, int numRooms) : m_name(name), m_numRooms(numRooms)
    {
        for (int i = 0; i < numRooms; ++i)
        {
            m_rooms.push_back(new Room(i + 1, 2, false, 0));
        }
    }
    vector<Room*> getM_rooms()
    {
        return m_rooms;
    }
    ~Hotel()
    {
        for (auto room : m_rooms)
        {
            delete room;
        }
    }

    Room* findRoom(int num) const
    {
        for (auto room : m_rooms)
        {
            if (room->getNum() == num)
            {
                return room;
            }
        }
        return nullptr;
    }

    void reserveRoom(int num)
    {
        Room* room = findRoom(num);
        if (room)
        {
            if (room->getIsReserved() == true)
            {
                cout << "You can't make a reservation because someone has already booked it" << endl;
            }
            else
            {
                room->reserve();
                cout << "Room " << num << " has been reserved." << endl;
            }
        }
        else
        {
            cout << "Room " << num << " is not found." << endl;
        }
    }

    void unreserveRoom(int num)
    {
        Room* room = findRoom(num);
        if (room)
        {
            room->unreserve();
            cout << "Room " << num << " has been unreserved." << endl;
        }
        else
        {
            cout << "Room " << num << "is not found." << endl;
        }
    }

    void printRooms() const
    {
        cout << m_name << " - Room list:" << endl;
        for (auto room : m_rooms)
        {
            cout << *room << " " << endl;
            cout << endl;
        }
    }

    void addRoom(int capacity, double money)
    {
        int newNum = m_numRooms + 1;
        Room* newRoom = new Room(newNum, capacity, false, money);
        m_rooms.push_back(newRoom);
        ++m_numRooms;
        cout << "Room " << newNum << " has been added." << endl;
    }

    void deleteRoom(int num)
    {
        for (auto iter = m_rooms.begin(); iter != m_rooms.end(); ++iter)
        {
            if ((*iter)->getNum() == num)
            {
                delete* iter;
                m_rooms.erase(iter);
                --m_numRooms;
                cout << "Room " << num << " has been deleted." << endl;
                return;
            }
        }
        cout << "Room " << num << "is not found." << endl;
    }
    void Roomcharge(int NightNumber, int num)
    {
        for (auto room : m_rooms)
        {
            if (room->m_num == num)
            {
                cout << " The amount you have to pay:  " << Money(*room, NightNumber) << "$" << endl;
                break;
            }
        }
    }
    void findRoominBudget(double money, int NightNumber)
    {
        int d = 0;
        for (auto room : m_rooms)
        {
            if (Money(*room, NightNumber) <= money && room->getIsReserved() == false)
            {
                cout << " You can book room number " << room->m_num << endl;
                d++;
            }
        }
        if (d == 0)
        {
            cout << " No matching rooms available " << endl;
        }
    }
};

#endif // !_HOTEL_H_
