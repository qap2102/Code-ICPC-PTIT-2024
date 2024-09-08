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

signed main()
{
    faster();
    // if(fopen(task".INP", "r"))
    // {
    //     freopen(task".OUT", "r", stdin);
    //     freopen(task".OUT", "w", stdout);
    // }
    int n,res=0,cnt=0;
    cin >> n;
    vi a(n),b(n),c,d;
    FOR(i,0,n) cin >> a[i];
    FOR(i,0,n) cin >> b[i];
    FOR(i,0,n) 
    {
        if(a[i]-b[i]>=0) 
        {
            c.pb(a[i]-b[i]);
        }
        else d.pb(a[i]-b[i]);
    }
    res+=c.sz;
    int sum=accumulate(c.begin(),c.end(),0LL);
    sort(d.begin(),d.end(),greater<int>());
    // debug(d);
    for(auto x:d)
    {
        int tmp=sum+x;
        if(tmp<0) break;
        sum+=x;
        res++;
    }
    cout << res<<endl;

    return 0;
}