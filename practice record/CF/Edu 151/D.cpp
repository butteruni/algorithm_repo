#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 10;
int n;
int t;
ll a[N];
ll pre[N],suf[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1;i <= n;++i)
        {
            cin >> a[i];
            pre[i] = pre[i - 1] + a[i];
        }
        ll mx = 0,ans = 0;
        ll mx_diff = 0;
        for(int i = 1;i <= n;++i)
        {
            mx = max(mx,pre[i]);
            ll diff = mx - pre[i];
            if(diff > mx_diff)
            {
                mx_diff = diff;
                ans = mx;
            }
        }
        cout << ans << '\n';
    }
}