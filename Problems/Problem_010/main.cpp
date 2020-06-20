#include <iostream>
#include <math.h>

bool checkPrime(int input);

int main() {
    int range = 2000000;
    long long sum = 2;
    for (int i = 3; i < range; i++)
        if (checkPrime(i))
            sum += i;
    std::cout << sum;
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