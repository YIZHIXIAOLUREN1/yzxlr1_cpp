#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int n;
int a[N],tot;
int ans,anx=N;
int ansl,dx,dy;
int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _;
    cin >> _;
    while(_--){
        memset(a,0,sizeof a);
        ans=0,anx=N;
        string s;
        cin >> s;
        n=s.size();
        dx=max((int)sqrt(n),1);
        int p=0,mp=0;tot=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0')p++;
            else a[++tot]=p,a[++tot]=0,mp=max(mp,p),p=0;
        }
		a[++tot]=p;
		bool tr=0;
        int mi=1;
        
        for(;mi<=n;mi++){
            int len=0,np=0,tr=0;
            for(int i=1;i<=tot;i++){
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
            
            
            dy=ans-ansl;
            //printf("%d:%d %d\n",mi,dy,dx);//
            if(mi>=dx&&dy>0)mi+=dy/dx;
            else if(mi>=dx&&dy<=0){
                mi=min(mi+2*(int)sqrt(n),n);
                break;
            }
            if(mi>=dx)dx=(ans-ansl)/dx+1;
            ansl=ans;
        }
        //cout << "A";//
        int mmi=max(anx-(int)sqrt(n),1);
        for(;mi>=mmi;mi--){
        	printf("%d\n",mi);//
            int len=0,np=0,tr=0;
            for(int i=1;i<=tot;i++){
            	np+=a[i];
                if(a[i]==0){
                	if(len||np)tr=1;
                	continue;
                }
                if(a[i]>=mi||np>=mi){len++;np=0;}
                if(tr&&ans<=(mi+1)*len-1){
                    ans=(mi+1)*len-1;
                    anx=min(anx,mi);
                }
            }
        }
        
        if(ans==0)cout << "-1 -1\n";
        else cout << ans << " " << anx << "\n";
    }
}
