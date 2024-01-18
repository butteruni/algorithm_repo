#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
void solve()
{
    ll n,m;
    cin >> n >> m;
    vector<vector<int>>ans;
    ll node = n * m;
    if(node & 1)
    {
        cout << "NO\n" << '\n';
        return ;
    }else 
    {
        ans.resize(n + 1);
        for(int i = 1;i <= n;++i)
        {
            for(int j = i + 1;j <= n;++j)
            {
                if(ans[i].size() == m)
                    break;
                ans[i].push_back(j);
                ans[j].push_back(i);

            }
        }
        cout << "YES\n" ;
        for(int i = 1;i <= n;++i)
        {
            for(auto x:ans[i])
            {
                cout << x << " ";
            }
            cout << '\n';
        }
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