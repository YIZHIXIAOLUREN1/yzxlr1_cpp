#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int n,root,a[N],ans;
int ll,lr,rl,rr;
int test_l(){
    int x=root;
    while(x>=1&&a[x-1]==0)x--;
    if(x==0)return 1;
    x--;
    return x+1;
}

int test_r(){
    int x=root;
    while(x<=n&&a[x+1]==0)x++;
    if(x==n+1)return 1;
    x++;
    return n-x+2;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n >> root;
        string s;
        cin >> s;
        for(int i=0;i<n;i++){
            a[i+1]=(s[i]=='#')?1:0;
        }
        ans=N;
        if(root==1||root==n){cout<<"1\n";continue;}
        if(a[root-1]==0){
            a[root-1]=1;
            ll=test_l();
            lr=test_r();
            a[root-1]=0;
        }
        if(a[root+1]==0){
            a[root+1]=1;
            rl=test_l();
            rr=test_r();
            a[root+1]=0;
        }
        if(a[root-1]==0&&a[root+1]==0){
            ans=max(min(ll,lr),min(rl,rr));
        }else if(a[root-1]==0&&a[root+1]==1)ans=min(ll,lr);
        else if(a[root-1]==1&&a[root+1]==0)ans=min(rl,rr);
        else{
            ans=min(test_l(),test_r());
        }
        cout<<ans<<"\n";
    }
}
/*
#..1#.
#.#1#. #.#.1.
#.#.1#





*/