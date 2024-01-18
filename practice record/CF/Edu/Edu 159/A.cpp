#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >>  s;
    bool ok = 0;
    int cnt_0 = 0,cnt_1 = 0;
    for(int i = 0;i < n;++i)
    {
        if(s[i] == '0')
            cnt_0++;
        else 
            cnt_1++;
    }
    if(cnt_0 > cnt_1)
        ok = 1;
    for(int i = 0;i + 1 < s.size();++i)
    {
        if(s[i] == '0' && s[i + 1] == '1')
            ok = 1;
        if(s[i] == '1' && s[i + 1] == '0')
            ok = 1;
    }
    if(ok)
    {
        cout << "YES\n";
    }else 
    {
        cout << "NO\n";
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