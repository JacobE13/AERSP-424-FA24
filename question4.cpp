#include <iostream>
#include <string>
#include <map>
#include <iomanip>  // For std::hex

// Simulating a distance container for airport pairs (you can replace this with your own container)
std::map<std::pair<std::string, std::string>, double> airportDistances = {
    {{"New York", "Los Angeles"}, 4500},
    {{"London", "Paris"}, 340},
    {{"Tokyo", "Seoul"}, 1160},
    {{"San Francisco", "Chicago"}, 3000},
    // Add more airport pairs as needed
};

class Plane {
private:
    // Private members
    double pos;           // Position in kilometers
    double vel;           // Velocity in km/h
    double distance;      // Total distance to the destination in kilometers
    bool at_SCE;          // True if the plane has reached its destination
    std::string origin;   // Origin airport
    std::string destination; // Destination airport

public:
    // Constructor
    Plane(const std::string& from, const std::string& to) 
        : pos(0), vel(0), at_SCE(false), origin(from), destination(to) 
    {
        // Set the distance using the container that holds distances between airports
        auto key = std::make_pair(origin, destination);
        if (airportDistances.find(key) != airportDistances.end()) {
            distance = airportDistances[key];
        } else {
            distance = 0; // Default if distance not found
            std::cerr << "Error: Distance between " << origin << " and " << destination << " not found." << std::endl;
        }

        // Print memory address of the object in hex format
        std::cout << "Plane Created at " << std::hex << this << std::dec << std::endl;
    }

    // Destructor
    ~Plane() {
        std::cout << "Plane Destroyed." << std::endl;
    }

    // Getters and Setters
    double getPos() const { return pos; }
    double getVel() const { return vel; }
    std::string getOrigin() const { return origin; }
    std::string getDestination() const { return destination; }
    bool getAtSCE() const { return at_SCE; }

    void setVel(double v) { vel = v >= 0 ? v : 0; } // Ensure velocity is non-negative

    // Function to simulate plane operation over time in seconds
    void operate(double dt) {
        if (at_SCE) {
            std::cout << "Plane has already reached its destination." << std::endl;
            return;
        }

        // Ensure time step is non-negative
        dt = dt >= 0 ? dt : 0;

        // Update the position based on velocity and time (velocity is in km/h, convert to km/s)
        pos += vel * (dt / 3600.0);  // Convert dt from seconds to hours

        // If plane exceeds the distance, it reaches the destination
        if (pos >= distance) {
            pos = distance;  // Snap to the exact destination
            at_SCE = true;
            std::cout << "Plane has reached its destination!" << std::endl;
        }

        // Ensure position doesn't go negative
        pos = pos >= 0 ? pos : 0;

        std::cout << "Operating: Time step = " << dt << " seconds, Position = " << pos << " km, Velocity = " << vel << " km/h" << std::endl;
    }
};

int main() {
    // Example: Create a plane object with origin and destination
    Plane plane("New York", "Los Angeles");

    // Set initial velocity (km/h)
    plane.setVel(900);  // Velocity in km/h

    // Simulate the plane's operation over time in seconds
    double timeStep = 3600; // 1 hour = 3600 seconds
    for (int i = 0; i < 5; ++i) { // Simulate for 5 hours
        plane.operate(timeStep);
        if (plane.getAtSCE()) break;  // Stop if the plane reaches its destination
    }

    return 0;
}
