#include "push_swap.h"
int *merge(int *a,int size)
{
    int k;
    int j;
    int **p;

    j = 0;
    k = 0;
    p = fill(a,size);
    while(j < size / 2)
    {
        if(sorted(2,p[j]) == 0)
            p[j] = sa(p[j]);
        j++;
    }
    j = 0;
    while(j < size / 2)
    {
        k = 0;
        while(k < 2)
        {
             printf("s%d: %d\n",j+1, p[j][k]);
             k++;
        }
        j++;    
    }
    if(size % 2 != 0)
     printf("s%d: %d\n",j+1, p[j][0]);
    return a;
}
int **fill(int *a,int size)
{
    int (i),(k),(j);
    int **p;
    j = 0;
    
    i = 0;
    p = allocate(size);
    while(j < size / 2)
    {
        k = 0;
        while(k < 2)
        {
            p[j][k] = a[i];
            k++;
            i++;
        }
        j++;
    }
    if(size % 2 != 0)
        p[j][0]=a[i];
    return p;
}
int **allocate(int size)
{
    int (i),(j);
    int **p;
    j = 0;
    i = size / 2;
    if(size % 2 == 0)
    {
        p = malloc((i) * sizeof(int *));  
        while(j < i)
            p[j++] = malloc((2) * sizeof(int)); 
    }
    else{
        p = malloc((i + 1) * sizeof(int *));   
         while(j < i)
            p[j++] = malloc((2) * sizeof(int));
        p[j] = malloc(sizeof(int));
    }
    return p;
}
