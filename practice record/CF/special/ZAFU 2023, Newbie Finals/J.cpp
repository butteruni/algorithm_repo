#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PLL;
const int N = 200;
char c[N][N];
int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};
bool vis[N][N][4][2];
struct op
{
    int x,y,dir,id;
    
};
void solve()
{
    int n,m;
    cin >> n >> m;
    PLL st,teleport;
    PLL otto;
    for(int i = 1;i <= n;++i)
    {
        for(int j = 1;j <= m;++j)
        {
            cin >> c[i][j];
            if(c[i][j] == '0')
            {
                otto.first = i,otto.second = j;
            }
            else if(c[i][j] == '1')
            {
                st.first = i,st.second = j;
            }else if(c[i][j] == '2')
            {
                teleport.first = i,teleport.second = j; 
            }
        }
    }
    queue<op>q;
    op cur;
    cur.x = otto.first;
    cur.y = otto.second;
    cur.id = 0;
    for(int i = 0;i <= 4;++i)
    {
        cur.dir = i;
        q.push(cur);
        vis[otto.first][otto.second][i][0] = 1;
    }
    while(q.size())
    {
        auto cur = q.front();
        q.pop();
        for(int i = 0;i < 4;++i)
        {
            if(abs(i - cur.id) == 2)
                continue;
            auto ne = cur;
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > m)
                continue;
            if(c[nx][ny] == '#')
                continue;
            ne.x = nx,ne.y = ny;
            ne.dir = i;
            if(c[nx][ny] == 1)
                ne.id = 1;
            if(ne.id && c[nx][ny] == '2')
            {
                cout << "YES\n";
                return;
            }
            if(vis[nx][ny][ne.dir][ne.id])
                continue;
            q.push(ne);
        }
    }
    cout << "NO\n";
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