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
        int ans = 0;
        int st = '1';
        for(int i = 0;i < 4;++i)
        {
            int cur = s[i];
            if(cur == '0')
                cur = '9' + 1;
            ans ++;
            ans += abs(cur - st);
            st = cur;
        }
        cout << ans << '\n';

    }
}