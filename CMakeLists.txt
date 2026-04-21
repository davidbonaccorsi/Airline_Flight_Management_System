cmake_minimum_required(VERSION 4.2)
project(Airline_Flight_Management_System)

set(CMAKE_CXX_STANDARD 20)

add_executable(Airline_Flight_Management_System main.cpp
        core/Flight.cpp
        core/Flight.h
        core/WaitingList.h
        entities/BusinessTicket.cpp
        entities/BusinessTicket.h
        entities/EconomyTicket.cpp
        entities/EconomyTicket.h
        entities/Passenger.cpp
        entities/Passenger.h
        entities/Ticket.cpp
        entities/Ticket.h
        services/SecurityCheck.cpp
        services/SecurityCheck.h)
