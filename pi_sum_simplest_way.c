#include<omp.h>
#include<stdio.h>
static long num_steps=100000;
double step;
#define NUM_THREADS 2
void main(){
    int i;
    double pi=0.0,start,end,x,sum=0.0;
    omp_set_num_threads(NUM_THREADS);
    start=omp_get_wtime();
    step=1.0/(double) num_steps;
    #pragma omp parallel for private(x) reduction(+:sum)
    for(i=0;i<num_steps;i++){
        x=(i+0.5)*step;
        sum+=4.0/(1.0+x*x);
    }
    pi=step*sum;
    end=omp_get_wtime();
    printf("%f %f",end-start,pi);
}