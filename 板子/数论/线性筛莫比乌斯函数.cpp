#include <bits/stdc++.h>
typedef long long ll;
const int N = 5e4 + 10;
ll pri[N],mu[N],phi[N]; //mu[i] = μ(i) 
bool vis[N];
int cnt;
void init()
{
    vis[1] = 1;
    mu[1] = 1;
    for(int i = 2;i<N;i++) 
    {
        if(!vis[i])//如果没有被筛过就是质数
        {
            pri[++cnt]=i;
            mu[i] = -1; 
            phi[i] = i - 1;
        }
        for(int j = 1;j <= cnt;j++) 
        {
            if(1ll * i * pri[j] >= N)
                break;
            vis[i * pri[j]] = 1;
            if(i % pri[j] == 0) 
            {
                mu[i * pri[j]] = 0;
                phi[i * pri[j]] = phi[i] * pri[j];
                break;
            }
            mu[i * pri[j]] = -mu[i];
            phi[i * pri[j]] = phi[i] * (pri[j] - 1);
        }
    }
}