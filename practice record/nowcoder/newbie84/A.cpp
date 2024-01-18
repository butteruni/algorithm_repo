#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
void solve()
{
    ll n,m,x,y;
    cin >> n >> m >> x >> y;
    ll res = n - m;
    if(x + n - m >= y && x <= y)
    {
        cout << "Yes\n";
    }else 
    {
        cout << "No\n";
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