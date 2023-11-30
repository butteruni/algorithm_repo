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
        vector<ll>c(n);
        for(int i = 0;i < n;++i)
        {
            cin >> c[i];
        }
        sort(c.begin(),c.end());
        ll sum = 0;
        bool ok = 1;
        for(int i = 0;i < n && ok;++i)
        {
            if(i == 0)
            {
                if(c[i] != 1)
                    ok = 0;
                sum += c[i];
            }
            else 
            {
                if(c[i] <= sum)
                {
                    sum += c[i];
                }else 
                {
                    ok = 0;
                }
            }
        }
        if(ok)
        {
            cout << "YES\n";
        }else 
        {
            cout << "NO\n";
        }
    }
}