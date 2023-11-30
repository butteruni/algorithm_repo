#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,ll>mp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    vector<ll>a(n + 2);
    a[0] = a[n + 1] = 0;
    for(int i = 1;i <= n;++i)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    ll ans = 0;
    for(int i = 0;i <= n + 1;++i)
    {
        if(mp[i] == 0)
        {
            ans = i;
            break;
        }
    }
    for(int i = 1;i <= n;++i)
    {
        if(a[i] == 0)
        {
            ans = max(ans,a[i + 1]);
            ans = max(ans,a[i - 1]);
        }
    }
    cout << ans << '\n';

}