#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 1e6 + 10;
ll a[N];
map<ll,ll>mp;
ll id[N];
ll ans[N];
bool cmp(int x,int y)
{
    return a[x] < a[y];
}
void solve()
{
    int n;
    cin >> n;
    ll sum = 0;
    for(int i = 1;i <= n;++i)
    {
        cin >> a[i];
        id[i] = i;
        mp[a[i]]++;
        sum += a[i];
    }
    sort(id + 1,id + 1 + n,cmp);
    for(int i = 1;i <= n;++i)
    {
        int u = id[i];
        sum -= mp[a[u]] * a[u];
        mp[a[u]] = 0;
        ans[u] = sum;
    }
    for(int i = 1;i <= n;++i)
    {
        cout << ans[i] << " ";
    }
    cout << '\n';
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