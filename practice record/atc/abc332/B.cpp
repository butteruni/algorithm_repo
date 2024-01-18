#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
void solve()
{
    ll k,g,m;
    cin >> k >> g >> m;
    int a = 0, b = 0;
    for(int i = 1;i <= k;++i)
    {
        if(a == g)
            a = 0;
        else if(b == 0)
        {
            b = m;
        }else 
        {
            ll bb = b;
            ll pre_a = a;
            a = min(a + bb,g);
            b = b - (a - pre_a);
        }
    }
    cout << a << " " << b << "\n";
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