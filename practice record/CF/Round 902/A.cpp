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
        vector<int>a(n);
        ll sum = 0;
        for(int i = 0;i < n - 1;++i)
        {
            cin >> a[i];
            sum += a[i];
        }
        cout << -sum << '\n';
    }
}