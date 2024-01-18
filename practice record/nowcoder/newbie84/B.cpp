#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
void solve()
{
    ll x,y;
    cin >> x >> y;
    if(y % x != 0)
    {
        cout << -1 << "\n";
    }else 
    {
        cout << x << " " << y << "\n";
    }
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