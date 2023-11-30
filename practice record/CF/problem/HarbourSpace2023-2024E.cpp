#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll qpow(ll a,ll b)
{
    ll res = 1;
    a %= mod;
    while(b)
    {
        if(b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        vector<int>a(n);
        for(int i = 0;i < n;++i)
        {
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        ll ans = n * n;
        for(int id = 0;id < 30;++id)
        {
            for(int l = 0,r = 0;l < n;l = r)
            {
                vector<ll>cnt(2,0);
                while(r < n && a[l] / 2 == a[r] / 2)
                {
                    cnt[a[r] & 1]++;
                    r++;
                }
                ans = (ans + cnt[1] * (cnt[1] + cnt[0])) % mod;
             }
             for(auto &x : a)
             {
                x /= 2;
             }
        }
        ans = (ans * qpow(n * n,mod - 2) % mod + mod) % mod;
        cout << ans << '\n';
    }
}