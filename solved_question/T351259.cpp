#include<bits/stdc++.h>
using namespace std;
#define N 1e9
#define db double
int x1,Y1,x2,y2,x3,y3;
db x4,y4;
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

void check(int x,int y){
    bool res=(x<=N&&y<=N&&x>=-N&&y>=-N);
    if(res){printf("%d %d",x,y);exit(0);}
}

void check1(db x,db y){
    if(fabs(x-round(x))<=1e-6&&fabs(y-round(y))<=1e-6){
        printf("%d %d",(int)round(x),(int)round(y));exit(0);}
}

int main(){
    scanf("%d%d%d%d",&x1,&Y1,&x2,&y2);
    int yo=(y2-Y1)/gcd(y2-Y1,x2-x1),
        xo=(x2-x1)/gcd(y2-Y1,x2-x1);

    x3=x1-yo;y3=Y1+xo;
    check(x3,y3);
    x3=x1+yo;y3=Y1-xo;
    check(x3,y3);
    x3=x2-yo;y3=y2+xo;
    check(x3,y3);
    x3=x2+yo;y3=y2-xo;
    check(x3,y3);
    check(x1,y2);
    check(x2,Y1);
    db xo1=((db)(x2-x1))/2,
       yo1=((db)(y2-Y1))/2;
    x4=x1+xo1-yo1;y4=Y1+yo1+xo1;
    check1(x4,y4);
    x4=x1+xo1+yo1;y4=Y1+yo1-xo1;
    check1(x4,y4);
}