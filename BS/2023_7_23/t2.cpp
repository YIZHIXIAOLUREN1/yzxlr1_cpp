#include<bits/stdc++.h>
using namespace std;
const int N=2007,mod1=1e9+7,mod2=998244353;

inline int read(){
    int res=0,f=1;
    char ch=' ';
    while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
    if(ch=='-')f=-1,ch=getchar();
    while(ch>='0'&&ch<='9')res=res*10+ch-'0',ch=getchar();
    return res*f;
}

int n,P;
int a[N],tot;
int ans;
vector<int> p[N];

void dfs(int u){
	//printf("%d\n",u);//
    if(u==n+1){
    	// for(int i=1;i<=u;i++){
    		// for(int j=0;j<p[i].size();j++){
        		// cout << p[i][j] << " \n"[j==p[i].size()-1];
	        // }
    	// }
    	// cout << "e";
    	ans++;return;
    }
    for(int i=1;i<=u;i++){
    	if(p[i].size()==0){
    		p[i].push_back(u);
    		//printf("ad%d:%d\n",i,u);//
    		dfs(u+1);
    		p[i].pop_back();
    		break;
    	}
        int ma=N;
        for(int j=0;j<p[i].size();j++)ma=min(ma,a[p[i][j]]);
        if(ma>p[i].size()){
            p[i].push_back(u);
            //printf("j%d:%d:%d\n",i,u,ma);//
            dfs(u+1);
            p[i].pop_back();
        }
    }
}

int main(){
    n=read(),P=read();
    for(int i=1,x;i<=n;i++){
        x=read();
        for(int j=tot+1;j<=min(tot+x,n);j++)a[j]=i;
        tot+=x;
        if(tot>n)break;
    }
    for(int i=tot+1;i<=n;i++)a[i]=n;
    //p[1].push_back(1);
    dfs(1);
    cout << ans%P;
}