#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int T,n;
int q[N],l=1,r=0;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> T;
    while(T--){
        l=1,r=0;
        cin >> n;
        for(int i=1;i<=n;i++)cin >> q[++r];
        bool ans=1;
        for(int i=n;i>=1;i--){
            if(q[l]==i)l++;
            else if(q[r]==i)r--;
            else{ans=0;break;}
        }
        if(ans)puts("YES");
        else puts("NO");
    }
}
