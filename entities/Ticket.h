//
// Created by bonac on 4/21/2026.
//

#ifndef AIRLINE_FLIGHT_MANAGEMENT_SYSTEM_TICKET_H
#define AIRLINE_FLIGHT_MANAGEMENT_SYSTEM_TICKET_H


#pragma once
#include <iostream>
#include <string>

using namespace std;

class Ticket {
protected:
    string passengerName;
    string flightNumber;
    float basePrice;

public:
    Ticket(string name, string flight, float price);

    virtual ~Ticket() = default;

    virtual float calculateFinalPrice() const = 0;
    virtual void printBoardingPass() const = 0;

    string getName() const;
    string getFlight() const;
};



#endif //AIRLINE_FLIGHT_MANAGEMENT_SYSTEM_TICKET_H
