#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 3e5 + 10;
ll a[N];
ll b[N],c[N];
ll aft[N];
ll pre[N];
int n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;++i)
    {
        cin >> a[i];
        b[i] = a[i] - i + n;
        c[i] = a[i] + i - 1;
        pre[i] = max(pre[i - 1],b[i]);
    }   
    for(int i = n;i >= 1;--i)
        aft[i] = max(aft[i + 1],c[i]);
    ll mx = 1e18;
    vector<ll>ans;
    for(int i = 1;i <= n;++i)
    {
        if(i > 1 && i < n)
            ans.push_back(max(a[i],max(pre[i - 1],aft[i + 1])));
        if(i == 1)
            ans.push_back(max(a[i],aft[i + 1]));
        if(i == n)
            ans.push_back(max(a[i],pre[i - 1]));
        // cout << ans.back() << " ";
    }
    sort(ans.begin(),ans.end());
    cout << ans[0] << '\n';

}