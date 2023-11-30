#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<ll>a(n);
        ll sum = 0;
        for(int i = 0;i < n;++i)
        {
            cin >> a[i];
            sum += a[i];
        }
        sort(a.begin(),a.end());
        sum -= a[0];
        sum -= a[n - 1];
        if(a[n - 1] != a[1])
        {
            sum++;
        }
        cout << sum << '\n';
    }
}