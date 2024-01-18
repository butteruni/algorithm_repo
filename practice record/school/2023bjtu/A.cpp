#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
void solve()
{
    int n;
    cin >> n;
    if(n == 1)
    {
        cout << 7 << '\n';
    }else if(n == 2)
    {
        cout << 4 << '\n';
    }else if(n == 3)
    {
        cout << 3 << '\n';
    }else if(n == 4) 
    {
        cout << 4 << '\n';
    }else 
    {
        cout << "Invalid\n";
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