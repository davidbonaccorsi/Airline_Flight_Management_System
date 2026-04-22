# ✈️ Airline Flight Management System
### Object-Oriented Programming Project | C++17

> A terminal-based flight management engine implemented in C++17, serving as a structural study in strict Object-Oriented Programming paradigms — focusing on memory-safe polymorphism, generic programming, and system-level data serialization.

📖 **[Read the Full Interactive Technical Documentation Here](https://davidbonaccorsi.github.io/Airline_Flight_Management_System/)**

---

## ⚙️ Architecture
The codebase is modularized around a clear separation of concerns:

* **`entities/`** — Core domain models built around an abstract `Ticket` base and its derived forms (`EconomyTicket`, `BusinessTicket`, `Passenger`).
* **`core/`** — Central `Flight` engine managing dynamically allocated arrays of polymorphic objects, plus the generic `WaitingList<T>` template.
* **`services/`** — Independent operational logic (`SecurityCheck` friend class).
* **`main.cpp`** — Interactive 8-option terminal menu via do-while / switch-case.

---

## 🧱 Class Architecture Diagram

```text
         +-----------------------------+
         |        <<abstract>>         |
         |           Ticket            |
         |-----------------------------|
         | + calculateFinalPrice() = 0 |
         | + printBoardingPass()   = 0 |
         +-----------------------------+
                      / \
            _________/   \_________
           /                       \
+------------------+      +---------------------+
|  EconomyTicket   |      |   BusinessTicket    |
+------------------+      +---------------------+

+------------------+  friend  +---------------------+
|    Passenger     |<-------->|    SecurityCheck    |
+------------------+          +---------------------+

+------------------+ contains +---------------------+
|      Flight      |----------->|   vector<Ticket*>   |
+------------------+            +---------------------+

+------------------+
|  WaitingList<T>  |   (Generic Template)
+------------------+
````

-----

## 🔬 OOP Concepts Applied

| Concept | Implementation |
|---|---|
| **Abstract Classes & Polymorphism** | `Ticket` declares pure virtual `calculateFinalPrice()`; `Flight` resolves calls on `vector<Ticket*>` dynamically at runtime. |
| **Operator Overloading** | `operator+=` handles booking logic (revenue + seat tracking); `operator[]` gives boundary-checked manifest access. |
| **Generic Programming** | `WaitingList<T>` wraps `std::queue<T>` — a type-safe FIFO queue adaptable to any data type. |
| **Friend Classes** | `SecurityCheck` accesses private `Passenger::passportNumber` directly via `friend class` without exposing it to the public API. |
| **Serialization & RTTI** | `saveToFile` / `loadFromFile` via `<fstream>`; `dynamic_cast` reconstructs the exact ticket hierarchy from flat text. |
| **Encapsulation** | `availableSeats` and `totalRevenue` are private; exposed read-only via getters, mutated only through operators. |

-----

## 🚀 Build & Run

 

```bash
git clone [https://github.com/davidbonaccorsi/Airline_Flight_Management_System.git](https://github.com/davidbonaccorsi/Airline_Flight_Management_System.git)
cd Airline_Flight_Management_System
mkdir build && cd build
cmake ..
make
./Airline_Flight_Management_System
```

*Note: On startup, the system auto-loads `manifest.txt` if present and initializes flight RO381 → Paris with 50 seats.*

-----

## 📌 Key Design Decisions

  - **No Raw Setters:** All state mutations go through highly controlled operators or constructors, preventing invalid system states.
  - **Move Semantics (`std::move`):** Utilized in constructors to transfer ownership of string data, avoiding unnecessary memory copies.
  - **Single Responsibility Principle (SRP):** Security logic is decoupled into a separate `SecurityCheck` service rather than forcing it inside the `Passenger` class.
