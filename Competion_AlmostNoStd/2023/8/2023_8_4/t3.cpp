#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int N=2e5+7;
int n;
ull a[N],b[N];
bool va[N],vb[N];
struct node{
    int x,y;
    ull s;
    friend bool operator < (node a,node b){
        return a.s>b.s;
    }
};
priority_queue<node> q;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++)cin >> a[i];
    for(int i=1;i<=n;i++)cin >> b[i];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ull c=a[i]^b[j];
            q.push({i,j,c});
        }
    }
    for(int i=1;i<n;i++){
        node u=q.top();
        q.pop();
        while(va[u.x]||vb[u.y])u=q.top(),q.pop();
        printf("%lld ",u.s);
        va[u.x]=vb[u.y]=1;
    }
    node u=q.top();
    q.pop();
    while(va[u.x]||vb[u.y])u=q.top(),q.pop();
    printf("%lld",u.s);
}
