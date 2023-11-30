#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int t;
int n;
int a[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--)
    {
        // cout << "--" << endl;
        cin >> n;
        for(int i = 1;i <= n;++i)
            cin >> a[i];
        sort(a + 1,a + 1 + n);
        ll ans =  0;
        for(int i = 1;i <= n / 2;++i)
        {
            ans += a[n - i + 1] - a[i];
        }
        cout << ans << '\n';
    }
}