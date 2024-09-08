#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod = 1e9 + 7;
int mark[10000005];
ll a[10000005];
void solve() {
	string a;
	ll sum = 0;
	while (cin >> a){
		if (a.length() >= 10 && a.length() <= 18){
			int n = a.length();
			string a_ = "";
			for (int i = 0; i < n; i++)
			{
				while (isdigit(a[i])){
					a_ += a[i];
					i++;
				}
				if (a_.length() >= 10 && a_.length() <= 18){
					sum += stoll(a_);
				}
				a_.clear();
				if (!isdigit(a[i])){
					continue;
				}
			}
		}
	}
	cout << sum;
	cout << "\n";
}

int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	int t = 1;
//	cin >> t;
//	cin.ignore();
	while (t--) {
		solve();
	}
}
