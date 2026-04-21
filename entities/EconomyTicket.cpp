//
// Created by bonac on 4/21/2026.
//

#include "EconomyTicket.h"

EconomyTicket::EconomyTicket(string name, string flight, const float price, const int baggage)
    : Ticket(std::move(name),std::move(flight),price), baggageAllowance(baggage) {}

float EconomyTicket::calculateFinalPrice() const {
    float extraBaggageFee = 0.0f;
    if (baggageAllowance > 20) {
        extraBaggageFee = static_cast<float>(baggageAllowance - 20) * 5.0f;
    }
    return extraBaggageFee;
}

void EconomyTicket::printBoardingPass() const {
    cout << "----------------------------------------\n";
    cout << "| ECONOMY CLASS BOARDING PASS          |\n";
    cout << "----------------------------------------\n";
    cout << " Passenger: " << passengerName << "\n";
    cout << " Flight: " << flightNumber << "\n";
    cout << " Baggage: " << baggageAllowance << " kg\n";
    cout << " Final Price: $" << calculateFinalPrice() << "\n";
    cout << "----------------------------------------\n";
}