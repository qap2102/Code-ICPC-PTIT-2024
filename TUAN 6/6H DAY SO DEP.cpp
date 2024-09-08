#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int n, vector<int>& a) {
    for (int i = 0; i < n - 1; i++) {
        if (a[i] > 1 && a[i+1] > 1 && __gcd(a[i], a[i+1]) != 1) {
            return -1;
        }
    }
    
    int x = 2;
    
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == 0 && a[i+1] == 0) {
            x = max(x, 3);
        } else if (a[i] == 0) {
            while (__gcd(x, a[i+1]) != 1) {
                x++;
            }
        } else if (a[i+1] == 0) {
            while (__gcd(a[i], x) != 1) {
                x++;
            }
        }
    }
    
    return x;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    cout << solve(n, a) << endl;
    
    return 0;
}