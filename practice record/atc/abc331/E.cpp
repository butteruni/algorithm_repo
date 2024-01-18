#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const ll N = 1e5 + 10;
ll a[N],b[N];
int id_b[N];
ll step[N];
map<pair<int,int>,int>mp;
bool cmp(int x,int y)
{
    return b[x] > b[y];
}
 
void solve()
{
    int n,m,l;
    cin >> n >> m >> l;
    for(int i = 1;i <= n;++i)
    {    
        cin >> a[i];
        step[i] = 1;
    }
    for(int i = 1;i <= m;++i)
    {
        cin >> b[i];
        id_b[i] = i;
    }
    sort(id_b + 1,id_b + 1 + m,cmp);
    for(int i = 1;i <= l;++i)
    {
        int c,d;
        cin >> c >> d;
        mp[make_pair(c,d)] = 1;
    }
    priority_queue<pair<int, int>> q;
    for(int i = 1;i <= n;++i)
    {
        q.push(make_pair(a[i] + b[id_b[step[i]]],i));
    }
    while(q.size())
    {
        auto cur = q.top();
        q.pop();
        int b_id = id_b[step[cur.second]];
        // cout << cur.first << " ";
        if(!mp.count(make_pair(cur.second,b_id)))
        {
            cout << cur.first << '\n';
            return;
        }
        if(step[cur.second] < m)
        {
            step[cur.second]++;
            q.push(make_pair(a[cur.second] + b[id_b[step[cur.second]]],cur.second));
        }
    }

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
}