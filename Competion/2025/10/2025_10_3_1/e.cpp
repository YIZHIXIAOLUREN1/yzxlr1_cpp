#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+7;
int n;
int ans[N],cnt;
vector<int> re[N];
int cc;
int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        cnt=0;
        int li=0;
        bool fl=0;
        for(int q=1;q<=n;q++){
            cout<<"? "<<n*n+1-li<<" ";
            for(int j=li+1;j<n*n+1;j++)cout<<j<<" ";
            cout<<n*n+1<<endl;
            int c;
            cin>>c;
            re[q].clear();
            for(int i=1,v;i<=c;i++){
                cin>>v;
                re[q].push_back(v);
            }
            if(c>re[cc].size()){
                cc=q;
            }
            if(c>=n+1){
                cout<<"! ";
                for(int i=1;i<n+1;i++)cout<<re[q][i-1]<<" ";
                cout<<re[q][n]<<endl;
                fl=1;
                break;
            }else{
                ans[++cnt]=re[q][c-1];
                li=re[q][c-1];
                if(re[q][c-1]==n*n+11)break;
                
            }
        }
        if(fl)continue;
        if(cnt>=n&&li<n*n+1){
            cout<<"! ";
            for(int i=1;i<n+1;i++)cout<<ans[i]<<" ";
            cout<<n*n+1<<endl;
            continue;
        }
        cout<<"! ";
        for(int i=0;i<re[cc].size()-1;i++)cout<<re[cc][i]<<" ";
        for(int i=0;i<n+1-re[cc].size();i++){
            cout<<re[cc+1][i]<<" ";
        }
        cout<<re[cc+1][n+1-re[cc].size()]<<endl;
    }
}
