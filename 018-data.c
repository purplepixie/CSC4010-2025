#include <stdio.h>
#include <omp.h>
#include <unistd.h>

int main()
{
    int i=10, j=20;

    #pragma omp parallel default(none) shared(i) private(j)
    {
        //int i = 1;
        i++;
        j++;
        printf("Hello from thread %d where i=%d and j=%d\n",omp_get_thread_num(),i,j);
        
    }

    printf("Finally i=%d and j=%d\n",i,j);



    return 0;
}