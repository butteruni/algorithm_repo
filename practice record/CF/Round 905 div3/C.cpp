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
        vector<int>a(n);
        int cnt_2 = 0;
        int cnt_3 = 0;
        int cnt_5 = 0;
        for(int i = 0;i < n;++i)
        {
            cin >> a[i];
            int x = a[i];
            while(x % 2 == 0)
            {
                cnt_2++;
                x /= 2;
            }
            x = a[i];
            while(x % 3 == 0)
            {
                cnt_3++;
                x /= 3;
            }
            x = a[i];
            while(x % 5 == 0)
            {
                cnt_5++;
                x /= 5;
            }
        }
        if(k == 2)
        {
            if(cnt_2)
            {
                cout << 0 << "\n";
            }else 
            {
                cout << 1 << '\n';
            }
        }else if(k == 3)
        {
            if(cnt_3)
            {
                cout << 0 << "\n";
            }else 
            {
                int ans = 20;
                for(int i = 0;i < n;++i)
                {
                    for(int j = 3;j <= 20;j += 3)
                    {
                        if(j >= a[i])
                            ans = min(ans,j - a[i]);
                    }
                }
                cout << ans << '\n';
            }
        }else if(k == 4)
        {
            int ans = max(0, 2 - cnt_2);
            for(int i = 0;i < n;++i)
            {
                for(int j = 4;j <= 20;j += 4)
                {
                    if(j >= a[i])
                        ans = min(ans,j - a[i]);
                }
            }
            cout << ans << '\n';
        }else if(k == 5)
        {
            if(cnt_5)
            {
                cout << 0 << "\n";
            }else 
            {
                int ans = 20;
                for(int i = 0;i < n;++i)
                {
                    for(int j = 5;j <= 20;j += 5)
                    {
                        if(j >= a[i])
                            ans = min(ans,j - a[i]);
                    }
                }
                cout << ans << '\n';
            }
        }
    }
}