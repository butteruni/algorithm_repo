#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int N = 1e5 + 10;
struct Edge
{
	int u, v, w, next;
} e[N << 2];
int head[N], dist[N], cnt;
int n, m;
queue<int> q;
bool vis[N];
void add(int u, int v, int w)
{
	++cnt;
	e[cnt].u = u;
	e[cnt].v = v;
	e[cnt].w = w;
	e[cnt].next = head[u];
	head[u] = cnt;
	return;
}

void dfs(int u, int uw)
{
	for (int i = head[u]; ~i; i = e[i].next)
	{
		int v = e[i].v, w = e[i].w;
		if (!vis[v] && uw == w)
		{
			dist[v] = dist[u];
			vis[v] = 1;
			q.push(v);
			dfs(v, uw);
		}
	}
}

void bfs()
{
	q.push(1);
	vis[1] = 1;
	dist[1] = 0;
	while (!q.empty())
	{
		auto u = q.front();
		q.pop();
		for (int i = head[u]; ~i; i = e[i].next)
		{
			int v = e[i].v, w = e[i].w;
			if (vis[v])
				continue;
			vis[v] = 1;
			dist[v] = dist[u] + 1;
			q.push(v);
			dfs(v, w);
		}
		if (dist[n] != 0x3f3f3f3f)
			break;
	}
}

void clear(queue<int> &Q)
{
	queue<int> tmp;
	swap(tmp, Q);
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while (cin >> n >> m)
	{
		cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			head[i] = -1;
			dist[i] = 0x3f3f3f3f;
			vis[i] = false;
		}
		clear(q);
		for (int i = 1; i <= m; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			add(a, b, c);
			add(b, a, c);
		}
		bfs();
		if (dist[n] == 0x3f3f3f3f)
			cout << -1 << "\n";
		else
			cout << dist[n] << "\n";
	}
	return 0;
}