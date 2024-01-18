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
        int n,x;
        cin >> n >> x;
        vector<ll>a(n + 2);
        ll ans = 0;
        a[0] = 0;
        for(int i = 1;i <= n;++i)
            cin >> a[i];
        a[n + 1] = x;
        for(int i = n + 1;i >= 1 ;--i)
        {
            a[i] -= a[i - 1];
        }
        for(int i = 1;i <= n;++i)
        {
            ans = max(ans,a[i]);
        }
        // if(n >= 2)
            ans = max(ans,2 * (a[n + 1]));
        cout << ans << '\n';
    }
}