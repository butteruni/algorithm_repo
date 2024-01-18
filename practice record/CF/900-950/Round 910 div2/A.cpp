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
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        int cnt = 0;
        for(auto x:s)
            if(x == 'B')
                cnt++;
        if(cnt == k)
        {
            cout << 0 << '\n';
        }else 
        {
            cnt = 0;
            bool ok = 0;
            s = " " + s;
            for(int i = n;i >= 1;--i)
            {
                if(k - cnt == i)
                {
                    cout << 1 << '\n';
                    cout << i << ' ' << 'B' << '\n';
                    ok = 1;
                }
                if(cnt == k)
                {
                    cout << 1 << '\n';
                    cout << i << ' ' << 'A' << '\n';
                    ok = 1;
                }
                if(ok)
                    break;
                if(s[i] == 'B')
                    cnt++;
            }
            assert(ok == 1);
        }
    }
}