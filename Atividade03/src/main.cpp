#include <iostream>
#include <omp.h>

int main()
{  
    omp_set_num_threads(4);
    int sum = 0;
 #pragma omp parallel
 {
    // Todas as threads devem executar 
    printf("Todas as threads executam esta instrução! Sou a Thread %d\n", omp_get_thread_num());
    #pragma omp barrier
    #pragma omp sections
    {
        #pragma omp section
        {
            printf("Section A: Esta section vai ser executada somente pela thread %d !\n", omp_get_thread_num());
            for(int i =0; i<100000; i++)
            {
                double temp = 10.0 * 5.0;
            }
        }

        #pragma omp section
        {
            printf("Section B: Esta section vai ser executada somente pela thread %d !\n", omp_get_thread_num());
            for(int i =0; i<100000; i++)
            {
                double temp = 10.0 * 5.0;
            }
        }

        #pragma omp section
        {
            printf("Section C: Ultima secao vai ser executada pela thread %d !\n", omp_get_thread_num());
            for(int i =0; i<100000; i++)
            {
                double temp = 10.0 * 5.0;
            }
        }
    }
}
    
    printf("Por fim, todas as threads executam esta instrução ! Sou a Thread %d \n", omp_get_thread_num());
    #pragma omp critical
    {
        sum += 1;
    }
    printf("sum: %d\n", sum);
    
}