#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<ll>a(n + 1);
        for(int i = 1;i <= n;++i)
        {
            cin >> a[i];
        }
        vector<ll>dp(n + 2,0x3f3f3f3f);
        vector<ll>suf(n + 2,0x3f3f3f3f);
        suf[n + 1] = n + 1;
        dp[n + 1] = 0;
        for(int i = n ;i >= 1;--i)
        {
            dp[i] = dp[i + 1] + 1;
            int ne = i + a[i];
            if(ne + 1 <= n + 1)
            {
                dp[i] = min(dp[i],suf[ne + 1] - ne - 1);
            }
            suf[i] = min(suf[i + 1],dp[i] + i);
        }
        cout << dp[1] << "\n";
    }
}