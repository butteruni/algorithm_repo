#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;

void solve()
{
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= k;++i)
    {
        cout << i << " ";
    }
    cout << n << ' ';
    for(int i = n - 1;i >= k + 1;--i)
        cout << i << " ";
    cout << '\n';
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