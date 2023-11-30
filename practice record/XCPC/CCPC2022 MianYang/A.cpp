#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int N = 1e5 + 10;
const ll inf = 1e9;
ll a[N],b[N];
ll dp[2 * N][15][15];
int n,k;
bool cmp(ll x,ll y)
{
    return x > y;
}
void init()
{
    for(int i = 0;i <= 2 * n;++i)
    {
        for(int j = 0;j <= k;++j)
        {
            for(int jj = 0;jj <= k;++jj)
            {
                dp[i][j][jj] = -inf;
            }
        }
    }
}
ll dfs(int round,int cnt_a,int cnt_b)
{
    if(round == 2 * n)
        return 0;
    if(dp[round][cnt_a][cnt_b] != -inf)
        return dp[round][cnt_a][cnt_b];
    int cur_a = round / 2 - cnt_b + cnt_a;
    int cur_b = (round + 1) / 2 - cnt_a + cnt_b;
    if(round % 2 == 1) // b 行动
    {
        ll ans = inf;
        if(cnt_b < k && cur_b < n)// b还能再选
            ans = min(ans,dfs(round + 1,cnt_a,cnt_b + 1) - b[cur_b + 1]);
        ans = min(ans,dfs(round + 1,cnt_a,cnt_b));// 删 a
        return dp[round][cnt_a][cnt_b] = ans;
    }else 
    {
        ll ans = -inf;
        if(cnt_a < k && cur_a < n) // a还能再选
            ans = max(ans,dfs(round + 1,cnt_a + 1,cnt_b) + a[cur_a + 1]);
        ans = max(ans,dfs(round + 1,cnt_a,cnt_b));// 删 b
        return dp[round][cnt_a][cnt_b] = ans;
    }
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;++i)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= n;++i)
    {
        cin >> b[i];
    }
    sort(a + 1,a + 1 + n,cmp);
    sort(b + 1,b + 1 + n,cmp);
    init();
    cout << dfs(0,0,0) << '\n';
}   