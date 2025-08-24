#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
int n,Q;
int fa[N],fh[N];
bool v[N];
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
    int fx=find(x),fy=find(y);
    fa[fx]=fy;
    fh[fy]+=fh[fx];
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>Q;
    for(int i=1;i<=n;i++)fa[i]=i;
    while(Q--){
        int ch,x,y;
        cin>>ch;
        if(ch==1){
            cin>>x>>y;
            if(find(x)==find(y))continue;
            else merge(x,y);
        }else if(ch==2){
            cin>>x;
            if(!v[x]){
                v[x]=1;
                fh[find(x)]++;
            }else{
                v[x]=0;
                fh[find(x)]--;
            }
        }else{
            cin>>x;
            if(fh[find(x)])cout<<"Yes\n";
            else cout<<"No\n";
        }
    }
}
