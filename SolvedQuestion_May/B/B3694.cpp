#include<bits/stdc++.h>
using namespace std;
#define N 100050
int n;
int a[N],lsh[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        for(int i=1;i<=n;i++){cin >> a[i];lsh[i]=a[i];}
        sort(lsh+1,lsh+n+1);
        int cnt=unique(lsh+1,lsh+n+1)-lsh-1;
        for(int i=1;i<=n;i++){
            int rank=lower_bound(lsh+1,lsh+cnt+1,a[i])-lsh;
            if(i!=n)cout << rank << " ";
            else cout << rank << "\n";
        }
    }
}