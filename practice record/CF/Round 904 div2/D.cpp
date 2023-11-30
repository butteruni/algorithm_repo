#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,ll>cnt;
map<ll,ll>vis;
map<ll,ll>count;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        vector<ll>f(n + 1,0); // f[i] 表示以 i 为因数的数出现了几次
        vector<int>g(n + 1,0);// g[i] 表示存在 a_k 同时整除 f[i]里的数;
        for(int i = 1;i <= n;++i)
        {
            int x;
            cin >> x;
            f[x]++;
            g[x] = 1;
        }
        for(int i = 1;i <= n;++i)
        {
            for(int j = 2 * i;j <= n;j += i)
            {
                f[i] += f[j];
                g[j] |= g[i];
            }
        }
        for(int i = 1;i <= n;++i)
        {
            f[i] *= f[i];
        }
        for(int i = n;i > 0;--i)
        {
            for(int j = 2 * i;j <= n;j += i)
            {
                f[i] -= f[j];
            }
        }
        ll ans = 0;
        for(int i = 1;i <= n;++i)
        {
            if(!g[i])
                ans += f[i];
        }
        ans /= 2;
        cout << ans << '\n';
    }
}