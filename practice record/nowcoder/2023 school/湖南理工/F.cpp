#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 5e5 + 10;
const ll mod = 998244353;
ll a[N];
map<ll,ll>cnt;
bool st[N];
ll gcd(ll a,ll b)
{
    if(a == 0 || b == 0)
    {
        return max(a,b);
    }
    return gcd(b,a % b);
}

void solve()
{
    ll n,q;
    cin >> n >> q;
    
    ll sum = 0;
    for(int i = 1;i <= n;++i)
    {
        cin >> a[i];
        st[i] = 1;
    }
    int sz = n;
    vector<int>op;
    for(int i = 1;i <= q;++i)
    {
        int x;
        cin >> x;
        op.push_back(x);
        st[x] = 0;
    }
    ll gcd_total = 0;
    for(int i = 1;i <= n;++i)
    {
        if(st[i])
        {
            gcd_total = gcd(gcd_total,a[i]);
        }
    }
    for(int j = op.size() - 1;j >= 0;--j)
    {
        gcd_total = gcd(gcd_total,a[op[j]]);
        sum = (sum + gcd_total) % mod;
    }
    cout << sum << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
}