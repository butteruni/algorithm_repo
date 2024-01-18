#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef long long ll;
int a[N];
ll pre[N];
bitset<200001>dp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    ll ans = a[1];
    dp.set(a[1]);
    dp.reset(0);
    for(int i = 2;i <= n;++i)
    {
        if(dp.test(i - 1))
        {
            ans = max(ans,pre[i] - (i - 1));
        }
        dp |= dp << a[i];
        dp.reset(i - 1);
    }
    for(int i = n - 1;i <= 2 * n;++i)
    {
        if(dp.test(i))
        {
            ans = max(ans,pre[n] - i);
        }
    }
    cout << ans << '\n';
}