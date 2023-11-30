#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 300;
ll n, m, c, d;
char s[N][N];
ll a[N], b[N];
void solve()
{
    cin >> n >> m >> c >> d;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == '.')
            {
                a[i]++;
                b[j]++;
            }
        }
    }
    ll k = max(*max_element(a, a + n), *max_element(b, b + m));
    ll ans = c * k;
    for (int i = k - 1; i >= 0; i--)
    {
        ll cnt1 = 0;
        for (int j = 0; j < n; j++)
            cnt1 += max(0LL, a[j] - i);
        ll cnt2 = 0;
        for (int j = 0; j < m; j++)
            cnt2 += max(0LL, b[j] - i);
        ans = min(ans, max(cnt2, cnt1) * d + c * i);
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
}