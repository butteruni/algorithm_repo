#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const ll N = 2e5 + 10;
ll a[N];
void solve()
{
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;++i)
    {
        cin >> a[i];
        a[i] ^= a[i - 1];
    }
    for(int i = 1;i <= m;++i)
    {
        int l,r;
        cin >> l >> r;
        cout << (a[r] ^ a[l - 1]) << '\n';
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