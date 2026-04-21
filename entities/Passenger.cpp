//
// Created by bonac on 4/21/2026.
//

#include "Passenger.h"

Passenger::Passenger(string name, string passport)
    : name(std::move(name)), passportNumber(std::move(passport)), securityCleared(false) {}

string Passenger::getName() const {
    return name;
}

bool Passenger::isCleared() const {
    return securityCleared;
}