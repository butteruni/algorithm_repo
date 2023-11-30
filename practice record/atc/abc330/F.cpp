#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define x first
#define y second
const int N = 2e5 + 10;
ll x[N],y[N];
ll sum_x[N],sum_y[N];
ll n,k;
bool check(ll val)
{
    ll ans1 = 1e15;
    for(int i = 1,j = 1;i <= n;++i)
    {
        while(x[j] - x[i] <= val)
        {   
            j++;
        }   
        j--;
        ll l = x[i],r = x[i] + val;
        ll t = l * (i - 1) - sum_x[i - 1];
        if(j != n)
            t += sum_x[n] - sum_x[j] - r * (n - j);
        ans1 = min(ans1,t);
    }
    for(int i = n,j = n;i >= 1;--i)
    {
        while(x[i] - x[j] <= val)
        {   
            j--;
        }   
        j++;
        ll r = x[i],l = x[i] - val;
        ll t = sum_x[n] - sum_x[i] - r * (n - i);
        if(j != 1)
            t += l * (j - 1) - sum_x[j - 1];
        ans1 = min(ans1,t);
    }
    ll ans2 = 1e15;
    for(int i = 1,j = 1;i <= n;++i)
    {
        while(y[j] - y[i] <= val)
        {   
            j++;
        }   
        j--;
        ll l = y[i],r = y[i] + val;
        ll t = l * (i - 1) - sum_y[i - 1];
        if(j != n)
            t += sum_y[n] - sum_y[j] - r * (n - j);
        ans2 = min(ans2,t);
    }
    for(int i = n,j = n;i >= 1;--i)
    {
        while(y[i] - y[j] <= val)
        {   
            j--;
        }   
        j++;
        ll r = y[i],l = y[i] - val;
        ll t = sum_y[n] - sum_y[i] - r * (n - i);
        if(j != 1)
            t += l * (j - 1) - sum_y[j - 1];
        ans2 = min(ans2,t);
    }
    return ans1 + ans2 <= k;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;++i)
        cin >> x[i] >> y[i];
    sort(x + 1,x + 1 + n);
    sort(y + 1,y + 1 + n);
    x[0] = -1e18,x[n + 1] = 1e18;
    y[0] = -1e18,y[n + 1] = 1e18;
    for(int i = 1;i <= n;++i)
    {
        sum_x[i] = sum_x[i - 1] + x[i];
        sum_y[i] = sum_y[i - 1] + y[i];
    }
    ll l = 0,r = 1e9;
    while(l < r)
    {
        ll mid = (l + r) >> 1;
        if(check(mid))0
        {
            r = mid;
        }else 
            l = mid + 1;
    }
    cout << l << '\n';
}