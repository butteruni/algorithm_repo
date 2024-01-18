#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 2e5 + 10;
ll t[N],x[N];
deque<int>e[N];
bool action[N];
void solve()
{
    int n;
    cin >> n;
    bool ok = 1;
    for(int i = 1;i <= n;++i)
    {
        action[i] = 1;
        cin >> t[i] >> x[i];
        if(t[i] == 1)
        {
            e[x[i]].push_back(i);
        }else 
        {
            if(e[x[i]].size())
            {
                e[x[i]].pop_back();
            }else 
                ok = 0;
        }
    }
    for(int i = 1;i <= n;++i)
    {
        while(e[i].size())
        {
            int u = e[i].front();
            e[i].pop_front();
            action[u] = 0;
        }
    }
    int ans = 0;
    int num = 0;
    for(int i = 1;i <= n;++i)
    {
        if(action[i] == 1)
        {
            if(t[i] == 1)
                num++;
            else 
                num--;
        }
        ans = max(ans,num);
    }
    if(ok)
    {
        cout << ans << '\n';
        for(int i = 1;i <= n;++i)
        {
            if(t[i] == 1)
                cout << action[i] << " ";
        }
        cout << '\n';
    }else 
    {
        cout << -1 << '\n';
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