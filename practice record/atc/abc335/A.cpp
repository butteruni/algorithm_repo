#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    n -- ;
    while(1)
    {
        if(s[n] == '3' && s[n - 1] == '2' && s[n - 2] =='0' && s[n - 3] == '2')
        {
            s[n] = '4';
            break;
        }
        n--;
        if(n < 3)
            break;
    }
    cout << s << '\n';
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