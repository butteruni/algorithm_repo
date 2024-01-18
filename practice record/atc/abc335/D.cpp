#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
int ans[50][50];
void solve()
{
    int n;
    cin >> n;
    int x = 1,y = 1;
    int dx = 0,dy = 1;
    int cnt = 1;
    ans[x][y] = 1;
    int val = 2;
    while(cnt < ((n * n) - 1))
    {
        x += dx,y += dy;
        if(ans[x][y] != 0 || x > n || x < 1 || y > n || y < 1)
        {
            x -= dx,y -= dy;
            if(dx == 0 && dy == 1)
            {
                dx = 1,dy = 0;
            }else if(dx == 1 && dy == 0)
            {
                dx = 0,dy = -1;
            }else if(dx == 0 && dy == -1)
            {
                dx = -1,dy = 0;
            }else if(dx == -1 && dy == 0)
            {
                dx = 0,dy = 1;
            }
            x += dx,y += dy;
            ans[x][y] = val;
            val++;
            cnt++;
        }else 
        {
            ans[x][y] = val;
            val++;
            cnt++;
        }
        // cout << x <<  " " << y << endl;
    }
    // cout << cnt << endl;
    for(int i = 1;i <= n;++i)
    {
        for(int j = 1;j <= n;++j)
        {
            if(i == (n + 1) / 2 && j == (n + 1) / 2)
            {
                cout << "T ";
                continue;
            }
            cout << ans[i][j] << " ";
        }
        cout << "\n";
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