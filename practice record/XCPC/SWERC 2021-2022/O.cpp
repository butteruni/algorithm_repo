#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 5000;
bool a[25][400];
bool block[25][400];
bool vis[25][400];
bool ok;
void dfs(int r,int angle)
{
    if(ok)
        return;
    vis[r][angle] = 1;
    // cout << r << " " << angle << endl;
    if(!a[r][angle]) // 前往下一层
    {
        if(r == 20)
        {
            ok = 1;
            return;
        }else if(!vis[r + 1][angle])
            dfs(r + 1, angle);
    }
    if(r > 1 && !a[r - 1][angle]) 
    {
		if(!vis[r - 1][angle]) 
            dfs(r - 1, angle);
	}
    if(!block[r][(angle + 1) % 360]) //逆时针
    {
        if(!vis[r][(angle + 1) % 360])
            dfs(r,(angle + 1) % 360);
    }
    if(!block[r][angle]) // 顺时针
    {
        if(!vis[r][(angle + 359) % 360])
            dfs(r,(angle + 359) % 360);
    }
    
}
void solve()
{
    int n;
    cin >> n;
    memset(a,0,sizeof(a));
    memset(block,0,sizeof(block));
    memset(vis,0,sizeof(vis));
    for(int i = 1;i <= n;++i)
    {
        char x;
        cin >> x;
        if(x == 'C')
        {
            int r,a1,a2;
            cin >> r >> a1 >> a2;
            for(int j = a1;j != a2;j = (j + 1) % 360)
                a[r][j] = 1;
        }else 
        {
            int r1,r2,angle;
            cin >> r1 >> r2 >> angle;
            for(int j = r1 + 1;j <= r2;j++)
                block[j][angle] = 1;
        }
        // cout << i << endl;
    }
    ok = 0;
    // cout << 1 << endl;
    dfs(1,0);
    if(ok)
    {
        cout << "YES\n";
    }else 
    {
        cout << "NO\n";
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