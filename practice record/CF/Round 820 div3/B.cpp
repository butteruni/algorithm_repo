#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<int,int>mp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int q;
    cin >> q;
    while(q--)
    {
        int n;
        mp.clear();
        cin >> n;
        string s;
        cin >> s;
        // vector<int>pos;
        for(int i = 0;i < n;++i)
        {
            if(s[i] == '0' && s[i + 1] != '0')
            {
                mp[i] = 1;
                // cout << i << " ";
            }
        }
        vector<char>ans;
        for(int i = 0;i < n;++i)
        {
            if(i + 2 < n && mp[i + 2])
            {
                int cur = s[i] - '0';
                cur *= 10;
                cur += s[i + 1] - '0';
                i += 2;
                ans.push_back(cur + 'a' - 1);
            }else 
            {
                int cur = s[i] - '0';
                ans.push_back(cur + 'a' - 1);
            }
            // cout << i << " ";
        }
        for(auto x: ans)
        {
            cout << x;
        }
        cout << '\n';
    }
}