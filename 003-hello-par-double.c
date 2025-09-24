#include <stdio.h>
#include <omp.h>

int main()
{
    #pragma omp parallel
    {
        printf("Hello\n");
        #pragma omp parallel
        {
            printf("World\n");
        }
    }

    printf("Goodbye\n");
    return 0;
}