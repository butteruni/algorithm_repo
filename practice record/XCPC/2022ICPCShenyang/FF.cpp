#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e3 + 10;
ll n, m;
ll cnt;
int row[N], col[N];
int k[N];

void solve()
{
    cin >> n >> m;
    vector<vector<int>>ans(n + 1);
    for(int i = 1;i <= n;++i)
    {
        ans[i].resize(m + 1);
    }
    ll sz_n = n * (n + 1) / 2;
    ll sz_m = m * (m + 1) / 2;
    ll cnt = sz_n * sz_m; 
    if(sz_n * m * 2 == cnt || sz_m * n * 2 == cnt)
    {
        cout << "Yes\n";
        if(sz_n * m * 2 == cnt)
        {   
            for(int i = 1;i <= n;++i)
                ans[i][1] = 1;
            for(int i = 1;i <= n;++i)
            {
                for(int j = 2;j <= m;++j)
                {
                    ans[i][j] = ans[i][j - 1] ^ 1;
                }
            }
        }else 
        {   

            for(int i = 1;i <=m;++i)
                ans[1][i] = 1;
            for(int i = 2;i <= n;++i)
            {
                for(int j = 1;j <= m;++j)
                {
                    ans[i][j] = ans[i - 1][j] ^ 1;
                }
            }
        }
        for(int i = 1;i <= n;++i)
        {
            for(int j = 1;j <= m;++j)
            {
                cout << ans[i][j] << " ";
            }
            cout << '\n';
        }
    }else 
    {
        cout << "No\n";
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}