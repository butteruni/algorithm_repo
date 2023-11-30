#include <bits/stdc++.h>

using namespace std;
const int N = 5e4 + 10;
int cnt;
bool vis[N];
int pri[N], phi[N];

void init()
{
	vis[1] = 1;
	for (int i = 2; i < N; i++)
	{
		if (!vis[i])
		{
			pri[++cnt] = i;
			phi[i] = i - 1;
		}
		for (int j = 1; j <= cnt; j++)
		{
			if (1ll * i * pri[j] >= N)
				break;
			vis[i * pri[j]] = 1;
			if (i % pri[j] == 0)
			{
				phi[i * pri[j]] = phi[i] * pri[j];
				break;
			}
			phi[i * pri[j]] = phi[i] * (pri[j] - 1);
		}
	}
}
int main()
{
	std::ios::sync_with_stdio(false);

	return;
}