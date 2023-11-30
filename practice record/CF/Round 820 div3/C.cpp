#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int cnt[30];
vector<vector<int> >pos(30);
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
        memset(cnt,0,sizeof(cnt));
        for(int i = 0;i <= 26;++i)
        {
            pos[i].clear();
        }
        int n = s.size();
        int st = s[0] - 'a';
        int ed = s.back() - 'a';
        for(int i = 1;i < n;++i)
        {
            cnt[s[i] -'a'] ++;
            pos[s[i] -'a'].push_back(i + 1);
        }
        ll cost = abs(st - ed);
        vector<int>ans;
        ans.push_back(1);
        int step = 1;
        if(st > ed)
        {
            for(int i = st;i >= ed;--i)
            {
                step += cnt[i];
                for(auto x: pos[i])
                {
                    ans.push_back(x);
                }
            }
        }else 
        {
            for(int i = st;i <= ed;++i)
            {
                step += cnt[i];
                for(auto x: pos[i])
                {
                    ans.push_back(x);
                }
            }
        }
        cout << cost << " " << step << '\n';
        for(auto x:ans)
        {
            cout << x << ' ';
        }
        cout << '\n';
    }
}