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
        ll ans = 1;
        int n = s.size();
        bool ok = 1;
        bool pre = 0;
        for(int i = 0;i < n;++i)
        {
            if(s[i] == '?')
            {
                if(i == 0)
                    ans *= 9;
                else 
                    ans *= 10;
                pre = 1;
            }else 
            {
                if(s[i] != '0')
                {
                    pre = 1;
                }else if(!pre)
                {
                    ok = 0;
                }
            }
        }
        if(ok)
            cout << ans << '\n';
        else 
        {
            cout << 0 << '\n';
        }
    }
}