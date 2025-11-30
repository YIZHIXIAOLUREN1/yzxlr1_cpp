#include<bits/stdc++.h>
using namespace std;
const int N=4e5+7;
int n,a[N],nc[N],cnt[N],tot;
vector<int> vec;

void Solve(){
    cin>>n;
    for(int i=1;i<=2*n;i++) nc[i]=0;
    for(int i=1;i<=2*n;i++){
        cin>>a[i];
        nc[a[i]]++;
    }
    int O=0,E=0;
    long long sum_odd=0,sum_even=0;
    vec.clear();
    for(int i=1;i<=2*n;i++){
        if(nc[i]){
            if(nc[i]%2==1){
                O++;
                sum_odd+=nc[i];
            }else{
                E++;
                sum_even+=nc[i];
                vec.push_back(nc[i]);
            }
        }
    }
    sort(vec.rbegin(),vec.rend());
    vector<long long> pre1(E+1);
    pre1[0]=0;
    for(int i=1;i<=E;i++) pre1[i]=pre1[i-1]+vec[i-1];
    int ans=O;
    for(int k=min(E,n);k>=0;k--){
        long long M1=pre1[k]-k;
        long long M2=sum_even-pre1[k];
        long long L0=max(1ll*k,n-sum_odd);
        long long R0=min(1ll*n,M1+M2);
        if(L0<=R0&&(L0%2==k%2||L0+1<=R0)){
            ans=O+2*k;
            break;
        }
    }
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        Solve();
    }
}