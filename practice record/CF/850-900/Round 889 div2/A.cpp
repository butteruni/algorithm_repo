#include <bits/stdc++.h>
using namespace std;
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
        cin >> n;
        int cnt = 0;
        for(int i = 1;i <= n;++i)
        {
            cin >> a[i];
            if(a[i] == i)
                cnt++;
        }
        int ans = 0;
        if(cnt == 1)
        {
            ans = 1;
        }else if(cnt > 1)
            ans = (cnt + 1) / 2;
        cout << ans << '\n';
    }
}