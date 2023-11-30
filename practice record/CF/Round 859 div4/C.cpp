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
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool ok = 1;
        map<char,int>vis;
        vis[s[0] - 'a'] = 1;
        for(int i = 1;i < n;++i)
        {
            int pre = s[i - 1] - 'a';
            int cur = s[i] - 'a';
            if(vis.count(cur))
            {
                if(vis[cur] == vis[pre])
                    ok = 0;
            }else 
            {
                vis[cur] = vis[pre] ^ 1;
            }
        }
        if(ok)
        {
            cout <<"YES" << '\n';
        }else 
        {
            cout << "NO\n";
        }
    }
}