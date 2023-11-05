#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+7;
int n;
ll ans;
struct node{int l,r,id;}a[N];
struct node1{int l,r,id;};
struct node2{int l,r,id;};
bool operator <(node1 x,node1 y){return x.r<y.r;}
bool operator <(node2 x,node2 y){return x.l>y.l;}
bool vis[N];
priority_queue<node1> q1;
priority_queue<node2> q2;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin>>a[i].l>>a[i].r;
        node1 x;node2 y;
        x.id=i;x.l=a[i].l;x.r=a[i].r;
        y.id=i;y.l=a[i].l;y.r=a[i].r;
        q1.push(x);
        q2.push(y);
    }
    while(!q1.empty()){
        while(!q1.empty()&&vis[q1.top().id])q1.pop();
        while(!q2.empty()&&vis[q2.top().id])q2.pop();
        if(q1.empty()||q2.empty())break;
        node1 x=q1.top();node2 y=q2.top();
        q1.pop();q2.pop();
        vis[x.id]=vis[y.id]=1;
        if(x.id==y.id){
        	while(!q1.empty()&&vis[q1.top().id])q1.pop();
            while(!q2.empty()&&vis[q2.top().id])q2.pop();
            if(q1.empty()&&!q2.empty()){y=q2.top();q2.pop();}
            else if(q2.empty()&&!q1.empty()){x=q1.top();q1.pop();}
            else if(q1.empty()||q2.empty())break;
            else if(q1.top().r-x.l>x.r-q2.top().l){x=q1.top();q1.pop();}
            else{y=q2.top();q2.pop();}
        }
        vis[x.id]=vis[y.id]=1;
        //printf("%d:%d\n",x.id,y.id);//
        ans+=x.r-y.l;
    }
    cout << ans;
}