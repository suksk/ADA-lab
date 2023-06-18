#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count = 0;
void plotter(int p);
int binary(int* ,int ,int,int);
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
    int i,n,c,*a,k,l,r;
    FILE *t;

    if(p==0)
    t = fopen("worst_rec.txt", "w");
    else
    t = fopen("best_rec.txt", "w");

    srand(time(NULL));

    for(n=10; n<10000; n = n<1000? (n * 10) : (n + 1000))
    {
        a = (int*)malloc(n*sizeof(int));
        for(i = 0; i < n; i++)
        {
            *(a+i) = i * 10;
        }

        k = (p==0) ? (*(a+n-1) = -1) : (*(a + (n-1)/2));
        count = 0;
        l = 0; r = n-1;
        c = binary(a, l, r, k);
        
        fprintf(t, "%d\t%d\n", n, count);
        free(a);
    }
    fclose(t);

}

int binary(int *a, int l, int r, int k)
{
    if(l > r)
    {
       count++;
       return -1;
    }
    int mid = (l + r)/2;
    if(a[mid] == k)
    {
        count++;
        return mid;
    }
    else if(a[mid] > k)
    {
        count++;
        return binary(a, l, mid-1, k);
    }
    else
    {
        count++;
        return binary(a, mid+1, r, k);
    }

}