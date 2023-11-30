#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e6 + 10;
int cnt;
bool vis[MAXN];
int pri[MAXN];

void init()
{
    vis[1] = 1;
    for (int i = 2; i < MAXN; i++)
    {
        if (!vis[i]) // 如果没有被筛过就是质数
        {
            pri[++cnt] = i;
        }
        for (int j = 1; j <= cnt; j++)
        {
            if (1ll * i * pri[j] >= MAXN)
                break;
            vis[i * pri[j]] = 1;
            if (i % pri[j] == 0)
            {
                break;
            }
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);

    return;
}