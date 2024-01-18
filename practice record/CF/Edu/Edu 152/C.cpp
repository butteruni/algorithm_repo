#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 10;
typedef pair<int,int> PII;
ll t;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        string s;
        cin >> s;
        s = " " + s;
        // cout << s << '\n';
        vector<int>pos_0(n + 10);
        vector<int>pos_1(n + 10);
        for(int i = 1;i <= n;++i)
        {
            if(s[i] == '0')
                pos_0[i] = i;
            else 
                pos_0[i] = pos_0[i - 1];
        }
        for(int i = n;i >= 1;--i)
        {
            if(s[i] == '1')
                pos_1[i] = i;
            else 
                pos_1[i] = pos_1[i + 1];
        }
        map<PII,int>vis;
        int cnt = 0;
        for(int i = 1;i <= m;++i)
        {
            int l,r;
            cin >> l >> r;
            int ll = pos_1[l],rr = pos_0[r];
            // cout << ll << " " << rr << "||";
            if(ll <= rr && ll != 0 && rr != 0)
            {
                if(vis.count({ll,rr}))
                {
                    continue;
                }else 
                {
                    vis[{ll,rr}] = 1;
                    cnt++;
            // cout << ll << " " << rr << "||";
                }
            }else 
            {
                if(vis.count({-2,-2}))
                    continue;
                else 
                {
                    vis[{-2,-2}] = 1;
                    cnt++;
            // cout << ll << " " << rr << "|--";
                }
            }
        }
        cout << cnt << '\n';
    }   
}