#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int t,n;
int cnt[N],pre_sum[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        int ans = 0;
        for(int i = 1;i <= n;++i)
        {
            cin >> a[i];
            if(i == 1)
            {
                cnt[i] = (a[i] == 1);
                pre_sum[i] = a[i];
            }else 
            {
                cnt[i] = cnt[i - 1] + (a[i] == 1);
                pre_sum[i] = pre_sum[i - 1] + a[i];
            }
        }
        if(pre_sum[n] >= 0)
            ans = (n - cnt[n]) & 1;
        else 
        {
            ans += (pre_sum[n] - 1) * (-1) / 2;
            cnt[n] += ans;
            ans += (n - cnt[n]) & 1;
        }
        cout << ans << '\n';
    }
}