#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
const int INF = 1e6;
int n,m;
bool vis[N];
int cntl,cntr,cnt;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        cntl = cntr = cnt = 0;
        cin >> n >> m;
        vector<int>ac(m + 2,0);
        for(int i = 0;i < n;++i)
        {
            int x;
            cin >> x;
            if(x == -1)
                cntl++;
            else if(x == -2)
                cntr++;
            else if(!vis[x])
            {
               ac[x] = 1;
               vis[x] = 1;
                cnt++;
            }
        }
        int ans = 0;
        for(int i = 1;i <= m + 1;++i)
        {
            ac[i] += ac[i - 1];
        }
        for(int i = 1;i <= m;++i)
            if(ac[i] - ac[i - 1] == 1)
            {
                ans = max(ans,min(i - ac[i],cntl) + min(cntr,m - (ac[m] - ac[i]) - i));
            }
        ans = max(ans,min(m - (ac[m] - ac[0]),cntr));
        ans = max(ans,min(m - ac[m],cntl));
        ans += cnt;
        cout << ans << '\n';
    }
}