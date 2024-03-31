#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <time.h>
#include <math.h>

extern double getDotProduct(double* vec_A, double* vec_B, long long int size_n);

int main() {
    long long int size_n;

    // Loop through different vector sizes
    for (size_n = 1048576; size_n <= 1048579; size_n += 2) {
        clock_t start, end, c_duration, asm_duration;
        double sdot_c, sdot_asm;
        double loop_time = 0.0;
        double c_time = 0.0;
        
        printf("Vector size: %lld\n", size_n);
        // Allocate memory for vec_A and vec_B
        double* vec_A = (double*)malloc(size_n * sizeof(double));
        double* vec_B = (double*)malloc(size_n * sizeof(double));
        
        // Initialize vec_A and vec_B with random values
        printf("vec_A: [ ");
        for (int i = 0; i < size_n; ++i) {
            vec_A[i] = (double)rand() / RAND_MAX; // Random value between 0 and 1
            // printf(" %.2f", vec_A[i]); // Print each element of vec_A
        }
        printf(" ]\n\n");

        printf("vec_B: [");
        for (int i = 0; i < size_n; ++i) {
            vec_B[i] = (double)rand() / RAND_MAX; // Random value between 0 and 1
            // printf(" %.2f", vec_B[i]); // Print each element of vec_B
        }
        printf("] \n\n");

        // Time the C version
        start = clock();
        for (int j = 0; j < 30; j++) {
            // printf("-----------[%d]-----------\n", j);
            sdot_c = 0.0;
            for (int k = 0; k < size_n; k++) {
                sdot_c += vec_A[k] * vec_B[k];
            }
        } 
        end = clock();
        c_duration = (end - start);
        loop_time = (double)c_duration*1e3/CLOCKS_PER_SEC;
        //average       
        c_time = (double)loop_time / 30.0;
        printf("C version: %f nanosconds on average, dot product: %.2lf\n", (float)c_duration, sdot_c);

        // Time the assembly version
        double asm_time = 0.0;
        start = clock();
        for (int j = 0; j < 30; j++) {
            // printf("-----------[%d]-----------\n", j);
            sdot_asm = getDotProduct(vec_A, vec_B, size_n);
        }
        end = clock();
        asm_duration = (end - start);
        loop_time = (double)asm_duration*1e3 / CLOCKS_PER_SEC;
        asm_time = (double)loop_time / 30.0;
        printf("Assembly version: %f nanosconds on average, dot product: %.2lf\n\n\n", (float)asm_duration, sdot_asm);

        // Free dynamically allocated memory
        free(vec_A);
        free(vec_B);
    }

    return 0;
}
