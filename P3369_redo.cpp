#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
const int N=1e5+7;
__gnu_pbds::tree<int,__gnu_pbds::null_type,less_equal<int>,
__gnu_pbds::rb_tree_tag,
__gnu_pbds::tree_order_statistics_node_update
> rbtr;
int n,opt,x;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>opt>>x;
        if(opt==1)rbtr.insert(x);
        else if(opt==2)rbtr.erase(rbtr.upper_bound(x));
        else if(opt==3)cout<<rbtr.order_of_key(x)+1<<"\n";
        else if(opt==4)cout<<*rbtr.find_by_order(x-1)<<"\n";
        else if(opt==5)cout<<*--rbtr.upper_bound(x)<<"\n";
        else cout<<*rbtr.lower_bound(x)<<"\n";
    }
}