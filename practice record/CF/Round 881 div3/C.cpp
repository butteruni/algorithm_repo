#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int t;
ll n;
ll ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        ans = 0;
        ans += n;
        while(n)
        {
            ans += n / 2;
            n /= 2;
        }
        cout << ans << endl;
    }
}