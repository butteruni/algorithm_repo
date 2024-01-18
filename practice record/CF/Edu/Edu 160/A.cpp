#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
int string_to_int(string s)
{
    int res = 0;
    for(auto x:s)
    {
        res *= 10;
        res += x - '0';
    }
    return res;
}
void solve()
{
    string s;
    cin >> s;
    for(int i = 0;i < s.size() / 2;++i)
    {
        string a = s.substr(0,i + 1);
        string b = s.substr(i + 1,s.size() - i);
        if(b[0] == '0' || a[0] == '0')
            continue;
        if(string_to_int(a) < string_to_int(b))
        {
            cout << a << " " << b << '\n';
            return ;
        }
    }
    cout << -1 << '\n';
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