#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,ll>mp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll n,m;
    cin >> n >> m;
    ll ans = 0;
    ll sum = 0;
    vector<ll>a(n);
    for(int i = 0;i < n;++i)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    // deque<ll>pre;
    // pre.clear();
    sort(a.begin(),a.end());
    int l = 0,r = 0;
    for(r = 0;r < n;++r)
    {
        while(r > l && a[r] >= a[l] + m)
        {
            sum --;
            l++;
        }
        sum ++;
        ans = max(ans,sum);
    }
    cout << ans << '\n';
    
}