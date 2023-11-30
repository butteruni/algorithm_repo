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
    ll ans = 0;
    vector<int>pos;
    for(int i = 0;i < n;++i)
    {
        cin >> a[i];
        ans = max(ans,a[i]);
    }
    sort(a.begin(),a.end());
    if(n >= 2)
        ans = max(ans,a[n - 1] + a[n - 2]);
    cout << ans << "\n";
}