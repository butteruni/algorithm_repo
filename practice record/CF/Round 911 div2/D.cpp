#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 8e4 + 10;
const int MAXN = 1e5 + 10;
ll a[N];
int cnt;
bool vis[MAXN];
ll pri[MAXN], phi[MAXN];
vector<int>fac[MAXN];
void init()
{
	vis[1] = 1;
    phi[1] = 1;
	for (int i = 2; i < MAXN; i++)
	{
		if (!vis[i])
		{
			pri[++cnt] = i;
			phi[i] = i - 1;
		}
		for (int j = 1; j <= cnt; j++)
		{
			if (1ll * i * pri[j] >= MAXN)
				break;
			vis[i * pri[j]] = 1;
			if (i % pri[j] == 0)
			{
				phi[i * pri[j]] = phi[i] * pri[j];
				break;
			}
			phi[i * pri[j]] = phi[i] * (pri[j] - 1);
		}
	}
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    init();
    for(int i = 1;i < MAXN;++i)
    {
        for(int j = i;j < MAXN;j += i)
            fac[j].push_back(i);
    }
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i = 1;i <= n;++i)
        {
            cin >> a[i];
            vis[a[i]] = 1;
        }
        sort(a + 1,a + 1 + n);
        ll ans = 0;
        vector<ll>cnt(MAXN);
        for(int i = 1;i <= n;++i)
        {
            for(auto x:fac[a[i]])
            {
                // cout << x <<  " ";
                ans += phi[x] * cnt[x] * (n - i);
                cnt[x]++;
            }
            // cout << ans << " ";
        }
        cout << ans << '\n';
    }
}