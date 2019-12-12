#include <stdio.h>
#include <omp.h>
#include <stdlib.h> 
#include <time.h>

#define N 100

int max(int A[])
{
    int idx;
    int max_val = 0;

    #pragma omp parallel for reduction(max:max_val) 
    for (idx = 0; idx < N; idx++)
       max_val = max_val > A[idx] ? max_val : A[idx];

    return max_val;
}

int main() {

    srand(time(0));

    int v1[N], v2[N], v3[N];

    for (int i = 0; i < N; i++)
    {
        v1[N] = rand();
        v2[N] = rand();
        v3[N] = rand();
    }

    printf("\n%d\n", max(v1));
    printf("%d\n", max(v2));
    printf("%d\n", max(v3));
    
    
}