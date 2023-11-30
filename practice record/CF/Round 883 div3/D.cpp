#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int t,n;
double d,h;
ll y[N]; 
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n >> d >> h;
        for(int i = 1;i <= n;++i)
            cin >> y[i];
        double ans = 0;
        for(int i = 1;i <= n;++i)
        {
            if(y[i + 1] - y[i] >= h || i == n)
            {
                ans += d * h / 2;
            }else 
            {
                double temp_h = y[i + 1] - y[i];
                double upper = (1.0 - temp_h / h) * d;
                // cout << upper << " ";
                ans += (upper + d) / 2 * temp_h; 
                // cout << ans << " ";
            }
        }
        printf("%lf\n",ans);
    }
}