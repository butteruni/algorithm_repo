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
        vector<ll>pre(n + 1);
        for(int i = 1;i <= n;++i)
            cin >> a[i];
        pre[0] = 0;
        pre[1] = a[1];
        for(int i = 1;i <= n;++i)
            pre[i] = a[i] + pre[i - 1];
        ll ans = 0;
        for(int i = 1;i < n;++i)
        {
            if(n % i == 0)
            {
                ll mn = 1e18;
                ll mx = 0;
                for(int j = i;j <= n;j += i)
                {
                    ll cur = pre[j] - pre[j - i];
                    mx = max(mx,cur);
                    mn = min(mn,cur); 
                }
                ans = max(ans,mx - mn);
            }
        }
        cout << ans << '\n';
    }
}