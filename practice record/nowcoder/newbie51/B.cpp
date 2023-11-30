#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    vector<ll>a(n);
    vector<int>pos;
    ll ans = 0;
    for(int i = 0;i < n;++i)
    {
        cin >> a[i];
        if(a[i] == 0)
        {
            if(i == 0)
                a[i] = 1;
            else 
                a[i] = a[i - 1] + 1;
        }
        ans += a[i];
    }
    bool ok = 1;
    for(int i = 1;i < n;++i)
    {
        if(a[i] <= a[i - 1])
            ok = 0;
    }
    if(!ok)
    {
        cout << -1 << '\n';
    }else 
        cout << ans << '\n';
}