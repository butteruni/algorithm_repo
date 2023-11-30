#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 +10;
int x,y;
bool vis[N];
int n,k;
int cnt;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= k;++i)
    {
        cin >> x >> y;
        if(!vis[y] && y != 0)
        {
            cnt++;
            // cout << i << "|";
        }
        vis[x] = 1;
    }
    cout << cnt << endl;
}