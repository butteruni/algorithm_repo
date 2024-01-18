#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 1010;
ll m[N][N];
ll ans[N][35];
ll a[N];
void solve()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i)
    {
        for(int j = 0;j < 30;++j)
            ans[i][j] = 1;
    }
    for(int i = 1;i <= n;++i)
    {
        for(int j = 1;j <= n;++j)
        {
            cin >> m[i][j];
            ll x = m[i][j];
            if(i != j)
            {
                for(ll k = 0;k < 30;++k)
                {
                    if(!((x >> k) & 1))
                    {
                        ans[i][k] = 0;
                    }
                }
            }
        }
    }
    for(int i = 1;i <= n;++i)
    {
        a[i] = 0;
        for(ll j = 0;j < 30;++j)
        {
            a[i] += ans[i][j] * (1ll << j);
        }
    }
    // bool ok = 1;
    for(int i = 1;i <= n;++i)
    {
        for(int j = 1;j <= n;++j)
        {
            if(i == j)
                continue;
            if((a[i] | a[j]) != m[i][j])
            {
                // cout << a[i] << " " << a[j] << " " << m[i][j] << "\n";
                cout << "NO\n";
                return ;
            }
        }
    }
    cout << "YES\n";
    for(int i = 1;i <= n;++i)
    {
        cout << a[i] << " ";
    }
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