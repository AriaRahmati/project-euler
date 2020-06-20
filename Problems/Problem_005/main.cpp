#include <iostream>

int main() {
    int range = 20;
    long number = 1;
    while(true) {
        bool isMine = true;
        for (int i = 1; i <= range; i++) {
            if (number % i) {
                isMine = false;
                break;
            }
        }
        if (isMine) {
            std::cout << number << std::endl;
            break;
        }
        number++;
    }
    return 0;
}
