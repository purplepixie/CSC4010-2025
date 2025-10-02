#include <stdio.h>
#include <omp.h>
#include <unistd.h>

int main()
{
    #pragma omp parallel
    {
        printf("Hello from thread %d\n", omp_get_thread_num());

        #pragma omp sections
        {
            #pragma omp section
            {
                printf("Hello from section 1 by thread %d\n", omp_get_thread_num());
                sleep(2);
            }

            #pragma omp section
            {
                printf("Hello from section 2 by thread %d\n", omp_get_thread_num());
            }

            #pragma omp section
            {
                printf("Hello from section 3 by thread %d\n", omp_get_thread_num());
            }

        }
        
        printf("Hello again from thread %d\n",omp_get_thread_num());
    }

    printf("Goodbye\n");

    return 0;
}