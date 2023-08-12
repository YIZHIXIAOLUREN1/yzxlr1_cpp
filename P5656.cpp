#include<bits/stdc++.h>
using namespace std;
#define ll long long
int T;
int a,b,c,xx,yy;

int gcd(int a,int b){
    if(a%b==0)return b;
    else return gcd(b,a%b)
}

void exgcd(int a,int b,int &x,int &y){
    if(a%b==0)x=0,y=1;
    else exgcd(b,a%b,y,x),y-=a/b*x;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> T;
    while(T--){
        cin >> a >> b >> c;
        int d=gcd(a,b);
        if(c%d){
            cout<<"-1\n";
            continue;
        }
        exgcd(a,b,xx,yy);
        xx*=d,yy*=d;
    }
}
