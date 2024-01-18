#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
map<int,int>mp;
void solve()
{
    int n;
    cin >> n;
    mp.clear();
    for(int i = 1;i <= n;++i)
    {
        int c,d;
        cin >> c >> d;
        mp[d] = max(mp[d],c);
    }
    if(mp.size() < 10)
    {
        cout << "MOREPROBLEMS\n";
    }else 
    {
        int sum = 0;
        for(auto [x,y]:mp)
            sum += y;
        cout << sum << '\n';
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