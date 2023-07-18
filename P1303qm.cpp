#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#define LL long long
using namespace std;
int m;
const long long mod=40961,G=3,Ginv=(mod+1)/3;
int r[240100];
LL ksm(LL a,LL b,LL mod) {
	LL ans=1;
	for(; b; b>>=1,a=a*a%mod)
		if(b&1)ans=ans*a%mod;
	return ans;
}
void NTT(int limit,LL *l,int opt) {
	for(int i=0; i<limit; ++i)
		if(i<r[i])swap(l[i],l[r[i]]);
	for(int mid=1; mid<limit; mid<<=1) {
		LL wn,len=mid<<1;;
		if(opt==1)wn=ksm(G,(mod-1)/len,mod);
		else wn=ksm(Ginv,(mod-1)/len,mod);
		for(int j=0; j<limit; j+=len) {
			LL w=1;
			for(int k=j; k<mid+j; ++k,(w*=wn)%=mod) {
				int x=l[k],y=w*l[k+mid]%mod;
				l[k]=(x+y)%mod;
				l[k+mid]=(x-y+mod)%mod;
			}
		}
	}
	if(opt==-1) {
		LL inv=ksm(limit,mod-2,mod);
		for(int i=0; i<=limit; i++) l[i]=l[i]*inv%mod;
	}
}
struct gj {
	int len,zheng;
	LL v[5000];
	gj() {
		len=0;
		memset(v,0,sizeof(v));
		zheng=1;
	}
	gj(int x) {
		if(x>=0)zheng=1;
		else x=-x,zheng=0;
		len=0;
		memset(v,0,sizeof(v));
		while(x) {
			v[++len]=x%10;
			x/=10;
		}
	}
	friend bool operator <(const gj &a,const gj &b) {
		if(a.len<b.len)return 1;
		if(a.len>b.len)return 0;
		for(int i=a.len; i>=1; --i) {
			if(a.v[i]<b.v[i])return 1;
			if(a.v[i]>b.v[i])return 0;
		}
		return 0;
	}
} n,a,b;
ostream& operator << (ostream &out,const gj &a);
istream& operator >> (istream &in,gj &a);
gj operator -(gj a,gj b);
gj operator +(gj a,gj b);
gj operator *(gj a,gj b);

gj operator +(gj a,gj b) {
	if(!a.zheng&&!b.zheng) {
		a.zheng=b.zheng=1;
		gj c=a+b;
		c.zheng=0;
		return c;
	}
	if(!a.zheng&&b.zheng) {
		a.zheng=b.zheng=1;
		return b-a;
	}
	if(a.zheng&&!b.zheng) {
		a.zheng=b.zheng=1;
		return a-b;
	}
	int len=a.len+b.len;
	gj c;
	c.len=len;
	for(int i=1; i<=len; ++i)c.v[i]=a.v[i]+b.v[i];
	for(int i=1; i<=len; ++i) {
		if(c.v[i]>=10) {
			++c.v[i+1];
			c.v[i]-=10;
		}
	}
	while(c.len&&!c.v[c.len])c.len--;
	return c;
}
gj operator -(gj a,gj b) {
	if(!a.zheng&&!b.zheng) {
		a.zheng=b.zheng=1;
		return b-a;
	}
	if(!a.zheng&&b.zheng) {
		a.zheng=1;
		gj c=a+b;
		c.zheng=0;
		return c;
	}
	if(a.zheng&&!b.zheng) {
		b.zheng=1;
		gj c=a+b;
		return c;
	}
	if(a.zheng&&b.zheng&&a<b) {
		gj c=b-a;
		c.zheng=0;
		return c;
	}
	int len=max(a.len,b.len);
	gj c;
	for(int i=1; i<=len; ++i)c.v[i]=a.v[i]-b.v[i];
	c.len=len;
	for(int i=1; i<=c.len; ++i) {
		if(c.v[i]<0) {
			c.v[i+1]--;
			c.v[i]+=10;
		}
	}
	while(c.len&&!c.v[c.len])c.len--;
	return c;
}
gj operator *(gj a,gj b) {
	int limit=1,tot,l=0;
	gj c;
	a.len--;
	b.len--;
	for(int i=0; i<=a.len; ++i)a.v[i]=a.v[i+1];
	a.v[a.len+1]=0;
	for(int i=0; i<=b.len; ++i)b.v[i]=b.v[i+1];
	b.v[b.len+1]=0;
	while(limit<=a.len+b.len)limit<<=1,l++;
	for(int i=0; i<=limit; i++) r[i]=(r[i>>1]>>1) | ((i&1)<<(l-1) );
	NTT(limit,a.v,1);
	NTT(limit,b.v,1);
	for(int i=0; i<=limit; i++) a.v[i]=a.v[i]*b.v[i]%mod;
	NTT(limit,a.v,-1);
	for(int i=0; i<=limit; i++) c.v[i]=a.v[i];
	for(int i=0; i<=limit; i++) {
		if(c.v[i]>=10) {
			c.v[i+1]+=c.v[i]/10,c.v[i]%=10;
			if(i+1>limit) limit++;
		}
	}
	for(int i=limit; i>=0; i--)if(c.v[i]==0) limit--;
		else break;
	c.len=limit+1;
	for(int i=c.len; i>=1; --i)c.v[i]=c.v[i-1];
	c.v[0]=0;
	for(int i=1; i<=c.len; ++i)swap(c.v[i],c.v[c.len-i+1]);
	if(a.zheng!=b.zheng)c.zheng=0;
	else c.zheng=1;
	return c;
}
gj operator /(gj a,long long b) {
	gj c;
	int d=0;
	for(int i=a.len; i>=1; --i)
		c.v[++c.len]=((d*10+a.v[i])/b),d=(d*10+a.v[i])%b;
	for(int i=1; i<=c.len/2; ++i)swap(c.v[i],c.v[c.len-i+1]);
	if(!a.len||!b||(a.zheng&&b>0)||(!a.zheng&&b<0))c.zheng=1;
	else c.zheng=0;
	while(c.v[c.len]==0&&c.len>1)--c.len;
	return c;
}
istream& operator >> (istream &in,gj &a) {
	char lin[5010];
	int len;
	scanf("%s",lin+1);
	len=a.len=strlen(lin+1);
	if(lin[1]=='-')a.zheng=0,a.len--;
	else a.zheng=1;
	for(int i=1; i<=a.len; ++i)a.v[i]=lin[len-i+1]-'0';
	return in;
}
ostream& operator << (ostream &out,const gj &a) {
	if(!a.len) {
		cout<<"0";
		return out;
	}
	if(!a.zheng)cout<<"-";
	for(int i=a.len; i>=1; i--)printf("%d",a.v[i]);
	return out;
}
int main() {
	cin>>a>>b;
	cout<<a*b;
	return 0;
}
