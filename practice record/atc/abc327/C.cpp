#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[10][10];
bool vis[10];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    bool ok = 1;
    for(int i = 1;i <= 9;++i)
    {
        memset(vis,0,sizeof(vis));
        for(int j = 1;j <= 9;++j)
        {
            cin >> a[i][j];
            if(vis[a[i][j]])
                ok = 0;
            vis[a[i][j]] = 1;
        }
    }
    for(int j = 1;j <= 9;++j)
    {
        memset(vis,0,sizeof(vis));
        for(int i = 1;i <= 9;++i)
        {
            if(vis[a[i][j]])
                ok = 0;
            vis[a[i][j]] = 1;
        }
    }
    for(int i = 1;i <= 9;i += 3)
    {
        for(int j = 1;j <= 9;j += 3)
        {
            memset(vis,0,sizeof(vis));
            for(int l = i;l <= i + 2;++l)
            {
                for(int r = j;r <= j + 2;++r)
                {
                    if(vis[a[l][r]])
                        ok = 0;
                    vis[a[l][r]] = 1;
                }
            }
        }
    }
    if(!ok)
    {
        cout << "No\n";
    }else 
    {
        cout << "Yes\n";
    }
}