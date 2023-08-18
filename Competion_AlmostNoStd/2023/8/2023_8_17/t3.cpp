#include<bits/stdc++.h>
using namespace std;
const int N=50;
int n;
int q[N],s[N],top=0;
int a[N];
int ans;

void check(){
    memcpy(s,q,sizeof q);
    sort(s+1,s+n+2);
    int res=1;
    //cout<<s[1]<<" ";//
    for(int i=2;i<=n+1;i++){
    	//cout<< s[i] << " \n"[i==n+1];//
        if(s[i]==s[i-1]+1)res++;
        else ans=max(ans,res),res=1;
    }
    ans=max(ans,res);
}

void dfs(int u,int tot){
	//printf("%d:%d:\n",u,tot);//
	//for(int i=1;i<=top;i++)cout<<q[i]<<" \n"[i==top];//
	if(tot==n+1){
    	//printf("%d:%d:\n",u,tot);//
        check();
        return;
    }
	if(tot>n+1||u>n)return;
    
    q[++top]=a[n+1+u];
    dfs(u+1,tot+1);
    q[++top]=a[n+1-u];
    dfs(u+1,tot+2);
    top-=2;
    q[++top]=a[n+1-u];
    dfs(u+1,tot+1);
    top--;
}


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    if(n>10)cout<<n+1;
    else{
    	for(int i=1;i<=2*n+1;i++)cin >> a[i];
    	q[++top]=a[n+1];
    	dfs(1,1);
    	cout << ans;
    }
}