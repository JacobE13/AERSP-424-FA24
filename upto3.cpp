#include <iostream>

// g++ -std=c++11 -Wall -o question2 question2.cpp
// ./question2

// define struct function to store information about flight
// Struct to store flight information
struct FlightInfo {
    const char* destination;  // Store and reference airport codes
    int distance;             // Miles to destination
};
int main() {
    // Define flight information
    FlightInfo flight1 = {"PHL", 160};  // Flight to PHL (Philadelphia)
    FlightInfo flight2 = {"ORD", 640};  // Flight to ORD (Chicago O'Hare)
    FlightInfo flight3 = {"EWR", 220};  // Flight to EWR (Newark)

    // Store all flights in an array
    FlightInfo flights[] = {flight1, flight2, flight3};
    int flightCount = sizeof(flights) / sizeof(flights[0]);  // Number of flights

    // Print out flight distances from SCE
    std::cout << "Flight distances from SCE:" << std::endl;
    for (int i = 0; i < flightCount; ++i) {
        std::cout << "To " << flights[i].destination << ": " << flights[i].distance << " miles" << std::endl;
    }

    // Instantiate a Plane object and pass the flight information array
    Plane plane("SCE", "PHL", flights, flightCount);
    return 0;
}
// Class Plane
class Plane {
private:
    double pos;               // Position of the plane
    double vel;               // Velocity of the plane
    double distance;          // Distance covered
    bool at_SCE;              // Whether the plane is at SCE (specific control event)
    std::string origin;       // Origin of the flight
    std::string destination;  // Destination of the flight

    // Helper function to find the distance based on the destination
    int findDistance(const std::string& dest, FlightInfo flights[], int flightCount) {
        for (int i = 0; i < flightCount; ++i) {
            if (dest == flights[i].destination) {
                return flights[i].distance;
            }
        }
        return -1; // Return -1 if destination is not found
    }

public:
    // Constructor
    Plane(const std::string& from, const std::string& to, FlightInfo flights[], int flightCount)
        : pos(0.0), vel(0.0), at_SCE(true), origin(from), destination(to) {
        distance = findDistance(to, flights, flightCount);
        if (distance == -1) {
            std::cout << "Destination " << to << " not found." << std::endl;
        } else {
            std::cout << "Plane Created at " << this << ". Distance to " << to << " is " << distance << " miles." << std::endl;
        }
    }

    // Destructor
    ~Plane() {};

    // Getter for position
    double getPos() const {
        return pos;
    }

    // Getter for origin
    std::string getOrigin() const {
        return origin;
    }

    // Getter for destination
    std::string getDestination() const {
        return destination;
    }

    // Getter for at_SCE
    bool isAtSCE() const {
        return at_SCE;
    }

    // Getter for vel
    double getVel() const {
        return vel;
    }

    // Setter for vel
    void setVel(double newVel) {
        vel = newVel;
    }
    //Question 5
    
    void operate() {
    double fspeed = 450;
    int timestep = 50;
    int i = 1500;

    }
};

