#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
ll dp[15][150][150];
ll a[20];
ll calc(ll x,ll val,ll sum,ll up,ll mod)
{


}
void solve()
{
    ll n;
    cin >> n;
    int len = 1;
    while(n)
    {
        a[len] = n % 10;
        n /= 10;
        len++;
    }
    ll ans = 0;
    for(int mod = 1;mod <= (len + 1) * 9;++len)
    {
        memset(dp,-1,sizeof(dp));
        ans += calc();
    }
    cout << calc << "\n";
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