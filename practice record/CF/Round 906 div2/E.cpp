#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N = 2e5 + 10;
ll sz[N];
ll tr[N];
ll lowbit(ll x)
{
    return x & (-x);
}
void add(int x, int maxn, ll v) 
{
    while (x <= maxn) 
    {
        tr[x] += v;
        x += lowbit(x);
    }
}

ll sum(int x) 
{
    ll s = 0;
    while (x >= 1) 
    {
        s += tr[x];
        x ^= lowbit(x);
    }
    return s;
}
ll query(ll l, ll r)
{
    return sum(r) - sum(l - 1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m,k;
        cin >> n >> m >> k;
        vector<PII>a(n + 1);
        for(int i = 1;i <= n;++i)
        {
            cin >> a[i].first >> a[i].second;
            sz[i] = a[i].second + 1 - a[i].first;
        }
        int l = n,r = 1;
        ll ans = 0;
        
    }
}