//
// Created by bonac on 4/21/2026.
//

#include "Ticket.h"

#include <utility>

Ticket::Ticket(string name, string flight, const float price)
    : passengerName(std::move(name)), flightNumber(std::move(flight)), basePrice(price) {}

string Ticket::getName() const {
    return passengerName;
}

string Ticket::getFlight() const {
    return flightNumber;
}


