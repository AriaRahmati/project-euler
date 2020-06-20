#include <iostream>

int main() {
    for (int i = 100000; i <= 999999; i++) {
        int _i = i;
        int numberDigits[6], reverseNumberDigits[6], index = 5;
        while (_i > 0) {
            numberDigits[index] = _i % 10;
            _i /= 10;
            index--;
        }
        for (int i = 0; i < 6; i++)
            reverseNumberDigits[i] = numberDigits[5 - i];
        int number = 0, reverseNumber = 0;
        number = (numberDigits[0] * 100000) + (numberDigits[1] * 10000) + (numberDigits[2] * 1000) + (numberDigits[3] * 100) + (numberDigits[4] * 10) + numberDigits[5];
        reverseNumber = (reverseNumberDigits[0] * 100000) + (reverseNumberDigits[1] * 10000) + (reverseNumberDigits[2] * 1000) + (reverseNumberDigits[3] * 100) + (reverseNumberDigits[4] * 10) + reverseNumberDigits[5];
        if (number == reverseNumber){ //it is a palindromic number
            for (int i = 100; i <= 999; i++)
                if (number % i == 0 && number / i < 1000)
                    std::cout << number << " = " << i << " * " << number / i << std::endl;
        }
    }
    return 0;
}
