#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
ll cnt[350];
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(s.back() != '!')
    {
        cout << "NO\n";
        return;
    }
    ll sum = 0;
    for(int i = 0;i < s.size();++i)
    {
        if(s[i] == '+')
            cnt[i]++;
    }
    for(int i = n - 1;i >= 0;--i)
        cnt[i] += cnt[i + 1];
    for(int i = 0;i < s.size();++i)
    {
        if(s[i] == '/')
        {
            for(int j = i + 1;j < s.size();++j)
            {
                if(s[j] == '/')
                {
                    sum += cnt[j];     
                }
            }
        }
        
    }
    // cout << sum << " ";
    if(sum >= 66)
    {
        cout << "YES\n";
        return ;
    }else 
    {
        cout << "NO\n";
        return;
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