//
// Created by bonac on 4/21/2026.
//

#ifndef AIRLINE_FLIGHT_MANAGEMENT_SYSTEM_FLIGHT_H
#define AIRLINE_FLIGHT_MANAGEMENT_SYSTEM_FLIGHT_H

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "../entities/Ticket.h"

using namespace std;


class Flight {
private:
    string flightNumber;
    string destination;
    int maxCapacity;
    int availableSeats;
    float totalRevenue;

    vector<Ticket*> tickets;

public:
    Flight(string fNumber, string dest, int capacity);

    ~Flight();

    Flight& operator+=(Ticket* newTicket);

    Ticket* operator[](int index);

    string getFlightNumber() const;
    int getAvailableSeats() const;
    float getTotalRevenue() const;

    void displayManifest() const;
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
};



#endif //AIRLINE_FLIGHT_MANAGEMENT_SYSTEM_FLIGHT_H
