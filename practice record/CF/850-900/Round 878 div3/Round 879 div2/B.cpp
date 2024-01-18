#include <bits/stdc++.h>
using namespace std;
int t;
string l,r;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> l >> r;
        int ans = 0;
        if(r.size() > l.size())
        {
            for(int i = 0;i <= r.size()- l.size();++i)
                l = "0" + l;
        }
        for(int i = 0;i < r.size();++i)
        {
            if(l[i] != r[i])
            {
                ans += r[i] - l[i] + (r.size() - 1 - i) * 9;
                break;                 
            }
        }
        cout << ans << endl;
    }
}