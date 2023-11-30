#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char,int>cnt;
    for(int i = 0;i < s.size();++i)
    {
        int l = i,r = i;
        while(s[r] == s[l])
        {
            r++;
        }
        r--;
        i = r;
        cnt[s[i]] = max(cnt[s[i]],r - l + 1);
    }    
    ll ans = 0;
    for(auto [x,val]:cnt)
    {
        ans += val;
    }
    cout << ans << '\n';
}