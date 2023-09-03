#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
int n;
int a[N],b[N];
ll ans=0;
int top=0,it;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        cin >> b[i];
    }

    for(int i=1;i<=n;i++){
        if(b[i]<=a[i])ans+=a[i]-a[i-1];
        else{
            top=b[i];
            for(int j=i+1;a[j]<=top;j++){
                if(b[j]>top)top=b[j];
                it=j;
            }
            
        }
    }
    
}