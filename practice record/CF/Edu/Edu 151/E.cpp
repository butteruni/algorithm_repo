#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int N = 1510;
int n,k;
int a[N];
ll dp[100][100][100];
int pre[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;++i)
        cin >> a[i];
    for(int i = 1;i <= n;++i)
    {
        pre[i] = pre[i - 1] + a[i];
    }
    dp[0][0][0] = 1;
    // for(int i = 1;i <= n;++i)
    //     dp[i][pre[i]][0] = 0;
    for(int i = 0;i <= n;++i)
    {
        for(int j = 0;j <= i;++j)
        {
            for(int l = 0;l <= k;++l)
            {
                
            }
        }
    }
    cout << dp[n][pre[n]][k];
    
}