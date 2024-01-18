#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;

int n,m;
string s;
bool check(ll val)
{   
    bool ok = 1;
    ll a = m,b = val;
    for(int i = 1;i <= n;++i)
    {
        int x = s[i] - '0';
        if(x == 0)
        {
            a = m,b = val;
        }else if(x == 1)
        {
            if(a)
            {
                a --;
            }else if(b)
            {
                b--;
            }else 
                ok = 0;
        }else 
        {
            if(b)
            {
                b--;
            }else 
            {
                ok = 0;
            }
        }
    }
    return ok;
}
void solve()
{
    cin >> n >> m;
    cin >> s;
    s = " " + s;
    ll l = 0,r = 1e9;
    while(l < r)
    {
        ll mid = (l + r) >> 1;
        if(check(mid))
        {
            r = mid;
        }else 
        {
            l = mid + 1;
        }
    }   
    cout << r << '\n'; 
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