#include <iostream>

int main() {
    int input = 4000000;
    int f0 = 1, f1= 1, f2, sum = 0;
    do {
        f2 = f0 + f1;
        if (f2 % 2 == 0)
            sum += f2;
        f0 = f1;
        f1 = f2;
    } while (f2 < input);
    std::cout << sum;
    return 0;
}
