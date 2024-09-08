#include <bits/stdc++.h>
using namespace std;
#define faster                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define ll long long
int solve(int a){
    vector<int> f={0,1,1};
    if(a==2) return 3;
    int b=f.size();
    while(1){
        int tmp=f[b-1]+f[b-2];
        tmp%=a;
        if(tmp==0&&f[b-1]==1){
            return b;
        }
        f.push_back(tmp);
        b++;
    }
    delete &f;
}
int main(){
    faster;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<solve(n)<<endl;
    }
}