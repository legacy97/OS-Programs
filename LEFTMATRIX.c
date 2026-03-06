//Write a program in C to find the sum of the left diagonals of a matrix.

#include <stdio.h>

int main() {
    int n = 3;
    int mat[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += mat[i][i];  // left diagonal
    }

    printf("Sum of left diagonal: %d\n", sum);
    return 0;
}
