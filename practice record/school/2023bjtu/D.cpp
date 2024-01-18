#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 5050;
ll a[N];
int n;
ll calc(int pos)
{
    ll res = 0;
    for(int i = 1;i < pos;++i)
    {
        res += a[i];
    }
    bool ok = 1;
    for(int i = pos;i <= n;++i)
    {
        int cnt = i - pos + 1;
        if(a[i] < cnt)
            ok = 0;
        if(!ok)
            res += a[i];
        else 
        {
            res += a[i] - cnt;
        }
        // cout << res << " ";
    }   
    res ++;
    // cout << res << '\n';
    return res;
}
void solve()
{
    cin >> n;
    for(int i = 1;i <= n;++i)
        cin >> a[i];
    sort(a + 1,a + 1 + n);
    ll sum = 1e18;
    for(int i = 1;i <= n;++i)
    {
        sum = min(sum,calc(i));
        // cout << calc(i) << " ";
    }
    cout << sum << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}