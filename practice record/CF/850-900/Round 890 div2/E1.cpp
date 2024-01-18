#include <bits/stdc++.h>
using namespace std;
const int N = 5050;
typedef long long ll;
int n;
vector<vector<int> >e;
ll sz[N];
ll ans = 0;
void dfs(int u)
{
    bitset<N>dp;
    dp.set(0);
    for(auto son:e[u])
    {
        dfs(son);
        sz[u] += sz[son];
        dp |= dp << sz[son];
    }
    ll tmp = 0;
    for(int i = 0;i <= n / 2;++i)
    {
        if(dp.test(i))
        {
            tmp = max(tmp,1ll * i * (sz[u] - i));
        }
    }
    ans += tmp;
    sz[u] += 1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n;
    e.resize(n + 1);
    for(int i = 2;i <= n;++i)
    {
        int x;
        cin >> x;
        e[x].push_back(i);
    }
    dfs(1);
    cout << ans << "\n";
}