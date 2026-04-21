//
// Created by bonac on 4/21/2026.
//

#ifndef AIRLINE_FLIGHT_MANAGEMENT_SYSTEM_BUSINESSTICKET_H
#define AIRLINE_FLIGHT_MANAGEMENT_SYSTEM_BUSINESSTICKET_H

#pragma once
#include "Ticket.h"

class BusinessTicket : public Ticket {
private:
    bool loungeAccess;
    int loyaltyPointsEarned;

public:
    BusinessTicket(string name, string flight, float price, bool lounge, int points);

    float calculateFinalPrice() const override;
    void printBoardingPass() const override;
};



#endif //AIRLINE_FLIGHT_MANAGEMENT_SYSTEM_BUSINESSTICKET_H
