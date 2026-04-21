//
// Created by bonac on 4/21/2026.
//

#include "SecurityCheck.h"
#include <iostream>

bool SecurityCheck::verifyIdentity(Passenger& p, const string& presentedPassport) {
    cout << "--- SECURITY SCAN FOR " << p.getName() << " ---\n";

    if (p.passportNumber == presentedPassport) {
        cout << " [APPROVED] Passport verified.\n";

        p.securityCleared = true;
        return true;
    }
    cout << " [ALERT] Passport mismatch! Security breach detected.\n";
    p.securityCleared = false;
    return false;
}
