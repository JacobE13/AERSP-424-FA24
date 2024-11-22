#include <iostream>
#include <thread>
#include <chrono>


void print424() {
    while (true) {
        std::cout << "424" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void printAERSP() {
    while (true) {
        std::cout << "AERSP" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main() {
    
    std::thread thread1(print424);
    std::thread thread2(printAERSP);
    thread1.join();
    thread2.join();

    return 0;
}
