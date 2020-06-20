#include <iostream>

int main() {
    int sum = 0, range = 1000;
    for (int i = 1; i < range; i++) {
        if (!(i % 3) || !(i % 5) && (i % 15))
            sum += i;
    }
    std::cout << sum;   
}