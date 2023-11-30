//卡unsigned long long (抽象)
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull n,ans;
int prime[16] = {2,3,5,7,11,13,17,19,23,29,31,37,41,47,53};
void dfs(ull idx,ull sum,ull num,ull pre_cnt)
{
    if(num > n || idx >= 16 || sum >= ans)
        return ;
    if(num == n)
    {
        ans = sum;
        return;
    }
    if(sum * prime[idx] > ans)
    {
        return;
    }
    for(int i = 1;i <= pre_cnt;++i)
    {
        dfs(idx + 1,sum *= prime[idx],num * (i + 1),i);
    }
}
int main()
{
    ans = 1e18;
    cin >> n;
    dfs(0,1,1,log2(1e18));
    // cout << log2(1e18) << endl;
    cout << ans << endl;
}