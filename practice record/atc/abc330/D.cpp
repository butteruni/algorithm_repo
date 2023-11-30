#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2020;
char s[N][N];
int cnt[N][N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i)
    {
        for(int j = 1;j <= n;++j)
        {
            cin >> s[i][j];
            if(s[i][j] == 'o')
                cnt[i][j]++;
            cnt[i][n + 1] += cnt[i][j];
        }
    }
    for(int i = 1;i <= n;++i)
    {
        for(int j = 1;j <= n;++j)
        {
            cnt[i + 1][j] += cnt[i][j];
        }   
    }
    ll ans = 0;
    for(int i = 1;i <= n;++i)
    {
        ll add = 0;
        for(int j = 1;j <= n;++j)
        {
            if(cnt[i][j] != cnt[i - 1][j])
            {
                ans += (cnt[i][n + 1] - 1) * (cnt[n][j] - 1);
            }
        }
    }
    cout << ans << '\n';
}