#include <iostream>
#include <string>
#include <unordered_map>
#include <set>

class Passenger;

class Flight {
private:
    std::string flightNumber;
    std::string departure;
    std::string arrival;
    int capacity;
    int bookedSeats;
    std::set<std::string> bookedPassengerIDs;

public:
    Flight(const std::string& fn, const std::string& dep, const std::string& arr, int cap)
        : flightNumber(fn), departure(dep), arrival(arr), capacity(cap), bookedSeats(0) {}

    bool bookSeat(const Passenger& passenger);
    bool cancelSeat(const Passenger& passenger);
    bool upgradeSeat(const Passenger& passenger);

    void showStatus() const {
        std::cout << "Flight " << flightNumber << " (" << departure << " to " << arrival << ")\n";
        std::cout << "Booked Seats: " << bookedSeats << " / " << capacity << std::endl;
    }

private:
    bool isBooked(const std::string& passengerID) const {
        return bookedPassengerIDs.find(passengerID) != bookedPassengerIDs.end();
    }

    friend class Passenger;
};

class Passenger {
private:
    std::string id;
    std::string name;

public:
    Passenger(const std::string& pid, const std::string& pname) : id(pid), name(pname) {}

    bool requestBooking(Flight& flight) {
        return flight.bookSeat(*this);
    }

    bool requestCancellation(Flight& flight) {
        return flight.cancelSeat(*this);
    }

    bool requestUpgrade(Flight& flight) {
        return flight.upgradeSeat(*this);
    }

    std::string getID() const {
        return id;
    }

    std::string getName() const {
        return name;
    }
};

// Flight method definitions

bool Flight::bookSeat(const Passenger& passenger) {
    if (bookedSeats >= capacity || isBooked(passenger.getID())) {
        std::cout << "Booking failed for " << passenger.getName() << std::endl;
        return false;
    }
    bookedPassengerIDs.insert(passenger.getID());
    bookedSeats++;
    std::cout << passenger.getName() << " successfully booked on flight " << flightNumber << std::endl;
    return true;
}

bool Flight::cancelSeat(const Passenger& passenger) {
    if (!isBooked(passenger.getID())) {
        std::cout << "Cancellation failed for " << passenger.getName() << std::endl;
        return false;
    }
    bookedPassengerIDs.erase(passenger.getID());
    bookedSeats--;
    std::cout << passenger.getName() << " cancelled from flight " << flightNumber << std::endl;
    return true;
}

bool Flight::upgradeSeat(const Passenger& passenger) {
    if (!isBooked(passenger.getID())) {
        std::cout << "Upgrade failed for " << passenger.getName() << ": not booked." << std::endl;
        return false;
    }
    std::cout << passenger.getName() << " has been upgraded on flight " << flightNumber << std::endl;
    return true;
}

int main() {
    Flight flight1("AI101", "New York", "London", 2);
    Flight flight2("AI202", "Paris", "Tokyo", 1);

    Passenger p1("P001", "Alice");
    Passenger p2("P002", "Bob");
    Passenger p3("P003", "Charlie");

    p1.requestBooking(flight1);
    p2.requestBooking(flight1);
    p3.requestBooking(flight1); // Should fail (over capacity)

    flight1.showStatus();

    p2.requestUpgrade(flight1);
    p2.requestCancellation(flight1);
    p3.requestBooking(flight1); // Now should succeed

    flight1.showStatus();

    p1.requestBooking(flight2);
    p2.requestBooking(flight2); // Should fail

    flight2.showStatus();

    return 0;
}

