// 4s 可以冲 n \sqrt(n) n = 2e5;
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PLL;
const int N = 2e5 + 10;
PLL a[N];
int cnt[N];
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
        for(int i = 1;i <= n;++i)  
        {
            cin >> a[i].first;
        }
        for(int i = 1;i <= n;++i)
        {
            cin >> a[i].second;
        }
        sort(a + 1,a + 1 + n);
        ll ans = 0;
        for(int i = 1;i * i <= 2ll * n;++i) //枚举a_i的值
        {
            memset(cnt,0,sizeof(cnt));

            for(int j = 1;j <= n;++j)
            {
                int res = a[j].first * i - a[j].second;
                if(res >= 1 && res <= n)
                {
                    ans += cnt[res];
                }
                if(a[j].first == i)
                    cnt[a[j].second]++;
            }
        }
        cout << ans << '\n';
    }
}