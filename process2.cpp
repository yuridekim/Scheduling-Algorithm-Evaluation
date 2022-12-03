#include <iostream>

int main()
{
    for (char c = 'a'; c <= 'e'; ++c) // outer loop on letters
    {
        for (int i = 0; i < 3000; ++i) // inner loop on all numbers
            std::cout << "";

        std::cout << "";
    }

    return 0;
}