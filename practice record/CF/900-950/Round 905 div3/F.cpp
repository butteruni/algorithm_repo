#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
ll pre[N],aft[N];
map<ll,int>vis;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<ll>a(n);
        vis.clear();
        for(int i = 0;i < n;++i)
        {
            cin >> a[i];
            pre[i] = 0;
            aft[i] = 0;
        }
        for(int i = 0;i < n;++i)
        {
            if(!vis.count(a[i]))
            {
                pre[i] = 1;
                vis[a[i]] = 1;
            }
        }
        vis.clear();
        for(int i = n - 1;i >= 0;--i)
        {
            if(!vis.count(a[i]))
            {
                aft[i] = 1;
                vis[a[i]] = 1;
            }
        }
        // for(int i = 1;i < n;++i)
        //     pre[i] += pre[i - 1];
        for(int i = n - 2;i >= 0;--i)
        {
            aft[i] += aft[i + 1];
        }
        ll ans = 0;
        for(int i = 0;i < n;++i)
        {
            if(pre[i])
                ans += aft[i];
        }
        cout << ans << '\n';
    }
}