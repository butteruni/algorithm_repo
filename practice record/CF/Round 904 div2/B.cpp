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
        vector<int>pos;
        for(int i = 0;i < n;++i)
        {
            if(s[i] == '0')
            {
                pos.push_back(i);
            }
        }
        ll ans = 0;
        int r = pos.size() - 1;
        for(int i = 1;i <= n;++i)
        {
            if(i > pos.size())
            {
                cout << -1 << ' ';
            }else 
            {
                ll ed = n - i;
                ans += ed - pos[r];
                r--;
                cout << ans << " ";
            }
        }
        cout << '\n';
    }
}