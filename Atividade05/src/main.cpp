#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
using namespace std;

#define N 10

float A[N][N];
float B[N][N];
float C[N][N];

int main() {

    srand((unsigned int)time(NULL));

    int i,j,k,a = 5.0;

    omp_set_num_threads(omp_get_num_procs());

    for (i= 0; i< N; i++){
        for (j= 0; j< N; j++){

            A[i][j] = float(rand())/float((RAND_MAX)) * a;
            B[i][j] = float(rand())/float((RAND_MAX)) * a;

	    }
    }

    #pragma omp parallel for private(i,j,k) shared(A,B,C)
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            for (k = 0; k < N; ++k) {

                C[i][j] += A[i][k] * B[k][j];

            }
        }
    }

    for (i= 0; i< N; i++)
    {
        for (j= 0; j< N; j++)
        {
            printf("%f\t",C[i][j]);
        }
        printf("\n");
    }
   
}