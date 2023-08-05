#include<bits/stdc++.h>
using namespace std;
#define N 1005
#define inf 0x3f3f3f3f
int A,B,n;
int a[N][N],ma[N][N],mi[N][N],na[N][N],ni[N][N];
int qa[N],la,ra,qi[N],li,ri;
int ans=inf;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> A >> B >> n;
    for(int i=1;i<=A;i++){
        li=la=1,ra=ri=0;
        for(int j=1;j<=B;j++){
            cin >> a[i][j];
            while(la<=ra&&qa[la]<=j-n)la++;
            while(li<=ri&&qi[li]<=j-n)li++;
            while(la<=ra&&a[i][qa[ra]]<=a[i][j])ra--;
            while(li<=ri&&a[i][qi[ri]]>=a[i][j])ri--;
            qa[++ra]=j;qi[++ri]=j;
            if(j>=n){
            	ma[i][j-n+1]=a[i][qa[la]];
            	mi[i][j-n+1]=a[i][qi[li]];
            }
        }
    }

    for(int j=1;j<=B-n+1;j++){
        li=la=1,ra=ri=0;
        for(int i=1;i<=A;i++){
            while(la<=ra&&qa[la]<=i-n)la++;
            while(la<=ra&&ma[qa[ra]][j]<=ma[i][j])ra--;
            qa[++ra]=i;
            while(li<=ri&&qi[li]<=i-n)li++;
            while(li<=ri&&mi[qi[ri]][j]>=mi[i][j])ri--;
            qi[++ri]=i;
            //if(i>=n)printf("%d %d:%d %d\n",i-n+1,j,
            //ma[qa[la]][j],mi[qi[li]][j]);//
            if(i>=n)ans=min(ans,ma[qa[la]][j]-mi[qi[li]][j]);
        }
    }
    cout << ans;
}