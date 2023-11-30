#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// 25 50 75 00
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    vector<int>ans(4,2*n);
    vector<string>aim(4);
    aim[0] = "25";
    aim[1] = "50";
    aim[2] = "75";
    aim[3] = "00";
    for(int i = 0;i < 3;++i)
    {
        map<char,int>mp;
        mp[aim[i][0]] = -1;
        mp[aim[i][1]] = -1;
        int cnt = -1;
        int add = 0;
        for(int j = n;j >= 0;--j)
        {
            if(s[j] == aim[i][0] || s[j] == aim[i][1])
            {
                if(j == 0 && s[1] == '0' && mp[aim[i][1]] != 1)
                {
                    
                }
                if(mp[s[j]] == -1)
                {
                    cnt++;
                }
                mp[s[j]] = max(mp[s[j]],j);
                if(cnt == 1)
                {
                    break;
                }
            }

        }
        if(mp[aim[i][0]] < 2 && mp[aim[i][1]] < 2 && s[2] == '0')
            continue;
        if(cnt == 1)
        {
            int cur = 0;
            for(auto [x,val]:mp)
            {
                // cout << val <<" ";
                cur += n - val - 1;
            }
            cur--;
            if(mp[aim[i][0]] > mp[aim[i][1]])
            {
                cur += 1;
                // cout << aim[i] << ' ';
            }
            ans[i] = min(ans[i],cur);
            cout << cur << " " << aim[i] << " ";
        }
    }
    vector<int>pos;
    for(int i = n;i >= 0 && pos.size() < 2;--i)
    {
        if(s[i] == '0')
        {
            pos.push_back(i);
        }
    }
    if(pos.size() == 2)
    {
        ans[3] = 0;
        for(auto x:pos)
        {
            // cout << x << " ";
            ans[3] += n - x - 1;
        }
        ans[3] --;
        // cout << ans[3] << " ";
    }
    sort(ans.begin(),ans.end());
    if(ans[0] == 2 * n)
    {
        cout << -1 << '\n';
    }else 
    {
        cout << ans[0] << '\n';
    }

}