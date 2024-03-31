#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern double getDotProduct(double* vec_A, double* vec_B, long long int size_n);

int main() {
    long long int size_n;

    // Loop through different vector sizes
    for (size_n = 220; size_n <= 230; size_n += 2) {
        printf("Vector size: %lld\n", size_n);

        // Allocate memory for vec_A and vec_B
        double* vec_A = (double*)malloc(size_n * sizeof(double));
        double* vec_B = (double*)malloc(size_n * sizeof(double));

        // Initialize vec_A and vec_B with random values
        //printf("vec_A: [ ");
        for (int i = 0; i < size_n; ++i) {
            vec_A[i] = (double)rand() / RAND_MAX; // Random value between 0 and 1
            //printf(" %.2f", vec_A[i]); // Print each element of vec_A
        }
        //printf(" ]\n\n");

        //printf("vec_B: [");
        for (int i = 0; i < size_n; ++i) {
            vec_B[i] = (double)rand() / RAND_MAX; // Random value between 0 and 1
            //printf(" %.2f", vec_B[i]); // Print each element of vec_B
        }
        //printf("] \n\n");

        // Initialize timing variables
        clock_t start, end;
        double sdot_c, sdot_asm;

        double c_duration = 0.0;
        double c_time = 0.0;

        // Time the C version
        for (int j = 0; j < 30; ++j) {
            start = clock();
            sdot_c = 0.0;
            for (int i = 0; i < size_n; i++) {
                sdot_c += vec_A[i] * vec_B[i];
            }
            end = clock();

            printf("start: %.12f, end: %.12f", (double)start, (double)end);
            c_duration = (double) end - (double) start; // Convert to milliseconds
            c_time += c_duration;
        }
        c_time = c_time / 30;

        printf("C version: %.12f milliseconds, dot product: %.2lf\n", c_time, sdot_c);

        // Time the assembly version

        double asm_duration = 0.0;
        double asm_time = 0.0;

        for (int j = 0; j < 30; ++j) {
            start = clock();
            sdot_asm = getDotProduct(vec_A, vec_B, size_n);
            end = clock();

            //printf("start: %.12f, end: %.12f", (double) start, (double) end);
            asm_duration = (double) end - (double) start;
            asm_time += asm_duration;
        }
        asm_time = asm_time / 30;

        double assembly_duration = ((double)(end - start)) / (CLOCKS_PER_SEC * 30) * 1000; // Convert to milliseconds
        printf("Assembly version: %.12f milliseconds, dot product: %.2lf\n\n\n", assembly_duration, sdot_asm);

        // Free dynamically allocated memory
        free(vec_A);
        free(vec_B);
    }

    return 0;
}
