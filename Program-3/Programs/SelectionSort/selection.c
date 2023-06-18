#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int SS(int *,int);

void main()
{
    FILE *t;
    int *a, i, n, c;

    t = fopen("SS.txt","w");

    srand(time(NULL));
    for(n=10; n<10000; n= n<1000 ? n*10 : n + 1000)
    {
        a = (int*)malloc(sizeof(int)*n);
        for(i=0; i<n; i++)
        {
            *(a+i) = rand()%n;
        }
        c=0;
        c = SS(a, n);
        fprintf(t, "%d\t%d\n", n, c);

        free(a);
    }
    fclose(t);
}

int SS(int* a,int n)
{
    int i,j,min,temp,count=0;

    for(i=0;i<=n-2;i++)
    {
        min = i;
        for(j=i+1; j<=n-1; j++)
        {
            count++;
            if(a[j] < a[min])
            {
                min = a[j];
            }
        }
        //if(min != i)
        //{
            temp = a[i];
            a[i] = a[i+1];
            a[i+1] = temp;
        //}
    }
    return count;
}