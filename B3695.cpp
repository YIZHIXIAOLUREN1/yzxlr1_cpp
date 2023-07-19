#include<bits/stdc++.h>
using namespace std;
#define N 30010
int n,m,q;
bitset<N> s[N],s0;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >> q;
    for(int i=0;i<m;i++)s0[i]=1;
    for(int i=1,c,x;i<=n;i++){
        cin >> c;
        for(int j=1;j<=c;j++)cin >> x,s[i][x-1]=1;
    }
    while(q--){
        int o,x,y;
        cin >> o >> x >> y;
        if(o==1)s[x]<<=y,s[x]&=s0;
        else if(o==2)s[x]>>=y;
        else if(o==3)cout << (s[x]&s[y]).count() << endl;
        else if(o==4)cout << (s[x]|s[y]).count() << endl;
        else cout << (s[x]^s[y]).count() << endl;
    }
}