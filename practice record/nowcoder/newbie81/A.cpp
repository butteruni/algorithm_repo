#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,x;
    cin >> n >> x;
    vector<int>a(n);
    int ans = 0;
    for(int i = 0;i < n;++i)
    {
        cin >> a[i];
        if(a[i] < x)
            ans += a[i];
    }
    cout << ans << '\n';

}