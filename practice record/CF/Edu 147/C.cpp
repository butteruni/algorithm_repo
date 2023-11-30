#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        vector<vector<int>>pos(26);
        for(int i = 0;i < n;++i)
        {
            int u = s[i] - 'a';
            pos[u].push_back(i);
        }
        int ans = n;
        for(auto x:pos)
        {
            if(!x.size())
                continue;
            int gap = 0;
            int cur_sz = x.size();
            vector<int>other;
            int mx_gap = 0;
            if(x[0] != 0)
            {
                mx_gap = max(mx_gap,x[0]);
            }
            for(int i = 0;i < cur_sz - 1;++i)
            {
                if(x[i] != x[i + 1] - 1)
                {
                    mx_gap = max(mx_gap,x[i + 1] - x[i] - 1);
                }
            }
            if(x[cur_sz - 1] != n - 1)
            {
                    mx_gap = max(mx_gap,n - 1 - x[cur_sz - 1]);
            }
            int step = 0;
            while(mx_gap)
            {
                step++;
                mx_gap /= 2;
            }
            ans = min(ans,step);
        }
        cout << ans << '\n';
    }
}