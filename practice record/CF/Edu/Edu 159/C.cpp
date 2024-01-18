#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 2e5 + 10;
ll gcd(ll x,ll y)
{
    if(x == 0 || y == 0)
        return max(x,y);
    return gcd(y,x % y);
}
ll a[N];
void solve()
{
    int n;
    cin >> n;
    ll total_gcd = 0;

    set<ll>s;
    for(int i = 1;i <= n;++i)
    {
        cin >> a[i];
        s.insert(a[i]);
    }
    sort(a + 1,a + 1 + n);
    ll ans = 0;
    for(int i = 2;i <= n;++i)
    {
        ll dis = a[i] - a[i - 1];
        total_gcd = gcd(total_gcd,dis);
    }
    if(!total_gcd)
        total_gcd = 1;
    ll sum = 0;
    bool add = 0;
    for(int i = n;i >= 1;--i)
    {
        if(!add && !s.count(a[i] - total_gcd))
        {
            add = 1;
            sum += a[n] - a[i] + total_gcd;
        }
        sum += a[n] - a[i];
    }
    cout << sum / total_gcd << "\n";


}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}