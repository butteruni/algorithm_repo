#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 2e5 + 10;
ll a[N];
ll l[N],r[N];
ll b[N];
void solve()
{
    ll n,k;
    cin >> n >> k;
    // abs(a_i - b_i) <= k
    
    // a_i - b_i <= k and b_i - a_i <= k;
    // b_i >= a_i - k and b_i <= a_i + k;
    // b_i <= b_{i + 1};
    for(int i = 1;i <= n;++i)
        cin >> a[i];
    for(int i = 1;i <= n;++i)
    {
        l[i] = a[i] - k;
        r[i] = a[i] + k;
    }
    bool ok = 1;
    b[1] = l[1];
    for(int i = 2;i <= n;++i)
    {
        if(r[i] < b[i - 1])
        {
            ok = 0;
            break;
        }else 
        {
            b[i] = max(l[i],b[i - 1]);
        }
    }
    if(ok)
    {
        cout << "Yes\n";
    }else 
    {
        cout << "No\n";
    }
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