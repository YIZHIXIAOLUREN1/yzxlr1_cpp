#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=3e5+7;
string s;
int n;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>s;
        n=s.size();
        if(n==1){cout<<"1\n";continue;}
        int f=1,t=-1,sx=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='<'){
                if(t==-1)continue;
                f=0;
                break;
            }else if(s[i]=='*'){
                if(i<n-1&&s[i+1]=='*')f=0;
                if(i<n-1&&s[i+1]=='<')f=0;
                if(i&&s[i-1]=='>')f=0;
                sx=i;
                if(!f)break;
            }else{
                if(t==-1)t=i;
            }
        }
        if(!f){cout<<"-1\n";continue;}
        t++;
        if(sx>=0){
        	sx++;
        	//cout<<sx<<":";//
        	cout<<max(sx,n-sx+1)<<"\n";
        	continue;
        }
        if(t<=1){
            cout<<n<<"\n";
            continue;
        }
        cout<<max(t-1,n-t+1)<<"\n";
    }
}