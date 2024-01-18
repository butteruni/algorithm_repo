#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
char mp[110][110];
string aim = "HNIST";
void solve()
{
    ll n,m,k;
    cin >> n >> m >> k;
    bool ok = 0;

    int ans = 0;
    for(int i = 1;i <= k;++i)
    {
        int x,y;
        cin >> x >> y;
        cin >> mp[x][y];
        for(int j = 0;j <= 4;++j)
        {
            
            if(mp[x][y] == aim[j])
            {
                int l = 0,r = 0;
                while(y - l >= 1 && j - l >= 0 && mp[x][y - l] == aim[j - l])
                {
                    l++;
                }
                while(y + r <= n && j + r <= 4 && mp[x][y + r] == aim[j + r])
                {
                    r++;
                }
                if(j - l == -1 && j + r == 5)
                {
                    ok = 1;
                    ans = k;
                    break;
                }
                // cout << l << " " <<  r << '\n';
            }
        }
    }
    if(ans)
    {
        cout << ans << '\n';
    }else 
    {
        cout << "Oh no!\n";
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