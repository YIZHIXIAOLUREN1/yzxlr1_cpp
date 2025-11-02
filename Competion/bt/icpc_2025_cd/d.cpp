#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int A,B,n,P,k;
bool check(int x,int y){
    int res=1;
    if(x)res&=(A==x||(A>=x+2&&A<=x*8));
    else res&=A==0;
    if(y)res&=(B==y||(B>=y+2&&B<=y*8));
    else res&=B==0;
    return res;
}
bool svd;
void pr(int x,int y){
    svd=1;
    int xj;
    if(A==x)xj=0;
    else xj=(A-x+6)%7;
    while(x--){
        cout<<"1";
        A--;
        if(xj){
            if((A-x)%7==1){
                cout<<"6";
                A-=6;
            }else{
                cout<<min(A-x,7);
                A-=min(A-x,7);
            }
            xj--;
        }else{
            cout<<"//";
        }
    }
    cout<<"/";
    int yj;
    if(B==y)yj=0;
    else yj=(B-y+6)%7;
    while(y--){
        cout<<"1";
        B--;
        if(yj){
            if((B-y)%7==1){
                cout<<"6";
                B-=6;
            }else{
                cout<<min(B-y,7);
                B-=min(B-y,7);
            }
            yj--;
        }else{
            cout<<"//";
        }
    }
}
bool chec(){
    int mn=min(n,15);
    for(int i=0;i<=mn;i++){
        if(check(i,mn-i)){
            pr(i,mn-i);
            return 1;
        }
    }
    return 0;
}
queue<int> ka,kb;
void dfs(int u,int ki,int kj){//2,3,...7
    if(svd)return;
    if(u>7){
        if(ki+kj==k){
        	//printf("%d%,d:%d\n",A,B,chec());//
            chec();
        }
        return;
    }
    if(ki+kj<k&&A>=u){
        A-=u;
        dfs(u+1,ki+1,kj);
        A+=u;
        if(svd)ka.push(u);
    }
    if(svd)return;
    if(ki+kj<k&&B>=u){
        B-=u;
        dfs(u+1,ki,kj+1);
        B+=u;
        if(svd)kb.push(u);
    }
    if(svd)return;
    if(7-u>=k-ki-kj)dfs(u+1,ki,kj);
}

void Solve(){
    while(!ka.empty())ka.pop();
    while(!kb.empty())kb.pop();
    svd=0;
    cin>>A>>B>>n>>P;
    n=21-n;
    if(n<=15){
        chec();
    }else{
        k=n-15;
        dfs(2,0,0);
        if(svd){
            while(!kb.empty()){
                cout<<kb.front();
                kb.pop();
            }
            cout<<"/";
            while(!kb.empty()){
                cout<<kb.front();
                kb.pop();
            }
            cout<<"/";
        }
    }
    if(!svd){
        cout<<"NA\n";
        return;
    }
    if(!P)cout<<"/";
    cout<<"\n";
}

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        Solve();
    }
}
/*
n=21-n//!!!

i j[0-i]

i+2*j,i+7*j
->i,[i+2,i+7*i]
i [0-15]
->a ->b

n>15{
    k=n-15
    2-7
    k
    (k+3)*k/2,(15-k)*k/2
}
O(lk*15)->2000*27*15
C(6,i)*C(6-i,k-i)=>C(6,k)*2^k//3,320;4,240
2000*320*15//1e7
*/