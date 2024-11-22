#include <iostream>
#include <string>

// Struct to store flight information
struct FlightInfo {
    std::string destination;  // Airport code
    int distance;             // Distance to destination in miles
};

// Class Plane
class Plane {
private:
    double pos;               // Position of the plane in miles
    double vel;               // Velocity of the plane in miles per second
    double distance;          // Distance covered in miles
    bool at_SCE;              // Whether the plane is at a specific control event (SCE)
    std::string origin;       // Origin of the flight
    std::string destination;  // Destination of the flight

    // Helper function to get distance between origin and destination
    int getDistanceFromOriginToDestination(const std::string& origin, const std::string& destination) {
        FlightInfo flights[] = {{"PHL", 160}, {"ORD", 640}, {"EWR", 220}};
        for (const auto& flight : flights) {
            if (flight.destination == destination) {
                return flight.distance;
            }
        }
        return 0; // Return 0 if the destination is not found
    }

public:
    // Constructor
    Plane(const std::string& from, const std::string& to)
        : pos(0.0), vel(0.0), at_SCE(true), origin(from), destination(to) {
        distance = getDistanceFromOriginToDestination(from, to);
        std::cout << "Plane Created at " << this << std::endl;  // Printing memory address 
    }

    // Destructor
    ~Plane() {
        std::cout << "Plane Destroyed" << std::endl;
    }

    // Getter for position
    double getPos() const {
        return pos;
    }

    // Setter for position
    void setPos(double newPos) {
        pos = newPos;
    }

    // Getter for velocity
    double getVel() const {
        return vel;
    }

    // Setter for velocity
    void setVel(double newVel) {
        vel = newVel;
    }

    // Getter for distance
    double getDistance() const {
        return distance;
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

    // Setter for at_SCE
    void setAtSCE(bool status) {
        at_SCE = status;
    }

    
    //Question 4
    // Function to operate the plane (advance the plane's state)
    void operate(double dt) {
        // Ensure time-related variable is not negative
        if (dt < 0) dt = 0;

        // Ensure position and distance do not go below zero
        if (pos < 0) pos = 0;
        if (distance < 0) distance = 0;

        if (pos < distance) {
            pos += vel * dt;
            at_SCE = 0;
        } else if (destination == "SCE"){
            at_SCE == 1;
        } 
        
        // Logic to check if plane has reached SCE or destination
        if (distance == 0) {
            at_SCE = true;
            std::cout << "Plane has arrived at destination: " << destination << std::endl;
        } else {
            std::cout << "Plane is in transit. Current position: " << pos << " miles" << std::endl;
        }
    }
};

// Main function for testing the class
int main() {
    Plane plane("SCE", "PHL");

    plane.setVel(5);  // Set velocity to 5 miles per second
    plane.operate(10);  // Operate for 10 seconds

    std::cout << "Current Position: " << plane.getPos() << " miles" << std::endl;
    std::cout << "Distance to Destination: " << plane.getDistance() << " miles" << std::endl;

    return 0;
}
