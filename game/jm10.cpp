#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7,len=3;
string s;
int ans;

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("jm10.in","r",stdin);
    cin>>s;
    for(int k=0;k<=255-len+1;k++){
        for(int i=k+1;i<=255-len+1;i++){
            bool fl=1;
            for(int j=0;j<len;j++){
                if(s[k+j]!=s[i+j]){fl=0;break;}
            }
            if(fl){
            	ans++;
                printf("%d %d:",k,i);//
                for(int j=0;j<len;j++)cout<<s[k+j];
                cout<<"\n";
            }
        }
    }
    cout<<ans;
}
