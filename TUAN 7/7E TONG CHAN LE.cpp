#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {
    faster();
    int k; cin >> k;
    int a[k];
    for(int i =0; i<k; i++) cin >> a[i];
    set <int > b[k];
    int x;
    map<int,int> ck;
    for(int i =0; i<k; i++){
        for(int j =0; j<a[i]; j++){
            cin >> x;
            b[i].insert(x);
        }
    }
    for(int i =0; i<k; i++){
        for(auto j:b[i]){
            ck[j]++;
        }
    }
    int check = 0;
    int res = 100000000;
    for(pair <int, int> v : ck){
        if( v.second == k){
            res = min(res, v.first);
            check = 1;
        }
    }
    if( check == 0){
        cout << "NO";
    }
    else cout << res ;


    
}