#include <bits/stdc++.h>
using namespace std;
#define faster                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define ll long long
const int N=2e5+1;
int f[N];
void init() {
	f[0] = 3;
	f[1] = 3 + (1 + 1 + 2) + 3;
	for (int i = 2; i < N; i++) {
		f[i] = f[i - 1] + (1 + i + 2) + f[i - 1];
		if (f[i] > 1e9) break;
	}

}
signed main() {
    faster;
	init();
	int n;
	cin >> n;

	int p = 0;
	for (int i = 0; i < N; i++) {
		if (f[i] >= n) {
			p = i;
			break;
		}
	}
	string s = "acc";
	while (p > 0) {
		if (n <= f[p - 1]) {
			p = p - 1;
		}
		else if (n <= f[p - 1] + (1 + p + 2)) {
			if (n == f[p - 1] + 1) {
				cout << 'a';
				return 0;
			}
			else {
				cout << 'c';
				return 0;
			}
		}
		else {
			n -= f[p - 1] + (1 + p + 2);
			p = p - 1;
		}
	}

	cout << s[n - 1] << endl;

	return 0;
}