#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
void solve()
{
    ll M,D,y,m,d;
    cin >> M >> D >> y >> m >> d;

    d++;
    if(d == D + 1)
    {
        d = 1;
        m++;
    }
    if(m == M + 1)
    {
        m = 1;
        y++;
    }
    cout << y << ' ' << m << ' ' << d << '\n';
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