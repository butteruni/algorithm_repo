#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
const ll mod = 998244353;
ll c[N];
ll inv[N];
ll f[N];
ll qpow(ll a,ll b)
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
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll n,m;
    cin >> n >> m;
    inv[1] = 1;
    for(ll i=2;i<=n;++i) 
    {
        inv[i]=(long long)(mod-mod/i)*inv[mod%i]%mod;
    }
    for(int i = 1;i <= m;++i)
    {
        cin >> c[i];
        
    }
}