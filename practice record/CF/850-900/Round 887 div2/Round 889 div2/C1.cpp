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
        ans.clear();
        cin >> n;
        int mx = -1e9;
        int mn = 1e9;
        int mx_pos = 0;
        int mn_pos = 0;
        for(int i = 1;i <= n;++i)
        {
            cin >> a[i];
            if(a[i] > mx)
            {
                mx = a[i];
                mx_pos = i;
            }
            if(a[i] < mn)
            {
                mn = a[i];
                mn_pos = i;
            }
        }
        if(mx <= 0)
        {
            if(mn == mx)
            {
                cout << 0 << '\n';
                continue;
            }
            for(int i = 1;i <= 6 && mn >= -40;++i)
            {
                ans.push_back(op{mn_pos,mn_pos});
                mn += mn;
                a[mn_pos] += a[mn_pos];
            }
            if(mn >= 0)
            {
                system("pause");
            }
            for(int i = n;i > 1;--i)
            {
                while(a[i] < a[i - 1])
                {
                    ans.push_back(op{i - 1,mn_pos});
                    a[i - 1] += mn;
                    if(a[i - 1] < mn)
                    {
                        mn = a[i - 1];
                        mn_pos = i - 1;
                    }
                }
            }
        }else 
        {
            for(int i = 1;i <= 6 && mx <= 40;++i)
            {
                ans.push_back(op{mx_pos,mx_pos});
                mx += mx;
                a[mx_pos] += a[mx_pos];
            }
            for(int i = 2;i <= n;++i)
            {
//                 cout << mx << " ";
//                 cout <<  i << " " << a[i] << "\n";
                while(a[i] < a[i - 1])
                {
                    ans.push_back(op{i,mx_pos});
                    a[i] += mx;
                    if(a[i] > mx)
                    {
                        mx = a[i];
                        mx_pos = i;
                    }
                }
            }
        }
//         for(int i = 1;i <= n;++i)
//         {
//             cout << a[i] << " ";
//         }
//         cout << "\n";
        cout << ans.size() << '\n';
        for(auto x:ans)
        {
            cout << x.i << " " << x.j << '\n';
        }
    }
//     if(flag)
//         cout << "no" << endl;
}
