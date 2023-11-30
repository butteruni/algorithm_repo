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
        ll n,m,k;
        cin >> n >> m >> k;
        if(k > 3)
        {
            cout << "0\n";
        }else 
        {
            ll ans = 0;
            if(k == 3)
            {
                ans = m - n - (m / n - 1);
            }else if(k == 2)
            {
                ans = m / n + min(n - 1,m);
            }else if(k == 1)
            {
                ans = 1;
            }
            if(ans < 0)
            {
                ans = 0;
            }
            cout << ans << '\n';
        }
    }
}