#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 1e6 + 10;
const int MAXBIT = 32;
ll a[N];
vector<int>pos;
void solve()
{
    int n;
    cin >> n;
    ll mx = 0;
    for(int i = 1;i <= n;++i)
    {
        cin >> a[i];
    }
    pos.push_back(0);
    for(ll i = 32;i >= 0;--i)
    {
        vector<int>cur_pos;
        if(pos.size() < 2)
        {
            for(int j = 1;j <= n;++j)
            {
                if((a[j] >> i) & 1)
                {
                    cur_pos.push_back(j);
                }
            }
            if(cur_pos.size() > 1)
            {
                pos = cur_pos;
            }
        }else 
        {
            for(auto x:pos)
            {
                if((a[x] >> i) & 1)
                {
                    cur_pos.push_back(x);
                }
            }
            if(cur_pos.size() > 1)
            {
                pos = cur_pos;
            }
        }
    }

    cout << (a[pos[0]] & a[pos[1]]) << "\n";
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