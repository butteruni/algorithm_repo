#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
map<PLL,int>mp;
int a,b;
int xk,yk;
int xq,yq;
void calc(int x,int y)
{
    mp[{x + a,y + b}]++;
    mp[{x - a,y + b}]++;
    mp[{x + a,y - b}]++;
    mp[{x - a,y - b}]++;
    if(a != b)
    {
        mp[{x + b,y + a}]++;
        mp[{x - b,y + a}]++;
        mp[{x + b,y - a}]++;
        mp[{x - b,y - a}]++;
    }
}
void solve()
{
    cin >> a >> b;
    cin >> xk >> yk;
    cin >> xq >> yq;
    mp.clear();
    calc(xk,yk);
    calc(xq,yq);
    int ans = 0;
    for(auto [x,val]:mp)
        if(val == 2)
            ans++;
    cout << ans << '\n';
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