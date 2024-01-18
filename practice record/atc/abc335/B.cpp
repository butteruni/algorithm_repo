#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
void solve()
{
    int n;
    cin >> n;
    for(int i = 0;i <= n;++i)
    {
        for(int j = 0;j + i <= n;++j)
        {
            for(int k = 0;k + i + j <= n;++k)
            {
                cout << i << " " << j << " " << k << '\n';
            }
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