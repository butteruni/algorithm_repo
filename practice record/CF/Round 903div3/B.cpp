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
        vector<ll>a;
        for(int i = 0;i < 3;++i)
        {
            ll x;
            cin >> x;
            a.push_back(x);
        }
        sort(a.begin(),a.end());
        ll cnt = 0;
        ll mn = a[0];
        // cout << mn << "\n";
        bool flag = 1;
        while(cnt <= 3 && flag)
        {
            flag = 0;
            int sz = a.size();
            for(int i = sz - 1;i >= 0;--i)
            {
                if(a[i] > mn)
                {
                    ll pre = mn;
                    a.push_back(a[i] - mn);
                    // cout << a[i] - mn << ' ';
                    mn = min(mn,a[i] - mn);
                    a[i] = pre;
                    cnt++;
                }
            }
                // cout << mn << " " << cnt << " " << a.size() << "__";
            sort(a.begin(),a.end());
            for(int i = 0;i < a.size();++i)
            {
                if(a[i] != mn)
                {
                    flag = 1;
                    break;
                }
            }
        }
        if(cnt <= 3)
        {
            cout << "YES\n"; 
        }else 
        {
            cout << "NO\n";
        }

    }
}