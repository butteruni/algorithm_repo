#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const ll N = 15;
ll a[N][N],b[N][N];
void solve()
{
    int h,w;
    cin >> h >> w;
    for(int i = 1;i <= h;++i)
    {
        for(int j = 1;j <= w;++i)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 1;i <= h;++i)
    {
        for(int j = 1;j <= w;++i)
        {
            cin >> b[i][j];
        }
    }
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