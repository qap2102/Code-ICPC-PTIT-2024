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
/*
    Y tuong :
    Minh se build cac so thoa man tu 10^(len(n)-1) -> 10^(len(n))-1
    Roi kiem tra cac so da build duoc, so nao <= n thi thoa man
    Dem so luong so thoa man la ok
    Vi du : n=20
    => build tu 1 ->99 
    Xong kiem tra , dem cac so thoa man la ok ._.

    ==> Phai dung set, vi trong qua trinh build co the tao ra cac so trung nhau
*/
int n;
set<int> s;
void build(int cur,int d1,int d2,int len,int max_len)
{
    //build khi nao len>max_len thi stop
    if(len>max_len) return;
    if(cur) s.insert(cur); //neu cur khac 0 thi them vao set
    //build so tiep theo
    build(cur*10+d1,d1,d2,len+1,max_len);
    build(cur*10+d2,d1,d2,len+1,max_len);
    return;
}

int dp(int n)
{
    /*
        Bat dau build voi cac so d1,d2 duoc lay tu 0->9
        Sau moi vong for de build, ta se duoc 1 list cac so thoa man chi co 2 chu so d1 va d2
    */
    for(int d1=0;d1<=9;d1++)
    {
        for(int d2=0;d2<=9;d2++)
        {
            build(0,d1,d2,0,to_string(n).sz);
        }
    }
    int cnt=0;
    //Duyet cac so vua tao duoc, dem cac so thoa man
    for(auto x:s)
    {
        if(x<=n) cnt++;
    }
    return cnt;

}
signed main()
{
    faster();
    cin >> n;
    cout << dp(n);
    return 0;
}
