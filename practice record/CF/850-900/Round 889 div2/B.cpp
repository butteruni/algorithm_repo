#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        ll ans = 0;
        for(ll i = 1;i  <= n;++i)
        {
            if(n % i == 0)
            {
                ans++;
            }
            else 
            {
                break;
            }
        }
        cout << ans << '\n';
    }
}