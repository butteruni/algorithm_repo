#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[1010][1010];
bool vis[1010][1010];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i = 1;i <= n;++i)
        {
            for(int j = 1;j <= n;++j)
            {
                cin >> a[i][j];
                vis[i][j] = 0;
            }
        }
        int ans = 0;
        for(int i = 1;i <= n;++i)
        {
            for(int j = 1;j <= n;++j)
            {
                if(vis[i][j])
                    continue;
                int i1,i2,i3,j1,j2,j3;
                i1 = j,j1 = n - i + 1; 
                i2 = n - i + 1,j2 = n - j + 1;
                i3 = n - j + 1,j3 = i;
                // cout << i << " " << j << '\n';
                // cout << i1 << " " << j1 << '\n';
                // cout << i2 << " " << j2 << '\n';
                // cout << i3 << " " << j3 << '\n';

                map<char,int>mp;
                mp[a[i][j]]++,mp[a[i1][j1]]++,mp[a[i2][j2]]++,mp[a[i3][j3]]++;
                int sum = a[i][j] + a[i1][j1] + a[i2][j2] + a[i3][j3];
                char mx = 0;
                for(auto[x,val]:mp)
                {
                    mx = max(mx,x);
                }
                // cout << mx << " ";
                ans += 4 * mx - sum;
                vis[i][j] = 1,vis[i1][j1] = 1,vis[i2][j2] = 1,vis[i3][j3] = 1;
            }
        }
        cout << ans << '\n';

    }
}