#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
char s[1010][1010];
bool vis[1010][1010];
ll h,w;
void bfs(int x,int y)
{
    vis[x][y] = 1;
    queue<PII>p;
    p.push(make_pair(x,y));
    while(!p.empty())
    {
        auto tmp = p.front();
        p.pop();
        for(int i = tmp.first - 1;i <= tmp.first + 1;++i)
        {
            for(int j = tmp.second - 1;j <= tmp.second + 1;++j)
            {
                if(i < 1 || i > h || j < 1 || j > w)
                    continue;
                if(s[i][j] == '#' && !vis[i][j])
                {
                    vis[i][j] = 1;
                    p.push(make_pair(i,j));
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> h >> w;
    for(int i = 1;i <= h;++i)
    {
        for(int j = 1;j <= w;++j)
            cin >> s[i][j];
    }
    int cnt = 0;
    for(int i = 1;i <= h;++i)
    {
        for(int j = 1;j <= w;++j)
        {
            if(s[i][j] == '#' && !vis[i][j])
            {
                cnt++;
                bfs(i,j);
            }
        }
    }
    cout << cnt << '\n';
}