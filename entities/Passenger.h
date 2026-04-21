//
// Created by bonac on 4/21/2026.
//

#ifndef AIRLINE_FLIGHT_MANAGEMENT_SYSTEM_PASSENGER_H
#define AIRLINE_FLIGHT_MANAGEMENT_SYSTEM_PASSENGER_H

#pragma once
#include <string>
#include <iostream>

using namespace std;

class Passenger {
    string name;
    string passportNumber;
    bool securityCleared;

    friend class SecurityCheck;

public:
    Passenger(string name, string passport);

    string getName() const;
    bool isCleared() const;
};



#endif //AIRLINE_FLIGHT_MANAGEMENT_SYSTEM_PASSENGER_H
