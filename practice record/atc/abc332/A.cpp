#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
void solve()
{
    ll n,s,k;
    cin >> n >> s >> k;
    ll sum = 0;
    for(int i = 1;i <= n;++i)
    {
        ll p,q;
        cin >> p >> q;
        sum += p * q;
    }
    if(sum < s)
        sum += k;
    cout << sum << '\n';
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