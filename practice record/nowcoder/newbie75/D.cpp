#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N = 1010;
int a[N][N];
int dist[N][N];
int d[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
bool vis[N][N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;++i)
    {
        for(int j = 1;j <= m;++j)
        {
            char x;
            cin >> x;
            a[i][j] = x - '0';
        }
    }
    memset(dist,0x3f,sizeof(dist));
    dist[1][1] = 0;
    priority_queue<pair<int,PII> >p;
    p.push({0,{1,1}});
    while(p.size())
    {
        auto temp = p.top().second;
        p.pop();
        if(vis[temp.first][temp.second])
            continue;
        vis[temp.first][temp.second] = 1;
        for(int i = 0;i < 4;++i)
        {
            int nx = temp.first + d[i][0],ny = temp.second + d[i][1];
            if(nx < 1 || ny < 1 || nx > n || ny > m)
                continue;
            int cost = 0;
            if((nx + ny - 2) & 1)
            {
                if(a[nx][ny] == a[1][1])
                    cost = 1;
                else 
                    cost = 2;
            }else 
            {
                if(a[nx][ny] == a[1][1])
                    cost = 2;
                else 
                    cost = 1;
            }
            if(dist[nx][ny] > dist[temp.first][temp.second] + cost)
            {
                dist[nx][ny] = dist[temp.first][temp.second] + cost;
                p.push({dist[nx][ny],{nx,ny}});
            }
        }
    }
    cout << dist[n][m] << endl;
}