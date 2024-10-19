#include <cstdlib>
#include <iostream>
#include <time.h>

void guess_a_number(uint16_t &number)
{
    auto *p = (unsigned short *)malloc(sizeof(number));
    srand(time(0));
    *p = rand();

    if (*p != number)
    {
        std::cout << "Wrong!" << std::endl;
        return;
    }

    std::cout << "Correct!" << std::endl;
    free(p);
}

int main()
{
    uint16_t x{};
    while (true)
    {
        std::cout << "Pick a number between 0-10000: ";
        std::cin >> x;
        guess_a_number(x);
    }
    return 0;
}