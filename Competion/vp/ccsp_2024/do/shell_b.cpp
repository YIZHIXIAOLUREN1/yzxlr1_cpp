#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+7,M=1e6+7;
int n,m;
int a[N];
int cnt[M];
void query(int l,int r){
    int i=l;
    for(i=l;i<=r-7;i+=8){
        cnt[a[i]]=0;cnt[a[i+1]]=0;cnt[a[i+2]]=0;cnt[a[i+3]]=0;
        cnt[a[i+4]]=0;cnt[a[i+5]]=0;cnt[a[i+6]]=0;cnt[a[i+7]]=0;
    }
    for(;i<=r;i++){
        cnt[a[i]]=0;
    }
    int res1=0,res2=0,res3=0,res4=0,res5=0,res6=0,res7=0,res8=0;
    for(i=l;i<=r-7;i+=8){
        if(!cnt[a[i]])cnt[a[i]]++,res1++;
        if(!cnt[a[i+1]])cnt[a[i+1]]++,res2++;
        if(!cnt[a[i+2]])cnt[a[i+2]]++,res3++;
        if(!cnt[a[i+3]])cnt[a[i+3]]++,res4++;
        if(!cnt[a[i+4]])cnt[a[i+4]]++,res5++;
        if(!cnt[a[i+5]])cnt[a[i+5]]++,res6++;
        if(!cnt[a[i+6]])cnt[a[i+6]]++,res7++;
        if(!cnt[a[i+7]])cnt[a[i+7]]++,res8++;
    }
    for(;i<=r;i++){
    	//printf("%d:%d %d\n",i,a[i],cnt[a[i]]);//
        if(!cnt[a[i]])cnt[a[i]]++,res1++;
    }
    //for(int i=l;i<=r;i++)cout<<cnt[a[i]]<<" \n"[i==r];//
    
    // cout<<res1<<"\n";//
    // cout<<res2<<"\n";//
    // cout<<res3<<"\n";//
    // cout<<res4<<"\n";//
    // cout<<res5<<"\n";//
    // cout<<res6<<"\n";//
    // cout<<res7<<"\n";//
    // cout<<res8<<"\n";//
    cout<<res1+res2+res3+res4+res5+res6+res7+res8<<"\n";
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    while(m--){
        int op,s1,s2;
        cin>>op>>s1>>s2;
        if(op==1){
            query(s1,s2);
        }else if(op==2){
            a[s1]=s2;
        }else{
            for(int i=n;i>s1;i--){
                a[i+1]=a[i];
            }
            a[s1+1]=s2;
            n++;
        }
    }
}