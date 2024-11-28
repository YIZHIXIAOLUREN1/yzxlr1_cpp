#include<bits/stdc++.h>
//#include<bits/extc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define ll long long
const int N=1e5+7,mod=998244353;
__gnu_pbds::tree<int,__gnu_pbds::null_type,less_equal<int>,
__gnu_pbds::rb_tree_tag,
__gnu_pbds::tree_order_statistics_node_update> rbtr;
int n,m,x,opt,last,ans;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n>>m;
    for(int i=1;i<=n;i++){
        cin>>x;rbtr.insert(x);
    }
    for(int i=1;i<=m;i++){
        cin>>opt>>x;
        x=x^last;
        if(opt==1)rbtr.insert(x);
        else if(opt==2)rbtr.erase(rbtr.upper_bound(x));
        else if(opt==3)last=rbtr.order_of_key(x)+1;
        else if(opt==4)last=*rbtr.find_by_order(x-1);
        else if(opt==5)last=*--rbtr.upper_bound(x);
        else last=*rbtr.lower_bound(x);
        if(opt>=3)ans^=last;
    }
    cout<<ans;
    return 0;
}
