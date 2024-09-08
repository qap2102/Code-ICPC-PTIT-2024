#include <bits/stdc++.h>
using namespace std;
#define faster                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define ll long long
const int MOD=1e9+7;
void solve(int n, int s,  vector<int> &A){
    vector<ll> even(n+1,0);
    vector<ll> odd(n+1,0);
    even[0]=1;
    odd[0]=0;
    for(int i=0;i<n;i++){
        if(A[i]%2==0){
            even[i + 1] = (even[i] * 2) % MOD;
            odd[i + 1] = (odd[i] * 2) % MOD;
        }
        else{
            even[i + 1] = (even[i] + odd[i]) % MOD;
            odd[i + 1] = (even[i] + odd[i]) % MOD;
        }
    }
    if(s==0){
        cout<<even[n]<<endl;
    }
    else if(s==1){
        cout<<odd[n]<<endl;
    }
}
int main(){
    faster;
    int n,s;
    cin>>n>>s;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    solve(n,s,a);

}