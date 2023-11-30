#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
ll a[N];
ll dp[N]; // 表示以[u] 为根的子树最大能造成的贡献
// 删成只有一个子树的点可以在第二步被压缩，有多个子树的不行
vector<int>e[N];
ll ans;
void dfs(int u,int pa)
{
    ans = max(ans,a[u]);
    dp[u] = a[u];
    vector<ll>d1,d2;
    for(auto x:e[u])
    {
        if(x == pa)
            continue;
        dfs(x,u);
        if(dp[x] < 0)
            d1.push_back(dp[x]); 
        else 
            d2.push_back(dp[x]);
    }
    sort(d1.begin(),d1.end());
    sort(d2.begin(),d2.end());
    if(!d2.empty()) // 存在权值大于0的子树
    {
        dp[u] = max(dp[u],d2.back());
        ans = max(ans,a[u] + d2.back());
    }
    if(!d1.empty()) // 存在权值小于0的子树
    {
        dp[u] = max(dp[u],d1.back());
        ans = max(ans,a[u] + d1.back());
    }
    if(d2.size() > 1) // 存在多个权值大于0的子树
    {
        ll sum = a[u];
        for(auto x:d2)
            sum += x;
        dp[u] = max(dp[u],sum);
        ans = max(ans,d2.back() + d2[d2.size() - 2]); // 删成只剩两个子树
        if(d2.size() > 2)
            ans = max(ans,sum);
    }
    if(d1.size() && d2.size() == 2) // 保留u的情况
    {
        ans = max(ans,d2.back() + d2[d2.size() - 2] + d1.back() + a[u]);
    }
    if(d1.size() && d2.size() == 1)
    {
        dp[u] = max(dp[u],a[u] + d1.back() + d2.back());
        ans = max(ans,d1.back() + d2.back());
    }
}
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
        ans = 0;
        for(int i = 1;i <= n;++i)
        {
            cin >> a[i];
            e[i].clear();
            // in[i] = 0;
            dp[i] = 0;
        }
        for(int i = 1;i < n;++i)
        {
            int u,v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
            // in[u]++,in[v]++;
        }
        dfs(1,-1);
        cout << ans << '\n';
    }
}