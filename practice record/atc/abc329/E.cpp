#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 2e5 + 10;
bool dp[N][6];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin >> n >> m;
    string s,t;
    cin >> s >> t;
    // int r = n - 1;
    // int st = m - 1;
    s = " " + s;
    t = " " + t;
    dp[0][0] = 1;
    for(int i = 1;i <= n;++i)
    {
        for(int j = 1;j <= m;++j)
        {
            if(s[i] == t[j])
            {
                dp[i][j] |= dp[i - 1][j - 1];
                dp[i][j] |= dp[i - 1][m];
            }
            if(s[i] == t[1])
            {
                dp[i][1] |= dp[i - 1][j];
            }
        }
    }
    if(dp[n][m])
    {
        cout << "Yes\n";
    }else 
    {
        cout << "No\n";
    }
}