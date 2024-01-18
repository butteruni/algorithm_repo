#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
void solve()
{
    int n;
    cin >> n;
    int cnt = 0;
    int id = n % 2;
    while(n % 2 == 0)
    {
        cnt++;
        n /= 2;
    }
    cout << cnt << '\n';
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