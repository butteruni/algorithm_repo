#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const ll mod = 1000000007;
const int N = 5e6 + 10;
int cnt;
bool vis[N];
ll pri[N];

void init()
{
    vis[1] = 1;
    for (int i = 2; i < N; i++)
    {
        if (!vis[i]) // 如果没有被筛过就是质数
        {
            pri[++cnt] = i;
        }
        for (int j = 1; j <= cnt; j++)
        {
            if (1ll * i * pri[j] >= N)
                break;
            vis[i * pri[j]] = 1;
            if (i % pri[j] == 0)
            {
                break;
            }
        }
    }
}
void solve()
{
    ll k;
    cin >> k;
    ll ans = 1;
    for(int i = 1;i <= cnt;++i)
    {
        if(pri[i] > k)
            break;
        ll st = pri[i];
        while(st * pri[i]<= k)
        {
            st = st * pri[i];
        }
        ans = ans * st % mod;
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
}