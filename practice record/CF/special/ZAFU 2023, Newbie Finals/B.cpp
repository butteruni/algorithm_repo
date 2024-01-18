#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
void solve()
{
    int n;
    cin >> n;
    while(n--)
    {
        char a,b,op;
        cin >> a >> op >> b;
        // cout << a << " " << op << " " << b << '\n';
        // a -= '0';
        // b -= '0';
        // cout << a << " " << op << " " << b << '\n';

        if(op == '*')
        {
            int x = (a - '0') * (b - '0');
            cout << min(x ,9) << '\n';
        }else if(op == '+')
        {
            int x = (a - '0') + (b - '0');
            cout << min(x ,9) << '\n';
        }else if(op == '-')
        {
            int x = a - b;
            if(x < 0)
                x = 9;
            cout << x << '\n';
        }else if(op == '/')
        {
            if((a % b) || b == '0')
            {
                cout << 9 << '\n';
            }else 
            {
                cout << ((a - '0') / (b - '0')) << '\n';
            }
        }
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
        // cout << '\n';
        solve();
    }
}