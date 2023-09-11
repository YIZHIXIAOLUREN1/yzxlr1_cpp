#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define print(x) if(x==0)putchar('0');else write(x)
const int N=50005;
int n,L;
int s[N];
ll f[N];

inline void read(register int &x){
    x=0;register int f=1;register char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
    x*=f;
}
inline void write(register ll x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}

inline ll a(int x){return s[x]+x;}
inline ll b(int x){return s[x]+x+L+1;}
inline ll px(int x){return b(x);}
inline ll py(int x){return f[x]+b(x)*b(x);}
inline db slope(int x,int y){return ((db)(py(y)-py(x)))/((db)(px(y)-px(x)));}
int q[N];
int head=1,tail=1;

int main(){
    read(n),read(L);
    for(int i=1;i<=n;i++){
        read(s[i]);
        s[i]+=s[i-1];
    }
    for(int i=1;i<=n;i++){
        while(head<tail&&slope(q[head+1],q[head])<2*a(i))head++;
        f[i]=f[q[head]]+(a(i)-b(q[head]))*(a(i)-b(q[head]));
        while(head<tail&&slope(q[tail],q[tail-1])>slope(q[tail-1],i))tail--;
        q[++tail]=i;
    }
    print(f[n]);
	return 0;
}