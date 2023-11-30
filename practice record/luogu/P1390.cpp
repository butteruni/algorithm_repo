#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e4 + 10;
ll prime[N],sum[N],mul[N];
bool vis[N];
ll pre[N];
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
    for(int i = 1;i <= 50000;++i)
    {
        sum[i] = sum[i - 1] + mul[i];
    }
    for(int i = 1;i <= 5e4;++i)
    {
        ll res = 0;
        for(ll l = 1,r;l <= i;l = r + 1)
        {
            r = i / (i / l);
            res += (r - l + 1) * (i / l);
        }
        pre[i] = res;
    }
}
ll calc(ll n,ll m)
{
    ll res = 0;
    for(ll l = 1,r;l <= n;l = r + 1)
    {
        r = min(n / (n / l),m / (m / l));
        res += (sum[r] - sum[l - 1]) * pre[n / l] * pre[m / l];
    }
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
        ll n,m;
        cin >> n >> m;
        if(n > m)
            swap(n,m);
        ll ans = calc(n,m);
        cout << ans << "\n";
    }
}