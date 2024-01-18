#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 2e5 + 10;
ll t[N],a[N];
ll dp[N];
ll ed[N];
struct node
{
    ll val1,val2;
}ls[N];
bool cmp(node x,node y)
{
    if(x.val1 != y.val1)
        return x.val1 < y.val1;
    return x.val2 < y.val2;
}
void solve()
{
    ll n,v;
    cin >> n >> v;
    // abs(a_i - a_{i - 1}) <= v * (t_i - t_{i - 1})

    // a_i - a_{i - 1} <= v * (t_i - t_{i - 1}) 
    // -> -a_{i - 1} + v * t_{i - 1} <= -a_i + v * t_{i}

    // a_{i - 1} - a_{i} <= v * (t_i - t_{i - 1})
    // -> a_{i - 1} + v * t_{i - 1} <= a_i + v * t_{i}
    for(int i = 1;i <= n;++i)
    {
        cin >> t[i];
    }
    for(int i = 1;i <= n;++i)
    {
        cin >> a[i];
        ls[i].val1 = v * t[i] - a[i];
        ls[i].val2 = v * t[i] + a[i];
    }

    sort(ls + 1,ls + 1 + n,cmp);
    ll ans = 0;
    for(int i = 1; i <= n;++i)
    {
        if(ls[i].val1 < 0 || ls[i].val2 < 0)
            continue;
        ll cur = ls[i].val2;
        // cout << cur << " ";
        if(cur >= ed[ans])
        {
            ans++;
            ed[ans] = cur;
        }else 
        {
            int p = upper_bound(ed + 1,ed + 1 + ans,cur) - ed;
            // cout << p << " ";
            ed[p] = cur;
        }
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