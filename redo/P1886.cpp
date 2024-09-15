#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define gc() getchar()
#define pc(x) putchar(x)
#define endl pc(10)
inline int read(){int w=1,s=0;char ch=' ';
    while(ch!='-'&&(ch<'0'||ch>'9'))ch=gc();if(ch=='-')w=-1,ch=gc();
    while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=gc();}return s*w;}
inline void pr(int x){if(x<0){pc('-'),x=-x;}if(x>9){pr(x/10);}pc(x%10+'0');}
const int N=1e6+7;
int n,k,a[N],pma[N],pmi[N],la=1,ra,li=1,ri;
int ma[N],mi[N];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    n=read();k=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        while(la<=ra&&pma[la]<=i-k)la++;
        while(la<=ra&&a[pma[ra]]<=a[i])ra--;
        pma[++ra]=i;
        if(i>=k)ma[i-k+1]=a[pma[la]];
		//printf("%d:%d %d %d\n",i,a[i],la,ra);//
        while(li<=ri&&pmi[li]<=i-k)li++;
        while(li<=ri&&a[pmi[ri]]>=a[i])ri--;
        pmi[++ri]=i;
        if(i>=k)mi[i-k+1]=a[pmi[li]];
        //printf("%d:%d %d %d\n",i,a[i],li,ri);//
    }
    for(int i=1;i<=n-k+1;i++)pr(mi[i]),pc(' ');
    endl;
    for(int i=1;i<=n-k+1;i++)pr(ma[i]),pc(' ');
    return 0;
}
