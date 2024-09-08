#include <bits/stdc++.h>
 
using namespace std;
 
#define sz size()
#define ll long long
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define endl '\n'
 
ll q[200005], dp[200005], h[200005];
 
double getVal(ll a, ll b)
{
	double x =  1.0 * dp[a] + 1.0 * h[a] * h[a];
	double y = 1.0 * dp[b] + 1.0 * h[b] * h[b];
	return (x - y) / (1.0 * (h[a] - h[b]));
}
 
int main()
{
	faster();
	ll n, c;
	cin >> n >> c;
	int l = 1, r = 1;
	for (int i = 1; i <= n; ++i)
		cin >> h[i];
	q[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		while (l < r and getVal(q[l], q[l + 1]) <= h[i] << 1LL)
			++l;
		dp[i] = dp[q[l]] + (h[i] - h[q[l]]) * (h[i] - h[q[l]]) + c;
		while (l < r and getVal(q[r - 1], q[r]) >= getVal(q[r], i))
			--r;
		q[++r] = i;
	}
	cout << dp[n];
	return 0;
}
