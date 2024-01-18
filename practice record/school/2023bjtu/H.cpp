#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
void solve()
{
    ll n;
    cin >> n;
    vector<ll>fac;
    for(int i = 1;i * i <= n;++i)
    {
        if(n % (i * i) == 0)
        {
            fac.push_back(i);            
        }
    }
    ll sum = 0;
    for(auto x:fac)
    {
        sum += n / (x * x);
    }
    cout << sum << '\n';
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