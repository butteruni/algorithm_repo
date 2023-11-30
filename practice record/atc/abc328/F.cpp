#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
ll a[N],b[N],d[N];
ll f[N],dis[N];
ll find(int x)
{
    if(x != f[x])
    {
        ll fx = f[x];
        f[fx] = find(f[x]);
        dis[x] += dis[fx];
        f[x] = f[fx];
    }
    return f[x];
}
void merge(int x,int y,ll w)
{
    ll fx = find(x),fy = find(y);
    f[fx] = fy;
    dis[fx] = w - dis[x] + dis[y];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,q;
    cin >> n >> q;
    for(int i = 1;i <= q;++i)
    {
        cin >> a[i] >> b[i] >> d[i];
    }
    vector<int>s;
    for(int i = 1;i <= n;++i)
    {
        f[i] = i;
    }
    for(int i = 1;i <= q;++i)
    {
        if(find(a[i]) == find(b[i]))
        {
            if(dis[a[i]] - dis[b[i]] == d[i])
            {
                s.push_back(i);
            }
        }else 
        {
            merge(a[i],b[i],d[i]);
            s.push_back(i);
        }
    }
    for(int i = 0;i < s.size();++i)
        cout << s[i] << " ";
    // cout << '\n';
}