#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 10;
int n,m;
ll h[N];
ll dp[N];
int pos = 0;
ll ans = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;++i)
    {
        cin >> h[i];
        if(i != 1)
            ans += abs(h[i] - h[i - 1]);
    }
    for(int i = 1;i < n;++i)
    {
        int j = i + 1;
        if(h[j] < h[i])
        {
            ll st = h[i];
            pos++;
            while(h[j] < st && j < n)
            {
                dp[pos] += abs(h[j] - h[j - 1]);
                j++;
            }
            dp[pos] += abs(h[j] - h[j - 1]);
            ll ed = h[j];
            dp[pos] -= abs(ed - st);
            i = j - 1;
        }
    }
//     for(int i = 1;i <= pos;++i)
//     {
//         cout << dp[i] << ' ';
//     }
//     cout << endl;
//     cout << pos << endl;
    sort(dp + 1,dp + 1 + pos);
    for(int i = pos;i >= 1 && m;--i,--m)
    {
        if(dp[i] < 0)
            break;
        ans -= dp[i];
    }
    cout << ans << endl;
}
