#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int N = 1e5 + 10;
priority_queue<PII> q[7];
int n, k;
int v[7];
int a[N][7];
int b[N][7];
void clear(priority_queue<PII> &Q)
{
	priority_queue<PII> tmp;
	swap(tmp, Q);
}
int cnt;
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&k);
		cnt = 0;
		for (int i = 1; i <= k; i++)
		{
			scanf("%d",&v[i]);
			clear(q[i]);
		}
		clear(q[k + 1]);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= k; j++)
			{
				scanf("%d",&a[i][j]);
			}
			for (int j = 1; j <= k; j++)
			{
				scanf("%d",&b[i][j]);
			}
			q[1].push({-a[i][1], i});
		}
		while (true)
		{
			for (int i = 1; i <= k; i++)
			{
				while (!q[i].empty())
				{
					auto u = q[i].top();
					int val = -u.x;
					int id = u.y;
					if (val <= v[i])
					{
						q[i].pop();
						q[i + 1].push({-a[id][i + 1], id});
					}
					else
						break;
				}
			}
			if (q[k + 1].empty())
				break;
			while (!q[k + 1].empty())
			{
				cnt++;
				auto u = q[k + 1].top();
				q[k + 1].pop();
				int id = u.y;
				for (int i = 1; i <= k; i++)
				{
					v[i] += b[id][i];
				}
			}
		}
		printf("%d\n",cnt);
		for (int i = 1; i <= k; i++)
		{
			printf("%d ",v[i]);
		}
		printf("\n");
	}
	return 0;
}