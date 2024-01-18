#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 2e5 + 10;
int cnt[N];
string s;
void solve()
{
    cin >> s;
    int n = s.size();
    s = " " + s;
    int cnt1 = 0,cnt0 = 0;
    for(int i = 1;i <= n;++i)
    {
        cnt[i] = 0;
        if(s[i] == '1')
        {
            cnt1++;
            cnt[i]++;
        }   
        else
        {
            cnt0++;
        } 
        cnt[i] += cnt[i - 1];
    }

    if(cnt1 == 0 || cnt0 == 0)
    {
        cout << n << '\n';
        return;
    }
    for(int i = n;i >= 0;--i)
    {
        if(cnt[i] <= cnt0 && i - cnt[i] <= cnt1)
        {
            cout << n - i << '\n';
            return;
        }
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