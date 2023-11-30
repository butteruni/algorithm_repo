#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int n,k;
ll a[N];
bool check(int x)
{
    ll sum = 0;
    int cnt = 0;
    for(int i = 1;i <= n;++i)
    {
        sum += a[i];
        if(sum >= x)
        {
            cnt++;
            sum = 0;
        } 
    }
    return cnt > n / 2;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;++i)
        cin >> a[i];
    if((n + (1 - k)) % 2 == 0)
    {
        ll ans = 0;
        for(int i = 1;i <= n / 2 + 1;++i)
            ans += a[i];
        ll temp = ans;
        for(int i = n / 2 + 2;i <= n;++i)
        {
            temp += a[i] - a[i - n / 2 - 1];
            ans = min(ans,temp);
        }
        cout << ans << endl;
    }else 
    {   
        ll l = 0,r = 1e9;
        while(l < r)
        {
            ll mid = (l + r) >> 1;
            // cout << mid << "-" << l <<  endl;
            if(check(mid))
            {
                if(l == mid)
                    break;
                l = mid;
            }else 
            {
                r = mid;
            }
        }
        cout << l << endl;
    }
}