#include <stdio.h>
#include <omp.h>
#include <unistd.h>

int main()
{
    int i=10, j=20;

    #pragma omp parallel for default(none) shared(i) firstprivate(j) lastprivate(j)
    for (int x=0; x<20; ++x)
    {
        i++;
        j+=100-omp_get_thread_num();
        printf("Hello from thread %d where i=%d and j=%d and x=%d\n",omp_get_thread_num(),i,j,x);
    }   

    printf("Finally i=%d and j=%d\n",i,j);



    return 0;
}