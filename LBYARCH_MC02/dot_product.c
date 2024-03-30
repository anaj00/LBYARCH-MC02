#include <stdio.h>

int main() {
    int size_n = 4;
    float vec_A[] = {1.0, 2.0, 3.0, 4.0};
    float vec_B[] = {2.0, 3.0, 4.0, 5.0};
    float sdot = 0.0;

    for(int i = 0; i < size_n; i++){
        sdot += vec_A[i] * vec_B[i];
    }
    printf("Dot product: %.2f", sdot);
    return 0;
}