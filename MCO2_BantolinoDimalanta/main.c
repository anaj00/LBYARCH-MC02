#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <time.h>
#include <math.h>

extern double getDotProductx64(size_t size_n, double* asm_dotProduct, double* vec_A, double* vec_B);

void getDotProduct(size_t size_n, double* ans, double* vec_A, double* vec_B){
    double dotProduct = 0.0;
    for(int i = 0; i < size_n; i++){
       dotProduct += vec_A[i] * vec_B[i];
    }
    *ans = dotProduct;
}


int main() {
    // Loop through different vector sizes
    const size_t size_n = 1 << 20;
    const size_t ARRAY_BYTES = size_n * sizeof(double);
    clock_t start, end;
    double loopTime, c_avg, asm_avg;
    double* c_dotProduct;
    double* asm_dotProduct;
    double* vec_A;
    double* vec_B;
    
    vec_A = (double*)malloc(size_n * sizeof(double));
    vec_B = (double*)malloc(size_n * sizeof(double));
    c_dotProduct = (double*)malloc(size_n * sizeof(double));
    asm_dotProduct = (double*)malloc(size_n * sizeof(double));
    
    // Initialize vec_A and vec_B with random values
    
    for (int i = 0; i < size_n; ++i) {
            vec_A[i] = (double)rand() / RAND_MAX; // Random value between 0 and 1
    }

    for (int i = 0; i < size_n; ++i) {
            vec_B[i] = (double)rand() / RAND_MAX; // Random value between 0 and 1
        }

    //cache    
    getDotProduct(size_n, &c_dotProduct, vec_A, vec_B);
    
    
    // Time C dotProduct function
    start = clock();
    for(int i = 0; i < 30; i++){
        getDotProduct(size_n, &c_dotProduct, vec_A, vec_B);
    }
    end = clock();
    loopTime = ((double) end - start) * 1e3 / CLOCKS_PER_SEC;
    c_avg = loopTime / 30;
    
    //cache
    getDotProductx64(size_n, &asm_dotProduct, vec_A, vec_B);
    

    // Time asm dotProduct Function
    start = clock();
    for (int i = 0; i < 30; i++){
        getDotProductx64(size_n, &asm_dotProduct, vec_A, vec_B);
    }
    end = clock();

    loopTime = ((double) end - start) * 1e3 / CLOCKS_PER_SEC;
    asm_avg = loopTime / 30;

    printf("C dot product function takes %lf milliseconds on average the dot product is %2lf \n", c_avg, c_dotProduct);
    printf("Asm dot product function takes %lf millisecons on average the dot product is %.2lf \n", asm_avg, asm_dotProduct);

    return 0;
}
