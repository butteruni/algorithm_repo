#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int N = 1e5 + 10;
ll a[N];
ll inv[N];
ll pre[N];
void init()
{
	inv[1]=1;
    for(ll i=2;i<N;++i) 
    {
        inv[i]=(long long)(mod-mod/i)*inv[mod%i]%mod;
    }
}
ll qpow(ll a, ll b)
{
    ll ans = 1;
    a = (a % mod + mod) % mod;
    while (b)
    {
        if (b & 1)
            ans = (a * ans) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    init();
    ll ans = 0;
    for(ll i = 1;i <= n;++i)
    {
        cin >> a[i];
        pre[i] = (pre[i - 1] + a[i]) % mod;
    }
    ll sum = 0;
    for(int i = 1;i <= n;++i)
    {
        int l = i,r = n + 1 - i;
        if(l < r)
        {
            sum = (sum + pre[r] - pre[l - 1]) % mod;
        }else 
        {
            sum = (sum - (pre[r] - pre[l - 1])) % mod;
        }
        ans = ((ans + sum * inv[i]) % mod + mod) % mod;
    }
    cout << ans << '\n';

}