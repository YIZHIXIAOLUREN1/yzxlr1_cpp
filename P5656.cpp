#include<bits/stdc++.h>
using namespace std;
#define int long long
int T;
int a,b,c,xx,yy,dx,dy,fla;
int a1x,a1y,a2x,a2y,ak;
int gcd(int a,int b){
    if(a%b==0)return b;
    else return gcd(b,a%b);
}

void exgcd(int a,int b,int &x,int &y){
    if(a%b==0)x=0,y=1;
    else exgcd(b,a%b,y,x),y-=a/b*x;
}

signed main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> T;
    while(T--){
    	fla=0;
    	a1x=a1y=0x3f3f3f3f,a2x=a2y=0;
        cin >> a >> b >> c;
        int d=gcd(a,b);
        if(c%d){
            cout<<"-1\n";
            continue;
        }
        exgcd(a,b,xx,yy);
        dx=b/d,dy=-a/d;
        xx*=c/d,yy*=c/d;
        if(xx>0&&yy>0)a1x=a2x=xx,a1y=a2y=yy;
        //printf("%d %d:\n",xx,yy);//
        if(xx<=0){
            int k=(-xx)/dx+1;
            xx+=k*dx;
            yy+=k*dy;
            if(yy<=0)fla=1;
            if(xx>0)a1x=min(a1x,xx);
            if(yy>0)a2y=max(a2y,yy);
           //printf("x%d %d:\n",xx,yy);//
        }
        if(yy<=0){
            int k=(-yy)/dy-1;
            xx+=k*dx;
            yy+=k*dy;
            if(xx<=0)fla=1;
            if(yy>0)a1y=min(a1y,yy);
            if(xx>0)a2x=max(a2x,xx);
            //printf("y%d %d:\n",xx,yy);//
        }
        if(xx<=0){
            int k=(-xx)/dx+1;
            xx+=k*dx;
            yy+=k*dy;
            if(yy<=0)fla=1;
            if(xx>0)a1x=min(a1x,xx);
            if(yy>0)a2y=max(a2y,yy);
            //printf("x%d %d:\n",xx,yy);//
        }
        if(yy>-dy){
        	int k=(yy-1)/(-dy);
        	xx+=k*dx;
        	yy+=k*dy;
            //printf("xx%d %d:\n",xx,yy);//
        }if(yy>0&&xx>0)a1y=min(a1y,yy),a2x=max(a2x,xx);
        if(xx>dx){
        	int k=-(xx-1)/dx;
        	xx+=k*dx;
        	yy+=k*dy;
            //printf("yy%d %d:\n",xx,yy);//
        }if(xx>0&&yy>0)a1x=min(a1x,xx),a2y=max(a2y,yy);
        ak=(a2x-a1x)/dx+1;
        if(fla){
            cout << a1x << " " << a1y << "\n";
            continue;
        }
        cout << ak << " " << a1x << " " << a1y << " " << a2x << " " << a2y << "\n";

    }
}