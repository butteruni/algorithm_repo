#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
typedef pair<int,char>Pii;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    vector<int>cnt(26,0);
    
    for(int i = 1;i <= n;++i)
    {
        int j = i;
        while(s[j] == s[i])
        {
            j++;
        }
        j --;
        cnt[s[i] - 'a'] += j - i + 1;
        i = j;
    }
    sort(cnt.begin(),cnt.end());

    ll mx = cnt.back();
    // cout << mx << " ";
    if(mx <= n / 2)
    {
        cout << (n % 2) << '\n';
    }else 
    {
        ll res = n - mx;
        cout << mx - res << '\n';
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