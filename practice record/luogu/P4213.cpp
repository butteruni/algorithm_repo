#include <bits/stdc++.h>
using namespace std;
const int N = 6e6 + 10;
typedef long long ll;
bool vis[N];
ll mu[N],phi[N];
ll sum_mu[N];
ll sum_phi[N];
unordered_map<ll,ll>val_mu;
unordered_map<ll,ll>val_phi;
int cnt,prime[N];
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
    for(int i = 1;i < N;++i)
    {
        sum_mu[i] = sum_mu[i - 1] + mu[i];
        sum_phi[i] = sum_phi[i - 1] + phi[i];
    }
}
ll calc_mu(ll x)
{
    if(x < N - 1)
        return sum_mu[x];
    if(val_mu[x])
        return val_mu[x];
    ll res = 1;
    for(ll l = 2,r;l <= x;l = r + 1)
    {
        r = x / (x / l);
        res -= (r - l + 1) * calc_mu(x / l);
    }
    val_mu[x] = res; 
    return res;
}
ll calc_phi(ll x)
{
    if(x < N - 1)
        return sum_phi[x];
    if(val_phi[x])
        return val_phi[x];
    ll res = (x + 1) * x / 2;
    for(ll l = 2,r;l <= x;l = r + 1)
    {
        r = x / (x / l);
        res -= (r - l + 1) * calc_phi(x / l);
    }
    val_phi[x] = res; 
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    init();
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        cout << calc_phi(n) << " " << calc_mu(n) << "\n";
    }
}