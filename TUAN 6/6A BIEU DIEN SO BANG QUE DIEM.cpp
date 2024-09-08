#include <bits/stdc++.h>
using namespace std;
#define faster                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define ll long long
const int N=5001;
int f[N];
int g[N];
void solve(){
    f[0]=0;
    f[1]=1;
    g[0]=0;
    g[1]=1;
    for(int i=2;i<N;i++){
        g[i]=i;
        for(int j=1;j<i;j++){
            if(i%j==0){
                g[i]=min(g[i],g[j]+2+g[i/j]);
            }
        }
    }
    for(int i=2;i<N;i++){
        f[i]=g[i];
        for (int j = 1; j < i; j++) {
			f[i] = min(f[i], f[j] + 2 + f[i - j]);
		}
    }
}
int main(){
    faster;
    solve();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<f[n]<<endl;
    }
}