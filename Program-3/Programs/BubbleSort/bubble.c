#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int bubble(int *, int);
void plotter(int);

void main()
{
    int i;
    for(i=0;i<2;i++)
    {
        plotter(i);
    }
}

void plotter(int p)
{
    int i,n,c,*a;
    FILE *t;

    if(p==0)
    {
        t = fopen("worstbubble.txt","w");
    }
    else
    t = fopen("bestbubble.txt","w");

    srand(time(NULL));

    for(n=10; n<1000; n= n<100 ? n*10 : n + 100)
    {
        a = (int*)malloc(sizeof(int)*n);

        if(p==0){
        for(i=0; i<n; i++)
        {
            a[i] = rand()%n ;
            //fprintf(t,"%d\t",a[i]);
        }
        }

        if(p!=0)
        {
            for(i=0; i<n; i++)
        {
            a[i] = i ;
            //fprintf(t,"%d\t",a[i]);
        }
        }
        c = 0;
        c = bubble(a, n);
        fprintf(t,"%d\t%d\n",n,c );
        free(a);
    }
    fclose(t);
}

int bubble(int *a, int n)
{
    int i,j,temp,flag,count=0;

    for(i=0; i<=n-2; i++)
    {
        flag = 0;
        for(j=0; j<=n-2-i; j++)
        {
            count++;
            if(a[j+1] < a[j])
            {
                flag = 1;
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
        if(flag != 1)
        return count;
    }
    return count;
}