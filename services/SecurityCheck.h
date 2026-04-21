//
// Created by bonac on 4/21/2026.
//

#ifndef AIRLINE_FLIGHT_MANAGEMENT_SYSTEM_SECURITYCHECK_H
#define AIRLINE_FLIGHT_MANAGEMENT_SYSTEM_SECURITYCHECK_H

#pragma once
#include "../entities/Passenger.h"

class SecurityCheck {
public:
    bool verifyIdentity(Passenger& p, const string& presentedPassport);
};

#endif //AIRLINE_FLIGHT_MANAGEMENT_SYSTEM_SECURITYCHECK_H
