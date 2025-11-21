#include <stdio.h>

#define M 100

void fun(int m, int *a, int *n)
{
    *n=0;
    for(int i=1;i<=m;i++)
        if(i%7==0||i%11==0)
            a[++*n]=i;
}

int main()
{  int aa[M], n, k;
   fun(50, aa, &n);
   for(k=1;k<=n;k++)
     if(k%20==0) printf("\n");
     else printf("%4d", aa[k]);
   printf("\n");
}