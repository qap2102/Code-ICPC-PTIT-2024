#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define int long long
#define sz size()
#define FOR(i,a,b) for(long long i = a; i < b; i++)
#define FORD(i,a,b) for(long long i = a; i > b; i--)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define vll vector<long long>
#define endl '\n'
#define MOD 1000000007
// #define task "Fernandez"

#ifdef FERNANDEZ
   #include "debug.h"
#else
   #define debug(...) 04
#endif

vi seg;
void update(int id, int l, int r, int i, int v)
{
    if (i < l || i > r) return;
    if (l == r)
    {
        seg[id] = v;
        return;
    }

    int mid = (l + r) / 2;
    update(id * 2, l, mid, i, v);
    update(id * 2 + 1, mid + 1, r, i, v);

    seg[id] = min(seg[id * 2], seg[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u) return 1e18;
    if (u <= l && r <= v)
        return seg[id];

    int mid = (l + r) / 2;
    return min(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

void solve()
{
    int n;
    cin >> n;
    seg.assign(4 * n + 5, 0);

    vi a(n + 1);
    vector<queue<int>> ind(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ind[a[i]].push(i);
        update(1, 1, n, i, a[i]);
    }
    vi b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }

    for (int i = 1; i <= n; i++)
    {
        // nếu không tồn tại phần tử b[i] trong a
        if (ind[b[i]].empty())
        {
            cout << "NO\n"; 
            return;
        }
        // tìm index j bé nhất mà a[j] = b[i]
        int j = ind[b[i]].front();
        ind[b[i]].pop();

        int tmp = get(1, 1, n, 1, j);
        // nếu tồn tại a[k] sao cho k < j && a[k] < a[j]
        if (tmp != b[i])
        {
            cout << "NO\n"; 
            return;
        }

        update(1, 1, n, j, 1e18);
    }

    cout << "YES\n";
    return;
}

signed main()
{
    faster();
    int t ;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}