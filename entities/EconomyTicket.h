//
// Created by bonac on 4/21/2026.
//

#ifndef AIRLINE_FLIGHT_MANAGEMENT_SYSTEM_ECONOMYTICKET_H
#define AIRLINE_FLIGHT_MANAGEMENT_SYSTEM_ECONOMYTICKET_H

#pragma once
#include "Ticket.h"

class EconomyTicket : public Ticket{
private:
    int baggageAllowance;

public:
    EconomyTicket(string name, string flight, float price, int baggage);

    float calculateFinalPrice() const override;
    void printBoardingPass() const override;
};



#endif //AIRLINE_FLIGHT_MANAGEMENT_SYSTEM_ECONOMYTICKET_H