#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N=1e5+7,M=8e6+7,inf=0x3f3f3f3f3f3f3f3f;
int n,m,Q,U,V,t;
int q1[N],q2[M],q3[M],head1,head2,head3,top1,top2,top3;

void che(int x){
    x+=(t-1)*Q;
    int u=U*x/V,v=x-u;
    if(u>v)swap(u,v);
    q2[++top2]=u-t*Q,q3[++top3]=v-t*Q;
    //printf("%d:%d %d\n",x,u,v);//
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    head1=head2=head3=1;
    cin>>n>>m>>Q>>U>>V>>T;
    for(int i=1;i<=n;i++)cin>>q1[i];
    sort(q1+1,q1+n+1,[](int x,int y){return x>y;});
    //for(int i=1;i<=n;i++)cout<<q1[i]<<" \n"[i==n];//
    top1=n;
    for(t=1;t<=m;t++){
        int nx=-inf,ch=0;
        if(head1<=top1&&nx<q1[head1]){
            nx=q1[head1],ch=1;
        }
        if(head2<=top2&&nx<q2[head2]){
            nx=q2[head2],ch=2;
        }
        if(head3<=top3&&nx<q3[head3]){
            nx=q3[head3],ch=3;
        }
        if(ch==1)++head1;
        else if(ch==2)++head2;
        else ++head3;
        che(nx);
        //for(int i=head1;i<=top1;i++)cout<<q1[i]+t*Q<<" \n"[i==top1];//
        //for(int i=head2;i<=top2;i++)cout<<q2[i]+t*Q<<" \n"[i==top2];//
        //for(int i=head3;i<=top3;i++)cout<<q3[i]+t*Q<<" \n"[i==top3];//
        if(t%T==0)cout<<nx+(t-1)*Q<<" ";
    }
    cout<<"\n";
    // printf("%d %d:%d %d:%d %d\n",head1,top1,head2,top2,head3,top3);//
    // for(int i=head1;i<=top1;i++)cout<<q1[i]+(t-1)*Q<<" \n"[i==top1];//
    // for(int i=head2;i<=top2;i++)cout<<q2[i]+(t-1)*Q<<" \n"[i==top2];//
    // for(int i=head3;i<=top3;i++)cout<<q3[i]+(t-1)*Q<<" \n"[i==top3];//
    for(int i=1,nx=-1,ch=0;i<=n+m;i++){
        nx=-inf;ch=0;
        // printf("%d %d:%d %d\n",nx,q1[head1],head1,top1);//
        if(head1<=top1&&nx<q1[head1]){
            nx=q1[head1];ch=1;
            //cout<<nx<<":"<<ch<<"a\n";
        }
        // printf("%d %d:%d %d\n",nx,q2[head2],head2,top2);//
        if(head2<=top2&&nx<q2[head2]){
            nx=q2[head2];ch=2;
            //cout<<nx<<":"<<ch<<"b\n";
        }
        //printf("%d %d:%d %d\n",nx,q3[head3],head3,top3);//
        if(head3<=top3&&nx<q3[head3]){
            nx=q3[head3];ch=3;
            //cout<<nx<<":"<<ch<<"ch\n";
        }
        if(ch==1)++head1;
        else if(ch==2)++head2;
        else ++head3;
        //cout<<nx+(t-1)*Q<<":"<<ch<<"\n";
        // printf("%d %d:%d %d:%d %d\n",head1,top1,head2,top2,head3,top3);//
        // for(int i=head1;i<=top1;i++)cout<<q1[i]+(t-1)*Q<<" \n"[i==top1];//
        // for(int i=head2;i<=top2;i++)cout<<q2[i]+(t-1)*Q<<" \n"[i==top2];//
        // for(int i=head3;i<=top3;i++)cout<<q3[i]+(t-1)*Q<<" \n"[i==top3];//
        if(i%T==0)cout<<nx+(t-1)*Q<<" ";
    }
    cout<<"\n";
}


/*
X=x+t*Q;

*/