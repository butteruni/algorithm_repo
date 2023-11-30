#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int N = 1e5 + 10;
ll fac[N],invfac[N],inv[N];
ll p2[N];
ll qpow(ll a,ll b)
{
    ll res = 1;
    while(b)
    {
        if(b & 1)
        {
            res = res * a % mod;
        }
        a = a* a % mod;
        b >>= 1;
    }
    return res;
}
void init()
{
    fac[0] = 1;
	p2[0] = 1;
    for (int i = 1; i < N; ++i) 
	{
        fac[i] = (fac[i - 1] * i) % mod;
		p2[i] = p2[i - 1] * 2ll % mod;
	}
    invfac[N - 1] = qpow(fac[N - 1],mod - 2);
    for (int i = N - 2; i >= 0; --i) 
        invfac[i] = (invfac[i + 1] * (i + 1)) % mod;
}
ll C(int n, int m)
{
    if (n < m || m < 0) return 0;
    return (fac[n] * invfac[m] % mod)*invfac[n - m] % mod;
}
ll A(int n,int m)
{
    if(n < m || m < 0)
        return 0;
    return fac[n] * invfac[n - m] % mod;
}

int n,k;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    init();
    while(t--)
    {
        cin >> n >> k;
		ll ans = 0;
        for(int i = 1;i <= min(k,n - k + 1);++i)
		{
			ans = (ans + (p2[i] * C(k - 1,i - 1)) % mod * C(n - k + 1,i)) % mod;
			// cout << ans << " ";
		}
		if(k == 0)
			ans = 1;
        cout << ans << '\n';
    }
}