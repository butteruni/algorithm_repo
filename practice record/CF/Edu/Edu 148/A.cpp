#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
bool vis[30];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        string s;
        cin >> s;
        bool success = 0;
        for(int i = 0;i < s.length() / 2;++i)
        {
            if(!vis[s[i] - 'a'] && i != 0)
            {
                success = 1;
                break;
            }else 
            {
                vis[s[i] - 'a'] = 1;
            }
        }
        if(success)
        {
            cout << "YES" << '\n';
        }else 
        {
            cout << "NO" << '\n';
        }
    }
}