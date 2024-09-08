#include <bits/stdc++.h>
using namespace std;
#define int long long
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define MAXN 200005

int parent[MAXN], sz[MAXN];
bool add[MAXN];
stack<bool> TrueOrFalse;

void ktao(int n) 
{
    for(int i = 1; i <= n; ++i) 
    {
        parent[i] = i;// dai dien cho tap hop
        sz[i] = 1;
        add[i] = false;
    }
}
int Find(int u)// ham tim dai dien cho tap hop
{
    if(parent[u]==u) return u;
    return parent[u]=Find(parent[u]);
}
int Union(int u,int v)// gop 2 tap hop voi nhau
{
    int x=Find(u);
    int y=Find(v);
    if(x==y) return 0;
    if(sz[x]>sz[y]) 
    {
        parent[y]=x;
        sz[x]+=sz[y];
    }
    else
    {
        parent[x]=y;
        sz[y]+=sz[x];
    }
    return 1;
}


signed main() 
{
    faster();
    int n, m;
    cin >> n >> m;
    ktao(n);
    vector<pair<int, int>> vp(m);
    for(int i = 0; i < m; ++i) 
    {
        int u, v;
        cin >> u >> v;
        vp[i] = {u, v};
    }

    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    reverse(v.begin(), v.end());
    int cnt = 0;
    vector<vector<int>> adj(n + 1);
    for(auto x : vp) 
    {
        int u = x.first, v = x.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 0; i < n; ++i) 
    {
        int x = v[i];
        add[x] = true;
        cnt++;
        for(int _x : adj[x]) 
        {
            if(add[_x])
                if (Union(x, _x))
                    cnt--;
        }
        TrueOrFalse.push(cnt == 1);
    }

    while(!TrueOrFalse.empty()) 
    {
        bool ok = TrueOrFalse.top();
        TrueOrFalse.pop();
        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}
// bai toan DSU Disjoint set union

