#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
ll a[N];
ll n,k;
bool check(ll x)
{
    ll pre = 0;
    ll cnt = 3;
    for(int i = 1;i <= n;++i)
    {
        if(pre == 0)
        {
            if(a[i] - a[1] >= x)
            {
                pre = a[1] + x;
                cnt--;
                while(a[i] - pre > x)
                {
                    cnt--;
                    pre = a[i] + x;
                    // cout << pre << " " ;
                }
                // cout << pre << ' ';
            }
        }else 
        {
            while(a[i] - pre > x)
            {
                cnt--;
                pre = a[i] + x;
                // cout << pre << " " ;
            }
        }
    }
    // cout << '\n';
    return cnt >= 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1;i <= n;++i)
        {
            cin >> a[i];
        }
        sort(a + 1,a + 1 + n);
        ll l = 0,r = 1e9;
        while(l < r)
        {
            ll mid = l + r >> 1;
            // cout << mid << " ";
            if(check(mid))
            {
                r = mid;
            }else 
                l = mid + 1;
        }
        // cout << check(1) << "\n";
        cout << l << '\n';
    }
}