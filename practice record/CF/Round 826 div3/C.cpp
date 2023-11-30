#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2020;
ll a[N];
ll sum;
int ans;
int n;
void calc(ll val)
{
    ll cur = 0;
    int gap = 0;
    int cnt = 0;
    for(int i = 0;i < n;++i)
    {
        if(cur == val)
        {
            cur = 0;
            gap = max(gap,cnt);
            cnt = 0;
        }else if(cur > val)
        {
            return;
        }
        cur += a[i];
        cnt++;
    }
    if(cur == val)
    {
        cur = 0;
        gap = max(gap,cnt);
        cnt = 0;
    }else if(cur > val)
    {
        return;
    }
    ans = min(ans,gap);
    // cout << val << " " << ans << '\n';
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
        ans = n;
        sum = 0;
        for(int i = 0;i < n;++i)
        {
            cin >> a[i];
            sum += a[i];
        }
        for(int i = 1;i <= n;++i)
        {
            if(sum % i == 0)
            {
                calc(sum / i);
            }
        }
        cout << ans << '\n';
    }
}