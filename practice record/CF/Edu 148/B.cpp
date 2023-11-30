#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long ll;
int n,k;
ll a[N];
ll pre_sum[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        memset(a,0,sizeof(a));
        memset(pre_sum,0,sizeof(pre_sum));
        cin >> n >> k;
        ll sum = 0;
        // priority_queue<ll>p;
        for(int i = 1;i <= n;++i)
        {
            cin >> a[i];
        }
        sort(a + 1,a + 1 + n);
        for(int i = 1;i <= n;++i)
        {
            pre_sum[i] = pre_sum[i - 1] + a[i];
        }
        ll ans = 0;
        int posl = 2 * k,posr = n;
        for(int i = 0;i <= k;++i)
        {
            ans = max(ans,pre_sum[posr] - pre_sum[posl]);
            posl -= 2,posr -= 1;
        }
        cout << ans << '\n';
    }
}