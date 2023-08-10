#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mid ((l+r)>>1)
const int N=1e9+7,M=3e5+7;
int n,m,mm;
int a[M];

bool check(int x){
	//printf("%d\n",x);//
    if(x<=0)return 0;
    int res=0;
    for(int i=1;i<=m;i++){
        res+=a[i]/x;
        if(a[i]%x)res++;
        if(res>n)return 0;
    }
    //printf("%d\n",x);//
    return 1;
}


int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        cin >> a[i];
        mm=max(mm,a[i]);
    }
    sort(a+1,a+m+1);
    int l=1,r=mm;
    while(l<r){
        if(!check(mid))l=mid+1;
        else r=mid-1;
    }
    while(!check(l))l++;
    while(l>1&&check(l-1))l--;
    cout << l;
}