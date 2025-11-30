#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=3e5+7;
int n,q;
string s;
int sum0,us0;
int s1,s2,s3,sg,nsg;

void Solve(){
    cin>>n>>q;
    cin>>s;
    s=' '+s;
    sum0=s1=s2=s3=sg=us0=0;
    int l=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='X')sum0+=10;
        else if(s[i]=='V')sum0+=5;
        else if(s[i]=='I'){
            if(i<n&&s[i+1]!='I'&&s[i+1]!='?')sum0--;
            else sum0++;
        }else{
            us0++;
            if(!l||s[i-1]!='?'){
                l=i;
            }
            if(i==n||s[i+1]!='?'){
            	//printf("%d %d\n",l,i);//
            	int f3=(l>1&&s[l-1]=='I'),f1=(i<n&&s[i+1]!='I');
                s3+=f3;
                s1+=f1;
                s2+=(i-l+1-f1-f3)/2;
                if(i==l&&f1&&f3){
                	s1--;s3--;
                	sg++;
                }
            }
        }
    }
    nsg=sg;
    //printf("%d %d %d %d:%d\n",s1,s2,s3,sg,sum0);//
    while(q--){
        int cx,cv,ci;
        cin>>cx>>cv>>ci;
        sg=nsg;
        if(cx+cv+ci>us0)cx-=min(cx,cx+cv+ci-us0);
        if(cv+ci>us0)cv-=min(cv,cv+ci-us0);
        if(ci>us0)ci=us0;
        int ans=sum0+cx*10+cv*5;
        cv=cx+cv;
        //cout<<ans<<"\n";//
        ans-=min(ci,s1);
        ci-=min(ci,s1);
        //cout<<ans<<"\n";//
        ans-=2*min(cv,s3);
        cv-=min(cv,s3);
        //cout<<ans<<"\n";//
        int cg=0;
        if(cv>ci){
        	cg=min(cv-ci,sg);
        	ans-=2*cg;
        	cv-=cg;
        	sg-=cg;
        }else if(cv<ci){
        	cg=min(ci-cv,sg);
        	ans-=cg;
        	ci-=cg;
        	sg-=cg;
        }
        //cout<<ans<<"\n";//
        cg=min(cv,sg/2);
        ans-=3*cg;
        cv-=cg;ci-=cg;sg%=2;
        //cout<<ans<<"\n";//
        cg=min(cv,sg);
        ans-=2*cg;
        cv-=cg;
        //cout<<ans<<"\n";//
        ans-=min(min(cv,ci),s2);
        cg=min(min(cv,ci),s2);
        cv-=cg;ci-=cg;
        ans+=ci;
        
        cout<<ans<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        Solve();
    }
}
