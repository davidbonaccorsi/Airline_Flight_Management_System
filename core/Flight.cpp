//
// Created by bonac on 4/21/2026.
//

#include "Flight.h"
#include <fstream>
#include "../entities/EconomyTicket.h"
#include "../entities/BusinessTicket.h"

Flight::Flight(string fNumber, string dest, int capacity)
    : flightNumber(std::move(fNumber)), destination(std::move(dest)),
    maxCapacity(capacity), availableSeats(capacity), totalRevenue(0.0f) {}

Flight::~Flight() {
    for (const Ticket* t : tickets) {
        delete t;
    }
    tickets.clear();
}

Flight& Flight::operator+=(Ticket* newTicket) {
    if (availableSeats > 0) {
        tickets.push_back(newTicket);
        availableSeats--;

        totalRevenue += newTicket->calculateFinalPrice();

        cout << "Success: Ticket booked for " << newTicket->getName() << ".\n";
    } else {
        cout << "Error: Booking failed. Flight " << flightNumber << " is fully booked!\n";
    }
    return *this;
}

Ticket* Flight::operator[](const int index) {
    if (index >= 0 && index < tickets.size()) {
        return tickets[index];
    }
    cout << "Error: Invalid seat index!\n";
    return nullptr;
}

string Flight::getFlightNumber() const { return flightNumber; }
int Flight::getAvailableSeats() const { return availableSeats; }
float Flight::getTotalRevenue() const { return totalRevenue; }

void Flight::displayManifest() const {
    cout << "\n=== FLIGHT MANIFEST: " << flightNumber << " to " << destination << " ===\n";
    cout << "Capacity: " << maxCapacity << " | Seats Available: " << availableSeats << "\n";
    cout << "Total Revenue: $" << totalRevenue << "\n";
    cout << "Passengers on board:\n";

    if (tickets.empty()) {
        cout << " No passengers booked yet.\n";
    } else {
        for (size_t i = 0; i < tickets.size(); i++) {
            cout << " [" << i << "] " << tickets[i]->getName()
                 << " (Paid: $" << tickets[i]->calculateFinalPrice() << ")\n";
        }
    }
    cout << "========================================\n";
}

void Flight::saveToFile(const string& filename) const {
    ofstream out(filename);
    if (!out) {
        cout << "Error: File not opened for saving!\n";
        return;
    }

    out << availableSeats << "\n";
    out << totalRevenue << "\n";

    for (Ticket* t : tickets) {
        if (dynamic_cast<EconomyTicket*>(t)) {
            out << "E\n";
        } else if (dynamic_cast<BusinessTicket*>(t)) {
            out << "B\n";
        }
        out << t->getName() << "\n";
    }

    out.close();
    cout << "[System] File '" << filename << "' was saved succesfully!\n";
}

void Flight::loadFromFile(const string& filename) {
    ifstream in(filename);
    if (!in) {
        cout << "Error: File not existing. Starting a new flight.\n";
        return;
    }

    for (Ticket* t : tickets) {
        delete t;
    }
    tickets.clear();

    in >> availableSeats;
    in >> totalRevenue;

    char type;
    string name;

    while (in >> type) {
        in.ignore(); // Ignoram newline-ul dupa caracter
        getline(in, name); // Citim numele complet (cu spatii)

        if (type == 'E') {
            tickets.push_back(new EconomyTicket(name, flightNumber, 100.0f, 20));
        } else if (type == 'B') {
            tickets.push_back(new BusinessTicket(name, flightNumber, 300.0f, true, 500));
        }
    }

    in.close();
    cout << "[System] File '" << filename << "' was loaded succesfully!\n";
}