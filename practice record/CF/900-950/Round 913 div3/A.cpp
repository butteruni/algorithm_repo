#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
void solve()
{
    // cin >> n;
    char op1,op2;
    cin >> op1 >> op2;
    for(char c = 'a';c <= 'h';c++)
    {
        if(c == op1)
            continue;
        cout << c<< op2 << '\n';
    } 
    for(char c = '1'; c <= '8';++c )
    {
        if(c == op2)
            continue;
        cout << op1<< c << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}