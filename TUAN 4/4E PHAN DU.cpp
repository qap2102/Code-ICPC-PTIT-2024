#include <bits/stdc++.h>
using namespace std;
#define faster                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define ll long long
int n,k;
int calc(int y){
    int cnt=n/y;
    // cout << cnt << endl;
    int res=0;
    int du=(n-cnt*y)%y;
    res+=cnt*(y-k);
    if(du>=k){
        if(k!=0)
            res+=du-k+1;
        else res +=du-k;
    }
    return res;
}
signed main(){
    faster;
    cin>>n>>k;
    int dem1=0;
    for(int i=0;i<n-k;i++){
        int dem2=n-i;
        dem1+=calc(dem2);
    }
    cout<<dem1<<endl;
}