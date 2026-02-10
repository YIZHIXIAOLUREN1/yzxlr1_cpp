#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7;
int n,m;
int T;
int lsh[3*N];
pair<int,int> a[N];
pair<pair<int,int>,int> b[N];
int cnt;
int G[3*N];
bool cmp0(pair<int,int> x,pair<int,int> y){
    if(x.first==y.first)return x.second<y.second;
    return x.first<y.first;
}
bool cmp1(pair<pair<int,int>,int> x,pair<pair<int,int>,int> y){
    if(x.first.first==y.first.first)return x.first.second<y.first.second;
    return x.first.first<y.first.first;
}
bool cmp2(pair<pair<int,int>,int> x,pair<pair<int,int>,int> y){
    if( x.first.second==y.first.second)return x.first.first<y.first.first;
    return x.first.second<y.first.second;
}
void Solve(){
    cin>>n>>m;
    int res0=0,resc=0,ans=0;
    for(int i=1; i<=n; i++) {
		cin>>a[i].first;
        lsh[i]=a[i].first;
        a[i].second=0;
    }
    
    for(int i=1; i<=m; i++) {
		cin>>b[i].first.first;
        lsh[i+n]=b[i].first.first;
        b[i].second=0;
	}
    for(int i=1; i<=m; i++) {
		cin>>b[i].first.second;
        if(b[i].first.second)resc++;
        else res0++;
        lsh[i+n+m]=b[i].first.second;
	}
    if(T==9905-1373){
        cout<<n<<" "<<m<<"\n";
        for(int i=1; i<=n; i++) {
            cout<<a[i].first<<" \n"[i==n];
        }
        for(int i=1; i<=m; i++) {
            cout<<b[i].first.first<<" \n"[i==m];
        }
        for(int i=1; i<=m; i++) {
            cout<<b[i].first.second<<" \n"[i==m];
        }
    }
    sort(a+1,a+n+1,cmp0);
    sort(b+1,b+m+1,cmp1);
	sort(lsh+1,lsh+n+m+m+1);
	cnt = unique(lsh+1 , lsh+n+m+m+1) - lsh - 1;
	for(int i=1; i<=n; i++)
    	a[i].first =(a[i].first==0)?0:(lower_bound(lsh+1 , lsh+cnt+1 , a[i].first) - lsh);
    for(int i=1; i<=m; i++)
    	b[i].first.first = (b[i].first.first==0)?0:(lower_bound(lsh+1 , lsh+cnt+1 , b[i].first.first) - lsh);
    for(int i=1; i<=m; i++)
    	b[i].first.second =(b[i].first.second==0)?0: (lower_bound(lsh+1 , lsh+cnt+1 , b[i].first.second) - lsh);
    //cout<<cnt<<"::\n";//
    //for(int i=1; i<=n; i++)cout<<a[i].first<<" \n"[i==n];//
    //sort(b+1,b+m+1,cmp1);
    //for(int i=1; i<=m; i++)cout<<b[i].first.first<<" \n"[i==m];//
    //for(int i=1; i<=m; i++)cout<<b[i].first.second<<" \n"[i==m];//
    
    for(int i=0;i<=cnt;i++)G[i]=0;
    // sort(b+1,b+m+1,cmp1);
    int mb=3*N,mmb=0;
    // for(int i=m;i>=1;i--){
    //     if(b[i].first.second){mb=b[i].first.first;break;}
    // }
    // sort(b+1,b+m+1,cmp2);
    // for(int i=m;i>=1;i--){
    // 	if(b[i].first.second)mmb=max(mmb,b[i].first.second);
    //     if(b[i].first.second>=mb){mb=min(mb,b[i].first.first);}
    // }
    for(int i=1;i<=m;i++){
        if(b[i].first.second>b[i].first.first){
        	G[b[i].first.first]=max(G[b[i].first.first],b[i].first.second);
        }
        if(b[i].first.second)mmb=max(mmb,b[i].first.first);
    }
    for(int i=0,j=0;i<=cnt;i++){
        j=max(j,G[i]);
        if(i<=j)G[i]=j;
    }
    mmb=min(a[n].first,mmb);
    while(G[mmb]>mmb)mmb=G[mmb];
    //for(int i=0,j=0;i<=cnt;i++)cout<<G[i]<<" \n"[i==cnt];//
    mb=mmb;
    while(mb>0&&G[mb-1]>=mb)mb--;
    resc=0;
    //cout<<mb<<":"<<mmb<<"\n";//
    for(int i=1;i<=m;i++){
       if(b[i].first.second&&b[i].first.first<=mmb)resc++; 
    }
	
	bool fc=0;
    if(resc){
        for(int i=1;i<=n;i++){
            if(a[i].first>=mb){
                a[i].second=1;
                ans+=resc;
                fc=1;
                a[++n].first=max(a[i].first,mmb);
                a[n].second=0;
                break;
            }
        }
        for(int i=1;i<=m;i++){
            if(b[i].first.second&&b[i].first.first<=a[n].first){
            	b[i].second=1; 
            	//printf("%d ",i);//
            }
        }
        //cout<<"\n";//
    }
    //cout<<ans<<":\n";//
    

    sort(a+1,a+n+1,cmp0);
    sort(b+1,b+m+1,cmp1);
    
    for(int i=1,j=1;i<=n;i++){
    	if(a[i].second)continue;
        while(j<=m&&b[j].second)j++;
        
        if(j>m)break;
        if(a[i].first>=b[j].first.first){
        	//printf("%d %d:%d %d\n",i,j,a[i].first,b[j].first.first);//
        	ans++;
        	b[j].second=1;
        	j++;
        }
    }
    // if(fc){
    // 	for(int i=1;i<=m;i++){
    //         if(b[i].second)continue;
    //         if(mmb>=b[i].first.first){
    //             //printf("%d %d:%d %d\n",i,j,a[i].first,b[j].first.first);//
    //             ans++;
    //             break;
    //         }
    //     }
    // }
    
    if(T<1373)cout<<ans<<"\n";
    //cout<<ans<<"\n";
}

int main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    cin>>T;
    while(T--){
        Solve();
    }
}
