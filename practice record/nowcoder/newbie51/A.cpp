#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    ll n;
    cin >> n;
    if(n & 1)
    {
        ll ans = n - 2;
        cout << 2 << " " << ans - 2 << '\n';
    }else 
    {
        ll ans = n - 1;
        cout << 2 << ' ' << ans - 2 << '\n';
    }

}