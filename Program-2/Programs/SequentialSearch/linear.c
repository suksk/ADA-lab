#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int search(int*, int, int);
void plotter();

void main()
{
    int i=0;
    for(i=0;i<2;i++)
    {
        plotter(i);
    }
}

void plotter(int p)
{
    int *a,n,k,i,o;
    FILE *t;

    if(p==0)
    {
        t = fopen("worstlinear.txt","w");
    }
    else
    t = fopen("bestlinear.txt","w");

    srand(time(NULL));
    for(n=100; n<=30000; n = n<10000? (n*10) : (n + 10000))
    {
        a = (int*)malloc(n*sizeof(int));
        for(i=0;i<n;i++)
        {
            a[i] = rand()%n;
            //fprintf(t, "%d\t", *(a+i));
        }
        k = (p==0) ? (a[n-1] = -1) : (a[0]);
        o = 0;
        o = search(a, k, n);

        if(o != -1)
        fprintf(t, "%d\t%d\n", n, o);
        free(a);
    }
    fclose(t);
}

int search(int *a, int k, int n)
{
    int i, count=0;
    for(i=0;i<n;i++)
    {
        count++;
        if(*(a+i) == k)
        return count;
    }
    return count;
}

