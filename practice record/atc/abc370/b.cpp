#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 2e5 + 10;
const int M = 300;
int a[M][M];
void solve()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i)
    {
        for(int j = 1;j <= i;++j)
            cin >> a[i][j];
    }
    int ans = 1;
    for(int i = 1;i <= n;++i)
    {
        if(ans >= i)
            ans = a[ans][i];
        else 
            ans = a[i][ans];
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    solve();
}