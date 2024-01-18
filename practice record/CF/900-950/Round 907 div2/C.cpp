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
        vector<ll>a(n);
        ll sum = 0;
        ll mx = 0;
        for(auto & x:a)
        {
            cin >> x;
            sum += x;
            mx = max(mx,x);
        }
        ll ans = (sum + 1) / 2;
        sum /= 2;
        if(sum != 0)
        {
            sort(a.begin(),a.end(),greater<>());
            for(int i = 0;i < n;++i)
            {
                sum -= a[i];
                if(sum <= 0)
                {
                    ans += (i + 1);
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
}