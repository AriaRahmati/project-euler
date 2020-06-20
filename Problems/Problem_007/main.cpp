#include <iostream>
#include <math.h>

bool checkPrime(int input);

int main() {
    int input = 10001, Count = 0, number = 1;
    while (Count < input) {
        if (checkPrime(number))
            Count++;
        number++;
    }
    std::cout << number - 1;
    return 0;
}

bool checkPrime(int input) {
    if (input == 2)
        return true;
    if (input == 1 || !input)
        return false;
    bool isPrime = true;
    for (int i = 2; i <= (int)sqrt(input) + 1; i++)
        if ((input % i) == 0) {
            isPrime = false;
            break;
        }
    return isPrime;
}
