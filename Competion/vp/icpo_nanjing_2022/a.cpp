#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=2e3+7;
void sovle()
{
    int n,m,k;
    cin>>n>>m>>k;
    string p;
    cin>>p;
    // if(k==0)
    // {
    //     cout<<n*m<<endl;
    //     return;
    // }
    int h=0,w=0;
    int up=0,down=0,left=0,right=0;
    int u=0,d=0,l=0,r=0;
    int sx=n,sy=m;
    for(char& x:p)
    {
        if(x=='U')u++,d--,sx--;
        else if(x=='D')
        {
            d++,u--,sx++;
            if(sx>n)sx=n;
        }
        else if(x=='R')
        {
            r++,l--,sy++;
            if(sy>m)sy=m;
        }
        else if(x=='L')l++,r--,sy--;
        up=max(up,u);
        down=max(down,d);
        left=max(left,l);
        right=max(right,r);
    }
    // cout<<sx<<' '<<sy<<endl;
    h=max(0,n-up-down);
    w=max(0,m-left-right);
    // cout<<h<<' '<<w<<endl;
    // if(h*w==k)
    // {
    //     cout<<n*m-h*w<<endl;
    //     return;
    // }
    if(h==0 || w==0)
    {
        if(k==0)cout<<n*m<<endl;
        else cout<<0<<endl;
        return;
    }
    vector<vector<int>> s(3*n+10,vector<int>(3*m+10,0));
    s[n+1][m+1]=1;
    PII st={n+1,m+1};
    reverse(p.begin(),p.end());
    for(char& x:p)
    {
        if(x=='U')
        {
            st.first--;
            sx++;
        }
        else if(x=='D')
        {
            st.first++;
            sx--;
        }
        else if(x=='R')
        {
            st.second++;
            sy--;
        }
        else if(x=='L')
        {
            st.second--;
            sy++;
        }
        if(st.first<1 || st.first>2*n || st.second<1 || st.second>2*m)
        {
            continue;
        }   
        s[st.first][st.second]=1;
    }
    // cout<<sx<<' '<<sy<<endl;
    // for(int i=1;i<=3*n;i++)
    // {
    //     for(int j=1;j<=3*m;j++)
    //     {
    //         cout<<s[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    for(int i=1;i<=3*n;i++)
    {
        for(int j=1;j<=3*m;j++)
        {
            s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        }
    }
    // for(int i=1;i<=2*n;i++)
    // {
    //     for(int j=1;j<=2*m;j++)
    //     {
    //         cout<<s[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    int ans=0;
    for(int i=1;i<=3*n;i++)
    {
        for(int j=1;j<=3*m;j++)
        {
            int x1=max(1,i-h+1);
            int y1=max(1,j-w+1);
            int x2=i;
            int y2=j;
            // cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
            // cout<<s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1]<<endl;
            if(s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1] == h*w-k)
            {
                int dx=st.first-i,dy=st.second-j;
                if(sx+dx>n || sx+dx<1 || sy+dy>m || sy+dy<1)continue;
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}
int main()
{
    int t=1;
    cin>>t;
    while(t--)
    {
        sovle();
    }
    return 0;
}