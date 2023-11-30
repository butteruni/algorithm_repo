#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 +10;
bool vis[N];
int n,k,m;
int t[N],c[N];
bool st[N];
int q;
long long l[N],r[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1;i <= n;++i)
    {
        cin >> t[i] >> c[i];
        if(k > t[i])
            continue;
        l[max(0,t[i] - c[i] - k + 1)]++;
        r[t[i] - k + 1]++;
    }
    for(int i = 1;i < 2e5 + 10;++i)
    {
        l[i] += l[i - 1];
        r[i] += r[i - 1];
    }
    for(int i = 1;i <= m;++i)
    {
        cin >> q;
        cout << l[q] - r[q] << '\n';
    }


}