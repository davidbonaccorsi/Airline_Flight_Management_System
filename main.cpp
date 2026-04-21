#include <iostream>
#include <vector>
#include "core/Flight.h"
#include "core/WaitingList.h"
#include "entities/EconomyTicket.h"
#include "entities/BusinessTicket.h"
#include "entities/Passenger.h"
#include "services/SecurityCheck.h"

using namespace std;

int main() {
    Flight flight("RO381", "Paris", 50);
    WaitingList<string> standbyList("Standby Queue");
    SecurityCheck security;

    int option;
    bool running = true;

    cout << "==========================================\n";
    cout << "   AIRLINE FLIGHT MANAGEMENT SYSTEM       \n";
    cout << "==========================================\n";

    while (running) {
        cout << "\n1. Book Economy Ticket\n";
        cout << "2. Book Business Ticket\n";
        cout << "3. Display Flight Manifest\n";
        cout << "4. Run Security Check (Friend Class)\n";
        cout << "5. Add to Standby List (Template/Queue)\n";
        cout << "6. Save Flight to File\n";
        cout << "7. Load Flight from File\n";
        cout << "8. Exit\n";
        cout << "Select option: ";
        cin >> option;

        switch (option) {
            case 1: {
                string name;
                int baggage;
                cout << "Passenger Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Baggage weight (kg): ";
                cin >> baggage;

                Ticket* ecoTicket = new EconomyTicket(name, flight.getFlightNumber(), 150.0f, baggage);
                flight += ecoTicket;
                break;
            }
            case 2: {
                string name;
                cout << "Passenger Name: ";
                cin.ignore();
                getline(cin, name);

                Ticket* busTicket = new BusinessTicket(name, flight.getFlightNumber(), 350.0f, true, 1000);
                flight += busTicket;
                break;
            }
            case 3: {
                flight.displayManifest();
                break;
            }
            case 4: {
                string name, passport;
                cout << "Passenger Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Passport Number: ";
                cin >> passport;

                Passenger p(name, passport);

                string inputPassport;
                cout << "Scan Passport at Gate: ";
                cin >> inputPassport;

                security.verifyIdentity(p, inputPassport);
                break;
            }
            case 5: {
                string name;
                cout << "Enter name for Standby List: ";
                cin.ignore();
                getline(cin, name);
                standbyList.add(name);
                break;
            }
            case 6: {
                flight.saveToFile("manifest.txt");
                break;
            }
            case 7: {
                flight.loadFromFile("manifest.txt");
                break;
            }
            case 8: {
                cout << "Exiting system. Have a good flight!\n";
                running = false;
                break;
            }
            default:
                cout << "Invalid option! Try again.\n";
        }
    }

    return 0;
}