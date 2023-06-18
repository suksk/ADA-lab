#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i;
    for (i = 0; i < 2; i++)
    {
        plotter(i);
    }
}

void plotter(int p)
{
    char *T, *P;
    int n, m, k, i, j, count = 0;
    FILE *t;
    if (p == 0)
        t = fopen("w_string.txt", "w");
    else
        t = fopen("b_string.txt", "w");
    // Inputting the text
    T = (char *)malloc(200 * sizeof(char));
    for (i = 0; i < 200; i++)
    {
        T[i] = 'a';
    }

    // For best case
    if (p != 0)
    {
        for (i = 2; i < 200; i = i + 10)
        {
            P = (char *)malloc(i * sizeof(char));
            for (j = 0; j < i; j++)
            {
                P[j] = 'a';
            }

            m = i;
            n = 200;
            count = 0;
            count = StringMatch(T, P, n, m);
            fprintf(t, "%d\t%d\n", i, count);
        }
    }
    // for worst case
    if (p == 0)
    {
        for (i = 2; i < 200; i = i + 10)
        {
            P = (char *)malloc(i * sizeof(char));
            for (j = 0; j < i; j++)
            {
                if (j == i - 1)
                    P[j] = 'b';
                else
                    P[j] = 'a';
            }

            m = i;
            n = 200;
            count = 0;
            count = StringMatch(T, P, n, m);
            fprintf(t, "%d\t%d\n", i, count);
        }
    }
    fclose(t);
}

int StringMatch(char *T, char *P, int n, int m)
{
    int i, j, count = 0;
    for (i = 0; i <= n - m; i++)
    {
        j = 0;
        while (j < m && P[j] == T[i + j])
        {
            count++;
            if (T[i + j] != P[j])
                break;
            j = j + 1;
        }
        if (j == m)
            return count;
    }
    return count;
}