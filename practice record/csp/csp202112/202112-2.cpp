#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef long long ll;
ll n,m;
ll g_sum,f_sum,ans;
int a[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    ll r = m / (n + 1);
    for(int i = 1;i <= n;++i)
        cin >> a[i];
    a[n + 1] = m;
    int step = 1;
    for(int i = 1;i <= n + 1; ++i)
    {
        for(int j = a[i - 1];j < a[i];j += step)
        {
            int ne_limit = (j / r + 1) * r - 1;
            if(ne_limit >= a[i])
                ne_limit = a[i] - 1;
            int cur_cnt = ne_limit - j + 1;
            ans += cur_cnt * abs(i - 1 - (j / r));
            step = cur_cnt;
        }
    }
    cout << ans << endl;
}