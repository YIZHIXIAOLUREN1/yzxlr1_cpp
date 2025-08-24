#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+7,NN=5e6+7;
int n,m,K;
bool a[NN];//i*m+j
int up[NN];
int q[N],head,tail;
ll ans;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>K;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        for(int j=1;j<=m;j++){
            int vij=i*m+j;
            if(s[j-1]=='#')a[vij]=1;
        }
    }

    for(int j=1;j<=m;j++){
        int res=0;
        for(int i=1;i<=n;i++){
            int vij=i*m+j;
            if(!a[vij]){res++;up[vij]=res;}
            else res=0;
            
        }
    }
    
    for(int i=1;i<=n;i++){
        head=1,tail=0;
        for(int j=1;j<=m;j++){
            int vij=i*m+j;
            if(a[vij]){head=1,tail=0;continue;}
            while(head<=tail&&q[head]%m<=j-K)head++;
            while(head<=tail&&up[q[tail]]>=up[vij])tail--;
            q[++tail]=vij;

            for(int vk=head;vk<tail;vk++){
                for(int k=q[vk]%m;k<q[vk+1]%m;k++){
                    ans+=1ll*(j-k+1)*min(K/(j-k+1),up[q[vk]]);
                }
            }
            ans+=min(up[vij],K);
        }
    }
    cout<<ans;
}
