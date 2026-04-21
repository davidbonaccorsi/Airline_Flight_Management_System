//
// Created by bonac on 4/21/2026.
//

#ifndef AIRLINE_FLIGHT_MANAGEMENT_SYSTEM_WAITINGLIST_H
#define AIRLINE_FLIGHT_MANAGEMENT_SYSTEM_WAITINGLIST_H

#pragma once
#include <iostream>
#include <queue>
#include <string>
#include <stdexcept>

using namespace std;

template <typename T>
class WaitingList {
private:
    queue<T> elements;
    string listName;

public:
    explicit WaitingList(string name) : listName(std::move(name)) {}

    void add(T item) {
        elements.push(item);
        cout << "[Waitlist] Added to " << listName << ".\n";
    }

    T processNext() {
        if (elements.empty()) {
            throw runtime_error("Waiting list is empty!");
        }
        T nextItem = elements.front();
        elements.pop();
        return nextItem;
    }

    bool isEmpty() const {
        return elements.empty();
    }

    int getSize() const {
        return elements.size();
    }

    string getName() const {
        return listName;
    }
};


#endif //AIRLINE_FLIGHT_MANAGEMENT_SYSTEM_WAITINGLIST_H
