#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7,mod=998244353;
int n,a[N],cnt[N],ans,live;


int main(){
	freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        cnt[a[i]]++;
    }

    for(int i=1;i<=N-1;i++){
        live=max(cnt[i],live);
    }

    cout<<live<<endl;
}