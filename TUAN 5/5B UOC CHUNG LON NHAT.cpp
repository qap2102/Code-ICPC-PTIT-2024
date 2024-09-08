#include <bits/stdc++.h>
using namespace std;
#define faster                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define ll long long
ll calc(ll n, ll m){
    ll g=1;
    for(ll i=1;i*i<=m;i++){
        if(m%i==0){
            if(i*n<=m) g=max(g,i);
            if((m/i)*n<=m) g=max(g,m/i);
        }
    }
    vector<int> A(n,g);
    A[n-1]=g*(m/g-(n-1));
    return __gcd(A[0],A[n-1]);
}
int main(){
    ll n,m;
    cin>>n>>m;
    cout<<calc(n,m)<<endl;
    return 0;
}