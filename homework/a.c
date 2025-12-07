#include <stdio.h>

void jhmaxmin(int *p,int n){
    int *max,*min,*end,*q,t;
    end=p+n;
    max=min=p;
    for(q=p+1;q<end;q++){
        if(*q>*max) max=q;
        if(*q<*min) min=q;
    }
    t=*max; *max=*min; *min=t;
}

int main(){
    int i; static int a[8]={10,5,4,0,12,18,20,46};
    printf("Original array:\n");
    for(i=0;i<8;i++) printf("%5d",a[i]);
    printf("\n");
    jhmaxmin(a,8);
    printf("Array after swaping max and min:\n");
    for(i=0;i<8;i++) printf("%5d",a[i]);
    printf("\n");
    return 0;
}