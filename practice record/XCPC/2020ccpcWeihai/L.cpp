#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 3e4 + 10;
const int nn = 3500;
int cnt;
bool vis[N];
int pri[N];
double dp[nn][N];
double add[nn];
void init()
{
    vis[1]=1;
    for(int i=2;i<=N;i++) 
    {
        if(!vis[i])//如果没有被筛过就是质数
        {
            pri[++cnt]=i;
        }
        for(int j=1;j<=cnt;j++) 
        {
            if(1ll*i*pri[j]>N)break;
            vis[i*pri[j]]=1;
            if(i%pri[j]==0) 
            {
                break;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    init();
    for(int i = 1;i <= cnt;++i)
    {
        add[i] = log(pri[i]);
    }
    int T;
    for(int i = 1;i <= cnt;++i)
    {
        int gap = pri[i];
        double w = add[i];
        for(int j = 1;j <= 30000;++j)
        {
            gap = pri[i];
            w = add[i];
            dp[i][j] = dp[i - 1][j];
            while(j - gap >= 0)
            {
                dp[i][j] = max(dp[i][j],dp[i - 1][j - gap] + w);
                gap *= pri[i];
                w += add[i];
            }
        }
    }
    cin >> T;
    while(T--)  
    {
        int n;
        cin >> n;
        cout << fixed << setprecision(9) << dp[cnt][n] << '\n';
    }
}