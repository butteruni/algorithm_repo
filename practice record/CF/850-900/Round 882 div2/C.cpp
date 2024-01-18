#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int a[N];
int n,t;
bool vis[300];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        ll ans = 0;
        memset(vis,0,sizeof(vis));
        for(int i = 1;i <= n;++i)
        {
            cin >> a[i];
        }
        vis[0] = 1;
        ll temp = 0;
        for(int i = 1;i <= n;++i)
        {
            temp ^= a[i];
            for(int j = 0;j < 256;++j)
            {
                if(vis[j])
                    ans = max(ans,temp ^ j);
            }
            vis[temp] = 1;
        }
        cout << ans << endl;
    }
}