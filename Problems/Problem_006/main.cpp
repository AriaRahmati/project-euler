#include <iostream>
#include <math.h>

long  sumOfSquare(int range);
long squareOfSum(int range);

int main() {
    int input = 100;
    std::cout << squareOfSum(input) - sumOfSquare(input);
    return 0;
}

long sumOfSquare(int range) {
    long sum = 0;
    for (int i = 1; i <= range; i++)
        sum += pow(i, 2);
    return sum;
}

long squareOfSum(int range) {
    int sum = (range * (range + 1)) / 2;
    return sum * sum;
}