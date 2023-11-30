#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll qpow(ll a, ll b)
{
    ll res = 1;
    while(b)
    {
        if(b & 1)
        {
            res = res * a % mod;
        }
        a = a * a % mod;
        b /= 2;
    }
    return res;
}
const int N = 2e5 + 10;
ll a[N],mx[N],id[N],p[N];
bool cmp(int x,int y)
{
    return mx[x] > mx[y];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    p[0] = 1;
    p[1] = 2;
    for(int i = 2;i <= n;++i)
    {
        p[i] = p[i - 1] * 2 % mod;
    }
    for(int i = 1;i <= n;++i)
    {
        cin >> a[i];
        id[i] = i;
        mx[i] = a[i];
    }
    for(int i = 1;i <= n;++i)
    {
        for(int sz = 2;sz * i <= n;++sz)
        {
            mx[i] = max(mx[i],a[i * sz]);
        }
    }
    sort(id + 1,id + 1 + n,cmp);
    // for(int i = 1;i <= n;++i)
    // {
    //     cout << id[i] << " " << mx[id[i]] << " || ";
    // }
    ll ans = 0;
    for(int i = 1;i <= n;++i)
    {
        ll res = n - i;
        ans = ((ans + mx[id[i]] * p[res]) % mod + mod) % mod;
        // cout << ans << " ";
    }
    cout << ans << '\n';


}