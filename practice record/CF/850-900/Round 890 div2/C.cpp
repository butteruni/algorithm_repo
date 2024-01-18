#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
typedef long long ll;
ll a[N];
ll n,k;
bool check(ll x)
{
    for(int i = 1;i <= n;++i)
    {
        int ops = k;
        ll aim = x;
        for(int j = i;j <= n;++j)
        {
            if(a[j] >= aim)
                return 1;
            if(ops < aim - a[j])
                return 0;
            ops -= aim - a[j];
            aim--;
        }
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(int i = 1;i <= n;++i)
        {
            cin >> a[i];
        }
        ll l = 0,r = 1e9;
        while(l < r)
        {
            ll mid = (l + r) >> 1;
            if(check(mid))
            {
                l = mid;
            }else 
            {
                r = mid - 1;
            }
        }
        cout << l << '\n';
    }
}