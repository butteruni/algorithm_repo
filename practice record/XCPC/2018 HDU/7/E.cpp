#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 10;
bool vis[N];
ll inv[N];
ll mu[N],phi[N];
ll sum[N];
int cnt,prime[N];
ll p;
ll n,m;
void init()
{
    phi[1] = mu[1] = 1;
    for(int i = 2;i < N;++i)
    {
        if(!vis[i])// i 为质数
        {
            prime[++cnt] = i;
            mu[i] = -1,phi[i] = i - 1;
        }
        for(int j = 1;j <= cnt;++j)
        {
            if(prime[j] * i >= N)
                break;
            vis[i * prime[j]] = 1;
            if(i % prime[j] == 0)
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }else 
            {
                mu[i * prime[j]] = -mu[i],phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            }
        }
    }
    for(int i = 1;i <= 1e6;++i)
    {
        sum[i] = sum[i - 1] + mu[i];
    }
}
void re()
{
	inv[1]=1;
    for(ll i=2;i<N;++i) 
    {
        inv[i]=(long long)(p-p/i)*inv[p%i]%p;
    }
}
ll calc(ll n,ll m)
{
    ll res = 0;
    for(ll l = 1,r;l <= m;l = r + 1)
    {
        r = min(n / (n / l),m / (m / l));
        res = (res + (sum[r] - sum[l - 1]) * (n / l) * (m / l)) % p;
    }
    return res % p;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    init();
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> p;
        re();
        ll ans = 0;
        for(int i = 1;i <= min(n,m);++i)
        {
            ll nn = n / i;
            ll mm = m / i;
            ll add = (i * inv[phi[i]]) % p;
            // cout << add << " ";
            if(nn < mm)
                swap(nn, mm);
            // cout << nn << " " << mm << "\n";
            ans = (ans + add * calc(nn,mm)) % p;
            // cout << ans << '\n';
        }
        cout << ans << '\n';
    }
}