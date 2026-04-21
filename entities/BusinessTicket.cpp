//
// Created by bonac on 4/21/2026.
//

#include "BusinessTicket.h"

BusinessTicket::BusinessTicket(string name, string flight, const float price, const bool lounge, const int points)
    : Ticket(std::move(name), std::move(flight), price), loungeAccess(lounge), loyaltyPointsEarned(points) {}

float BusinessTicket::calculateFinalPrice() const {
    float total = basePrice * 1.5f;

    if (loungeAccess) {
        total+= 50.0f;
    }

    return total;
}

void BusinessTicket::printBoardingPass() const {
    cout << "========================================\n";
    cout << "* BUSINESS CLASS VIP BOARDING PASS    *\n";
    cout << "========================================\n";
    cout << " Passenger: " << passengerName << "\n";
    cout << " Flight: " << flightNumber << "\n";
    cout << " VIP Lounge Access: " << (loungeAccess ? "YES" : "NO") << "\n";
    cout << " Points Earned: +" << loyaltyPointsEarned << "\n";
    cout << " Final Price: $" << calculateFinalPrice() << "\n";
    cout << "========================================\n";
}
