#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int n;
string s;
vector<int>pos[10];
ll value[30];
ll calc()
{
    ll res = 0;
    int mx = -1;
    for(int i = s.size() - 1;i >= 0;--i)
    {
        int val = s[i] - 'A';
        if(val < mx)
            res -= value[val];
        else 
            res += value[val];
        mx = max(val,mx);
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    value[0] = 1;
    for(int i = 1;i <= 8;++i)
    {
        value[i] = value[i - 1] * 10;
    }
    while(t--)
    {
        cin >> s;
        ll ans = calc();
        for(int i = 0;i <= 5;++i)
            pos[i].clear();
        for(int i = 0;i < s.size();++i)
        {
            int val = s[i] - 'A';
            pos[val].push_back(i);
        }
        for(int i = 0;i < 5;++i)
        {
            if(pos[i].empty())
            {
                continue;
            }
            for(int j = 0;j < 5;++j)
            {
                s[pos[i][0]] = char('A' + j);
                ans = max(ans,calc());
                s[pos[i][0]] = char('A' + i);
                s[pos[i].back()] = char('A' + j);
                ans = max(ans,calc());
                s[pos[i].back()] = char('A' + i);
            }
        }
        cout << ans << '\n';

    }
}

