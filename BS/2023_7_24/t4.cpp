#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int n;
int a[N],tot;
int ans,anx=N;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _;
    cin >> _;
    while(_--){
        memset(a,0,sizeof a);
        ans=0,anx=N;
        string s;
        cin >> s;
        n=s.size();
        int p=0,mp=0;tot=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0')p++;
            else a[++tot]=p,a[++tot]=0,mp=max(mp,p),p=0;
        }
		a[++tot]=p;
		bool tr=0;
        for(int mi=1;mi<=n;mi++){
            int len=0,np=0;
            for(int i=1;i<=tot;i++){
            	//printf("%d %d:%d %d\n",mi,a[i],len,np);//
            	np+=a[i];
                if(a[i]==0){
                	if(len||np)tr=1;
                	continue;
                }
                if(a[i]>=mi||np>=mi){len++;np=0;}
                if(tr&&ans<(mi+1)*len-1){
                    ans=(mi+1)*len-1;
                    anx=mi;
                }
            }
        }
        
        if(ans==0)cout << "-1 -1\n";
        else cout << ans << " " << anx << "\n";
    }
}