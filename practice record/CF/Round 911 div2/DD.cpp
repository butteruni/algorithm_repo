#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 8e4 + 10;
const int MAXN = 1e5 + 10;
ll a[N];
vector<int>fac[MAXN];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    for(int i = 1;i < MAXN;++i)
    {
        for(int j = i;j < MAXN;j += i)
            fac[j].push_back(i);
    }
    while(t--)
    {
        int n;
        cin >> n;
        for(int i = 1;i <= n;++i)
            cin >> a[i];
        sort(a + 1,a + 1 + n);
        ll ans = 0;
        ll add = 0;
        vector<ll>fa(MAXN,0);
        vector<ll>cnt(MAXN,0);
        for(int i = 1;i <= n;++i)
        {
            ans += add;
            int u = a[i];
            for(int j = fac[u].size() - 1;j >= 0;--j)
            {
                int t = fac[u][j];
                fa[t] += cnt[t];
                add += t * fa[t];
                for(auto x:fac[t])
                {
                    fa[x] -= fa[t];
                }
            }
            for(auto x:fac[u])
            {
                cnt[x]++;
                fa[x] = 0;
            }
        }
        cout << ans << '\n';
    }
}