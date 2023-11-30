#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 20101009;
const int N = 1e7 + 10;
ll prime[N],sum[N],mul[N];
bool vis[N];
int cnt;
void init()
{
    vis[1] = 1;
    mul[1] = 1;
    for(int i = 2;i<=N;i++) 
    {
        if(!vis[i])//如果没有被筛过就是质数
        {
            prime[++cnt]=i;
            mul[i] = -1; 
        }
        for(int j = 1;j <= cnt;j++) 
        {
            if(1ll * i * prime[j] > N)
                break;
            vis[i * prime[j]] = 1;
            if(i % prime[j] == 0) 
            {
                mul[i * prime[j]] = 0;
                break;
            }
            mul[i * prime[j]] = -mul[i];
        }
    }
    for(ll i = 1;i < N;++i)
    {
        sum[i] = (((sum[i - 1] + i * i * mul[i]) % mod) + mod) % mod;
    }
}
ll Sum(ll a)
{
    return (((a + 1) * a / 2) % mod + mod) % mod;
}
ll calc2(ll n,ll m)
{
    ll res = 0;
    for(ll l = 1,r;l <= m;l = r + 1)
    {
        r = min(n / (n / l),m / (m / l));
        res = (res + ((sum[r] - sum[l - 1]) % mod) * (Sum(n / l) * Sum(m / l) % mod)) % mod;
    }
    return res;
}
ll calc1(ll n,ll m)
{
    ll res = 0;
    for(ll l = 1,r;l <= m;l = r + 1)
    {
        r = min(n / (n / l),m / (m / l));
        res = (res + ((r - l + 1) * (l + r) / 2 % mod) * 
        calc2(max(m / l,n / l),min(m / l,n / l)) % mod + mod) % mod;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    init();
    ll n,m;
    cin >> n >> m;
    if(n < m)
        swap(n,m);
    ll ans = calc1(n,m);
    cout << ans << "\n";
}