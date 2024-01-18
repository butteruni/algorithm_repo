#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll n,k;
        cin >> n >> k;
        vector<ll>b(n + 1);
        for(int i = 1;i <= n;++i)
            cin >> b[i];
        int pre = 1;
        vector<bool>vis(n + 1);
        bool ok = 1;
        for(int i = 1;i <= k && ok;++i)
        {
            int cur = pre - 1;
            if(i == 1)
                cur = n;
            if(b[cur] > n)
            {
                ok = 0;
            }
            if(vis[cur])
                break;
            vis[cur] = 1;
            pre = (cur - b[cur] + n) % n + 1;
        }
        if(ok)
            cout << "Yes\n";
        else    
            cout << "No\n";
    }
}