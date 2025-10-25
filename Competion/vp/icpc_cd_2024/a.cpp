#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int n;
string s;
int res;
vector<pair<int,int>> ans;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>s;
        n=s.length();
        res=0;
        ans.clear();
        if(s[0]=='-'){
            cout<<"No\n";
            //cout<<"A";//
            continue;
        }
        int fl=n;
        for(int i=n;i>=1;i--){
            fl=i;
            if(s[i-1]=='-')break;
        }
        if(fl>=n-2||fl==1){
            cout<<"No\n";
            continue;
        }
		
		int j=n;
        for(;j>=fl+3;j-=3){
            ans.push_back({1,j});
            res++;
        }
        if(j!=fl){
        	ans.push_back({1,fl+3});
            res++;
        }
        for(int i=2;i<fl;i++){
            if(s[i-1]=='-')continue;
            ans.push_back({i,fl+3});
            res++;
        }
        if(res>n){cout<<"No\n";continue;}
        cout<<"Yes "<<res<<"\n";
        for(auto [l,r]:ans){
            cout<<l<<" "<<r-l+1<<"\n";
        }
    }
}