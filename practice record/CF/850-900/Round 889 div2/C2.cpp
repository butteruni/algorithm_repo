#include <bits/stdc++.h>
using namespace std;
const int N = 30;
struct op
{
    int i,j;
};
int n;
int t;
int a[N];
vector<op>ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    int flag = 0;
    while(t--)
    {
        cin >> n;
        ans.clear();
        int cnt_ne = 0,cnt_po = 0;
        int mx_pos = 0,mn_pos = 0;
        int mx_val = -25,mn_val = 25;
        bool success = 1;
        for(int i = 1;i <= n;++i)
        {
            cin >> a[i];
            if(a[i] < a[i - 1] && i != 1)
                success = 0;
            if(a[i] < 0)
                cnt_ne++;
            if(a[i] > 0)
                cnt_po++;
            if(mx_val < a[i])
            {
                mx_val = a[i];
                mx_pos = i;
            }
            if(mn_val > a[i])
            {
                mn_val = a[i];
                mn_pos = i;
            }
        }
        if(success)
        {
            cout << 0 << "\n";
            continue;
        }
        if(cnt_ne >= 13)
        {
            int mn = 1;
            while(a[mn] >= 0)
                mn++;
            for(int i = 1;i <= 5;++i)
            {
                ans.push_back({mn,mn});
                a[mn] += a[mn];
            } 
            for(int i = 1;i <= n;++i)
            {
                if(a[i] > 0)
                {
                    ans.push_back({i,mn});
                    a[i] += a[mn];
                }
            }
            for(int i = n - 1;i >= 1;--i)
            {
                if(a[i] > a[i + 1])
                {
                    ans.push_back({i,i + 1});
                    a[i] += a[i + 1];
                }
            }
        }else if(cnt_po >= 13)
        {
            int mx = 1;
            while(a[mx] <= 0)
                mx++;
            for(int i = 1;i <= 5;++i)
            {
                ans.push_back({mx,mx});
                a[mx] += a[mx];
            }
            for(int i = 1;i <= n;++i)
            {
                if(a[i] < 0)
                {
                    ans.push_back({i,mx});
                    a[i] += a[mx];
                }
            }
            for(int i = 2;i <= n;++i)
            {
                if(a[i] < a[i - 1])
                {
                    ans.push_back({i,i - 1});
                    a[i] += a[i - 1];
                }
            }
        }else 
        {
            if(abs(a[mx_pos]) >= abs(a[mn_pos]))
            {
                for(int i = 1;i <= n;++i)
                {
                    if(a[i] < 0)
                    {
                        ans.push_back({i,mx_pos});
                        a[i] += a[mx_pos];
                    }
                }
                for(int i = 2;i <= n;++i)
                {
                    if(a[i] < a[i - 1])
                    {
                        ans.push_back({i,i - 1});
                        a[i] += a[i - 1];
                    }
                }
            }else 
            {
                for(int i = 1;i <= n;++i)
                {
                    if(a[i] > 0)
                    {
                        ans.push_back({i,mn_pos});
                        a[i] += a[mn_pos];
                    }
                }
                for(int i = n - 1;i >= 1;--i)
                {
                    if(a[i] > a[i + 1])
                    {
                        ans.push_back({i,i + 1});
                        a[i] += a[i + 1];
                    }
                }
            }
        }
        cout << ans.size() << '\n';
        for(auto x:ans)
        {
            cout << x.i << " " << x.j << '\n';
        }
    }
}
