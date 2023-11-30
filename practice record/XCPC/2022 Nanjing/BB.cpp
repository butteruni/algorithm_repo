#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e6 + 10;
int n, a[maxn], k;
int hh = 1, tt = 0; // 最小的最小值
int dp[maxn], dp2[maxn];
int q[maxn];
char s[maxn];
int l[maxn];
void solve1()
{
    hh = 1, tt = 0;
    q[++tt] = 0;
    dp[0] = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        while (i - q[hh] > k)
            ++hh; // 若队首出窗口，hh加1
        dp[i] = dp[q[hh]] + a[i];
        if (s[i] == '1') // 我们将队列里面只留下这个数，保证后面一定会取到这个
        {
            hh = 1, tt = 0;
        }
        while (hh <= tt && dp[i] < dp[q[tt]])
            --tt;    // 若队尾不单调，tt减1
        q[++tt] = i; // 下标加到队尾
    }
}
void change(int pos, int val)
{
    int last = a[pos];
    a[pos] = val;
    hh = 1, tt = 0;
    for (int i = max(0ll, pos - k); i <= pos - 1; i++)
    {
        if (s[i] == '1') // 我们将队列里面只留下这个数，保证后面一定会取到这个
        {
            hh = 1, tt = 0;
        }
        while (hh <= tt && dp[i] <= dp[q[tt]])
            --tt;    // 若队尾不单调，tt减1
        q[++tt] = i; // 下标加到队尾
        l[i] = dp[i];
    }
    int ans = 1e18;
    for (int i = pos; i <= min(n + 1, pos + k - 1); i++)
    {
        while (i - q[hh] > k)
            ++hh;
        l[i] = l[q[hh]] + a[i];
        ans = min(ans, l[i] + dp2[i]);
        if (s[i] == '1') // 我们将队列里面只留下这个数，保证后面一定会取到这个
        {
            hh = 1, tt = 0;
        }
        while (hh <= tt && l[i] < l[q[tt]])
            --tt;    // 若队尾不单调，tt减1
        q[++tt] = i; // 下标加到队尾
    }
    a[pos] = last;
    cout << ans << '\n';
}
void solve2()
{
    reverse(a + 1, a + n + 1);
    reverse(s + 1, s + n + 1);
    dp2[0] = 0;
    hh = 1, tt = 0;
    q[++tt] = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        while (i - q[hh] > k)
            ++hh; // 若队首出窗口，hh加1
        dp2[i] = dp2[q[hh]] + a[i];
        if (s[i] == '1') // 我们将队列里面只留下这个数，保证后面一定会取到这个
        {
            hh = 1, tt = 0;
        }
        while (hh <= tt && dp2[i] < dp2[q[tt]])
            --tt;    // 若队尾不单调，tt减1
        q[++tt] = i; // 下标加到队尾
    }
    reverse(a + 1, a + n + 1);
    reverse(s + 1, s + n + 1);
    reverse(dp2, dp2 + n + 2); // reverse函数是左闭右开的
    for (int i = 1; i <= n; i++)
        dp2[i] -= a[i];
}
void solve()
{
    scanf("%lld%lld", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    a[n + 1] = 0;
    a[0] = 0;
    scanf("%s", s + 1);
    s[n + 1] = 0;
    s[0] = '0';
    solve1();
    solve2();
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int pos, val;
        scanf("%lld%lld", &pos, &val);
        change(pos, val);
    }
}
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}