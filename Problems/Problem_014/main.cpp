#include <iostream>

long long doEven(long long input);
long long doOdd(long long input);

int main() {
    int maxCount = 0, maxNumber, range = 1000000;
    for (int i = 2; i <= range; i++) {
        long long number = i;
        int Count = 0;
        while(number != 1) {
            if (!(number % 2))
                number = doEven(number);
            else
                number = doOdd(number);
            Count++;
        }
        if (Count > maxCount) {
            maxCount = Count;
            maxNumber = i;
        }
    }
    std::cout << maxNumber << " " << maxCount;
    return 0;
}

long long doEven(long long input) {
    return input/2;
}

long long doOdd(long long input) {
    return (3*input) + 1;
}