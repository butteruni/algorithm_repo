#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e18;
const int N = 5e4 + 10;
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
    for(int i = 1;i <= 50000;++i)
    {
        sum[i] = sum[i - 1] + mul[i];
    }
}
ll calc(ll n,ll m)
{
    ll res = 0;
    for(ll l = 1,r;l <= m;l = r + 1)
    {
        r = min(n / (n / l),m / (m / l));
        res += (sum[r] - sum[l - 1]) * (n / l) * (m / l);
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
        ll a,b,d;
        cin >> a >> b >> d;
        a /= d,b /= d;
        if(a < b)
            swap(a,b);
        ll ans = calc(a,b);
        cout << ans << '\n';
    }
}