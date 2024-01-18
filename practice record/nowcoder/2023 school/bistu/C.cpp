#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
void solve()
{
    int n;
    cin >> n;
    if(n <= 3)
    {
        cout << -1 << '\n'; 
    }else if(n == 4)
    {
        cout << "2 4 1 3\n";
    }else if(n == 5)
    {
        cout << "2 4 1 3 5\n";
    }else if(n == 6)
    {
        cout << "2 4 6 1 3 5\n";
    }else if(n == 7)
    {
        cout << "2 4 6 1 3 5 7\n";
    }else if(n % 2 == 0)
    {
        int sz = n / 2;
        int st = 2;
        for(int i = 1;i <= sz;++i)
        {
            if(i == sz - 3)
            {
                cout << n - 3 << " ";
            }
            if(i == sz - 2)
            {
                cout << n - 1 << " ";
            }

            cout << st << " ";
            st += 2;
        }
        st = n - 3;
        for(int i = 1;i < sz - 1;++i)
        {
            st -= 2;
            cout << st << ' ';
        }
        cout << '\n';
    }else 
    {
        int sz = n / 2;
        int st = 2;
        for(int i = 1;i <= sz;++i)
        {
            if(i == sz - 2)
            {
                cout << n - 2 << " ";
            }
            if(i == sz - 1)
            {
                cout << n << " ";
            }
            cout << st << " ";
            st += 2;
        }
        st = n - 2;
        for(int i = 1;i < sz;++i)
        {
            st -= 2;
            cout << st << ' ';
        }
        cout << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
}