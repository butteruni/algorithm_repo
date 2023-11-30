#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef long long ll;
int a[N],id[N];
int n,m;
ll ans;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    ll pre = -1;
    for(int i = 1;i <= n;++i)
    {
        ll x;
        cin >> x;
        if(pre == -1)
        {
            pre = x;
            continue;
        }else 
        {
            ans += (i - 1) * (x - pre);
            pre = x; 
        }
        // cout << ans << endl;
    }
    ans += (m - pre) * n ;
    cout << ans << endl;
}