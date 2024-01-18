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
        int ans = 0;
        int cnt = 0;
        bool ok = 0;
        vector<int>a;
        for(int i = 0;i < n;++i)
        {
            if(s[i] == '.')
                cnt++;
            else 
            {
                a.push_back(cnt);
                cnt = 0;
            }
        }
        if(cnt)
        {
            a.push_back(cnt);
            cnt = 0;
        }
        sort(a.begin(),a.end());
        for(auto x:a)
        {
            if(x == 0)
                continue;
            if(x >= 3)
            {
                ans = 2;
                break;
            }else 
            {
                ans += max(x,1);
            }
        }
        cout << ans << '\n';
    }
}