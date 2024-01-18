#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
void solve()
{
    ll a,b,c,d,e;
    cin >> a >> b >> c >> d >> e;
    ll A,B,C,D;
    cin >> A >> B >> C >> D;
    ll sum = A * a + B * b + C * c - D * d;
    if(sum > e)
    {
        cout << "YES\n"; 
    }else 
    {
        cout << "NO\n";
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
}