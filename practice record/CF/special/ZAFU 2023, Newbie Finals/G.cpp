#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
ll n,x;
ll dp[20][20];
ll fav[20];
ll p[20];
void solve()
{
    cin >> n >> x;
    bool ok = 0;
    for(int i = 1;i + n - 1 <= 9;++i)
    {
        if(dp[i][n] == x)
        {
            ok = 1;
            for(int k = i;k <= i + n - 1;++k)
            {
                cout << k;
            }
            cout << "\n";
            return;
        }
    }
    if(!ok)
    {
        cout << -1 << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    fav[0] = 1;
    p[0] = 1;
    for(int i = 1;i <= 10;++i)
    {
        fav[i] = fav[i - 1] * i;
        p[i] = p[i - 1] * 10; 
    }
    for(int i = 1;i <= 9;++i)
    {
        ll sum = 0;
        for(int j = 1;i + j - 1 <= 9;++j)
        {
            sum += (i + j - 1);
            for(int k = 1;k <= j;++k)
            {
                dp[i][j] += sum * fav[j - 1] * p[k - 1];
            }
            // cout << i << " " << j << " " << dp[i][j] << "\n";
        }
    }
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}