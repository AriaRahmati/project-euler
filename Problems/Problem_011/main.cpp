#include <iostream>

void printArray(int Array[20][20]);
int checkUp(int Array[20][20]);
int checkRight(int Array[20][20]);
int checkDiagonally(int Array[20][20], bool right, bool left);

int main() {
    int Array[20][20] = {
        {8,2,22,97,38,15,0,40,0,75,4,5,7,78,52,12,50,77,91,8},
        {49,49,99,40,17,81,18,57,60,87,17,40,98,43,69,48,4,56,62,0},
        {81,49,31,73,55,79,14,29,93,71,40,67,53,88,30,3,49,13,36,65},
        {52,70,95,23,4,60,11,42,69,24,68,56,1,32,56,71,37,2,36,91},
        {22,31,16,71,51,67,63,89,41,92,36,54,22,40,40,28,66,33,13,80},
        {24,47,32,60,99,3,45,2,44,75,33,53,78,36,84,20,35,17,12,50},
        {32,98,81,28,64,23,67,10,26,38,40,67,59,54,70,66,18,38,64,70},
        {67,26,20,68,2,62,12,20,95,63,94,39,63,8,40,91,66,49,94,21},
        {24,55,58,5,66,73,99,26,97,17,78,78,96,83,14,88,34,89,63,72},
        {21,36,23,9,75,0,76,44,20,45,35,14,0,61,33,97,34,31,33,95},
        {78,17,53,28,22,75,31,67,15,94,3,80,4,62,16,14,9,53,56,92},
        {16,39,5,42,96,35,31,47,55,58,88,24,0,17,54,24,36,29,85,57},
        {86,56,0,48,35,71,89,7,5,44,44,37,44,60,21,58,51,54,17,58},
        {19,80,81,68,5,94,47,69,28,73,92,13,86,52,17,77,4,89,55,40},
        {4,52,8,83,97,35,99,16,7,97,57,32,16,26,26,79,33,27,98,66},
        {88,36,68,87,57,62,20,72,3,46,33,67,46,55,12,32,63,93,53,69},
        {4,42,16,73,38,25,39,11,24,94,72,18,8,46,29,32,40,62,76,36},
        {20,69,36,41,72,30,23,88,34,62,99,69,82,67,59,85,74,4,36,16},
        {20,73,35,29,78,31,90,1,74,31,49,71,48,86,81,16,23,57,5,54},
        {1,70,54,71,83,51,54,69,16,92,33,48,61,43,52,1,89,19,67,48},
    };
    int MaxUp = checkUp(Array);
    std::cout << "Max up = " << MaxUp << std::endl;
    int MaxRight = checkRight(Array);
    std::cout << "Max Right = " << MaxRight << std::endl;
    int MaxDiagonallyRight = checkDiagonally(Array, 1, 0);
    std::cout << "Max DiagonallyRight = " << MaxDiagonallyRight << std::endl;
    int MaxDiagonallyLeft = checkDiagonally(Array, 0, 1);
    std::cout << "Max DiagonallyLeft = " << MaxDiagonallyLeft << std::endl;
    int Max = MaxUp;
    Max = (MaxDiagonallyRight > Max) ? MaxDiagonallyRight : ((Max = (MaxDiagonallyLeft > Max) ? MaxDiagonallyLeft : ((Max = (MaxRight > Max) ? MaxRight : Max))));
    std::cout << "\nMax of all Up, Right and Diagonally is " << Max << std::endl;
    return 0;
}

void printArray(int Array[20][20]) {
    for (int i = 0; i < 20; i++){
        for (int j = 0; j < 20; j++)
            std::cout << Array[i][j] << " ";
        std::cout << std::endl;
    }
}

int checkUp(int Array[20][20]) {
    long MaxUp = 0;
    int lastFourUp[4];
    for (int j = 0; j < 20; j++)
        for (int i = 0; i < 17; i++) {
            int fourUp[4] = {
                Array[i][j], Array[i+1][j], Array[i+2][j], Array[i+3][j]
            };
            long product = 1;
            for (int k = 0; k < 4; k++)
                product *= fourUp[k];
            if (product > MaxUp) {
                MaxUp = product;
                for (int k = 0; k < 4; k++)
                    lastFourUp[k] = fourUp[k];
            }
        }
    for (int k = 0; k < 4; k++)
        std::cout << lastFourUp[k] << " ";
    return MaxUp;
}

int checkRight(int Array[20][20]) {
    long MaxRight = 0;
    int lastFourRight[4];
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 17; j++) {
            int fourRight[4] = {
                Array[i][j], Array[i][j+1], Array[i][j+2], Array[i][j+3]
            };
            long product = 1;
            for (int k = 0; k < 4; k++)
                product *= fourRight[k];
            if (product > MaxRight) {
                MaxRight = product;
                for (int k = 0; k < 4; k++)
                    lastFourRight[k] = fourRight[k];
            }
        }
    for (int k = 0; k < 4; k++)
        std::cout << lastFourRight[k] << " ";
    return MaxRight;
}

int checkDiagonally(int Array[20][20], bool right, bool left) {
    if (right) {
        long MaxDiagonallyRight = 0;
        int lastFourDiagonallyRight[4];
        for (int i = 0; i < 17; i++)
            for (int j = 0; j < 17; j++){
                int fourDiagonallyRight[4] = {
                    Array[i][j], Array[i+1][j+1], Array[i+2][j+2], Array[i+3][j+3]
                };
                long product = 1;
                for (int k = 0; k < 4; k++)
                    product *= fourDiagonallyRight[k];
                if (product > MaxDiagonallyRight) {
                    MaxDiagonallyRight = product;
                    for (int k = 0; k < 4; k++)
                        lastFourDiagonallyRight[k] = fourDiagonallyRight[k];
                }
            }
        for (int k = 0; k < 4; k++)
            std::cout << lastFourDiagonallyRight[k] << " ";
        return MaxDiagonallyRight;
    } 
    if (left) {
        long MaxDiagonallyLeft = 0;
        int lastFourDiagonallyLeft[4];
        for (int i = 3; i < 17; i++)
            for (int j = 19; j > 2; j--) {
                int fourDiagonallyLeft[4] = {
                    Array[i][j], Array[i+1][j-1], Array[i+2][j-2], Array[i+3][j-3]
                };
                long product = 1;
                for (int k = 0; k < 4; k++)
                    product *= fourDiagonallyLeft[k];
                if (product > MaxDiagonallyLeft) {
                    MaxDiagonallyLeft = product;
                    for (int k = 0; k < 4; k++)
                        lastFourDiagonallyLeft[k] = fourDiagonallyLeft[k];
                }
            }
        for (int k = 0; k < 4; k++)
            std::cout << lastFourDiagonallyLeft[k] << " ";
        return MaxDiagonallyLeft;
    }
}