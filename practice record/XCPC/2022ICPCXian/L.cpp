#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
int d[N];
int dep[N];
map<int,int>cnt;
vector<int>e[N];
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
        for(int i = 0;i <= n;++i)
        {
            d[i] = dep[i] = 0;
            e[i].clear();
        }
        cnt.clear();
        for(int i = 2;i <= n;++i)
        {
            // cin >> p[i];
            int x;
            cin >> x;
            d[x]++;
            e[i].push_back(x);
        }
        queue<int>q;
        for(int i = 1;i <= n;++i)
        {
            if(!d[i])
            {
                q.push(i);
                dep[i] = 1;
            }   
        }
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            for(auto x:e[cur])
            {
                d[x]--;
                dep[x] = dep[cur] + 1;
                if(d[x] == 0)
                    q.push(x);
            }
        }
        int ans = 1e9;
        for(int i = 1;i <= n;++i)
            cnt[dep[i]] ++;
        for(int i = 1;i <= n;++i)
        {
            ans = min(ans,cnt[i] + i - 1);
        }       
        cout << ans << '\n';
        
    }
    
    
}