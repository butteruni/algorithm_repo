#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
typedef pair<ll,ll>PLL;
void solve()
{
    int n;
    cin >> n;
    vector<ll>a(n);
    bool ok = 0;
    for(int i = 0;i < n;++i)
        cin >> a[i];
    sort(a.begin(),a.end());
    ll ans = 1;
    while(!ok)
    {
        ans <<= 1ll;
        ll tmp = a[0] % ans;
        for(int i = 1;i < n;++i)
        {
            if((a[i] % ans) != tmp)
            {
                ok = 1;
                break;
            }
        }  
    }
    cout << ans << '\n';
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