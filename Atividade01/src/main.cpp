#include <stdio.h>
#include <omp.h>

int main(){

    omp_set_num_threads(4);
    int np = 0;
    int iam = 0;

    #pragma omp parallel private(np, iam)
    {
        np = omp_get_num_threads();
        iam = omp_get_thread_num();
        printf("Hello World! from thread %d of %d!\n", iam, np);
    }
    
    return 0;
}
