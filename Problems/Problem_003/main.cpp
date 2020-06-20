#include <iostream>
#include <math.h>

bool CheckAvval(long long input) {
    if (input == 2)
        return true;
    else if (input == 1 || !input)
        return false;
    for (long long i = 2; i <= sqrt(input) + 1; i++) {
        if (!(input % i)) {
            return false;
        }
    }
    return true;
}
int main() {
    long long input = 600851475143;
    long Max = 0;
    for (long long i = 1; i <= sqrt(input) + 1; i++) {
        if (CheckAvval(i)) {
            if (!(input % i) && i > Max)
                Max = i;
        }
    }
    std::cout << Max;
    return 0;
}
