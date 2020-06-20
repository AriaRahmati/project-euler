#include <iostream>
#include <math.h>

int generateTriangleNumber(int index);

int main() {
    int targetDevisors = 500, countOfFactors = 0, triangleNumber, i = 1;
    while(countOfFactors*2 < targetDevisors) {
        triangleNumber = generateTriangleNumber(i);
        countOfFactors = 0;
        for (int j = 1; j < (sqrt(triangleNumber) + 1); j++)
            if (triangleNumber % j == 0)
                countOfFactors++;
        i++;
    }
    std::cout << triangleNumber << " " << countOfFactors*2;
    return 0;
}

int generateTriangleNumber(int index) {
    return ((index * (index + 1)) / 2);
}