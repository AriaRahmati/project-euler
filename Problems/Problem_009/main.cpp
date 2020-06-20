#include <iostream>

int main() {
    int result;
    do {
        for (int c = 1; c < 500; c++)
            for (int b = 1; b < c; b++)
                for (int a = 1; a < b; a++)
                    if ((((a*a) + (b*b)) == (c*c)) && (a + b +c) == 1000) {
                        result = a * b * c;
                        goto end;
                    }
    } while (true);
    end:
    std::cout << result;
    return 0;
}
