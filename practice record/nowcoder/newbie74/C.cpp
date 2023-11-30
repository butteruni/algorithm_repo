#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int t,n,m;
int c[N][N];
bool vis[200010];
int ans = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        memset(vis,0,sizeof(vis));
        ans = 0;
        for(int i = 1;i <= n;++i)
        {
            for(int j = 1;j <= m;++j)
            {
                cin >> c[i][j];
                if(!vis[c[i][j]])
                {
                    ans++;
                    vis[c[i][j]] = 1;
                }
            }
        }
        cout << ans << '\n';
    }

}