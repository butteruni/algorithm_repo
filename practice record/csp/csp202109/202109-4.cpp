#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef double db;
const int N = (1 << 17) + 10;
db p[20];
int cnt[N];
db dp[100][N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i = 0;i < n;++i)
        cin >> p[i];
    for(int i = 0;i < (1 << n);++i)
    {
        int x = i;
        while(x)
        {
            cnt[i]++;
            x &= (x - 1);
        }
    }
    // cout << cnt[3] << endl;
    dp[0][0] = 1;
    db ans = 0;
    for(int i = 0;i < (1 << n);i++) //当前已抽出的卡片集合
    {
        for(int j = cnt[i];j <= 80;j++) //可能操作数
        {
            if(cnt[i] + (j - cnt[i]) / k == n) //当前已经能换到n个卡
            {
                ans += j * dp[j][i];
                continue;
            }
            for(int _ = 0;_ < n;_++)
            {
                if(i & (1 << _)) //_已被抽出过
                    dp[j + 1][i] += dp[j][i] * p[_];
                else //_未被抽出过 
                    dp[j + 1][i + (1 << _)] += dp[j][i] * p[_];
            }
        }
    }
    // cout << ans << endl;
    printf("%lf\n",ans);
}   