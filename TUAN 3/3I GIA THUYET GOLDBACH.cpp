#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector<int> snt;
int prime[10000001]; // N = 10^7

void sieve() {
    fill(prime, prime + 10000001, 1);
    prime[0] = prime[1] = 0;
    for(int i = 2; i * i <= 10000000; i++) {
        if(prime[i]) {
            for(int j = i * i; j <= 10000000; j += i) {
                prime[j] = 0;
            }
        }
    }
    
    for(int i = 2; i <= 10000000; i++) {
        if(prime[i]) {
            snt.push_back(i);
        }
    }
}

int main() {
    faster();
    int n;
    cin >> n;
    
    sieve();
    
    int count = 0;
    for(int i = 0; i < snt.size() && snt[i] <= n / 2; i++) {
        int a = snt[i];
        int b = n - a;
        if(b > 1 && prime[b]) {
            count++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}
