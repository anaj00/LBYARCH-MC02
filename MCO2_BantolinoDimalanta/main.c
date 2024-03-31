#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <time.h>
#include <math.h>

extern double getDotProduct(double* vec_A, double* vec_B, long long int size_n);

int main() {
    // Loop through different vector sizes
    for (int exp = 20; exp <= 28; exp += 2) {
        int size_n = pow(2, exp);

        clock_t start, end, c_duration, asm_duration;
        double sdot_c = 0.0, sdot_asm = 0.0;
        double loop_time = 0.0;
        double c_time = 0.0;
        
        printf("Vector size: %d^%d (%d)\n", 2, exp, size_n);
        // Allocate memory for vec_A and vec_B
        double* vec_A = (double*)malloc(size_n * sizeof(double));
        double* vec_B = (double*)malloc(size_n * sizeof(double));

        // Initialize vec_A and vec_B with random values
        for (int i = 0; i < size_n; i++) {
            vec_A[i] = (double)rand(); // Random value between 0 and 1
        }

        for (int i = 0; i < size_n; i++) {
            vec_B[i] = (double)rand(); // Random value between 0 and 1
        }

        // Time the C version
        start = clock();
        for (int j = 0; j < 30; j++) {
            sdot_c = 0.0;
            for (int k = 0; k < size_n; k++) {
                sdot_c += vec_A[k] * vec_B[k];
            }
        } 
        end = clock();
        c_duration = (end - start);
        loop_time = (double)c_duration*1e3/CLOCKS_PER_SEC;   
        c_time = (double)loop_time / 30.0; // average    
        printf("C version: %f ms on average, dot product: %.2lf\n", (float)c_duration, sdot_c);

        // Time the assembly version
        double asm_time = 0.0;
        start = clock();
        for (int j = 0; j < 30; j++) {
            sdot_asm = getDotProduct(vec_A, vec_B, size_n);
        }
        end = clock();
        asm_duration = (end - start);
        loop_time = (double)asm_duration*1e3 / CLOCKS_PER_SEC;
        asm_time = (double)loop_time / 30.0;
        printf("Assembly version: %f nanosconds on average, dot product: %.2lf\n\n", (float)asm_duration, sdot_asm);

        // Free dynamically allocated memory
        free(vec_A);
        free(vec_B);
    }

    return 0;
}
