#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 200010;
int c[N];
set<int>diff[N];
ll fa[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,q;
    cin >> n >> q;
    for(int i = 1;i <= n;++i)
    {

        cin >> c[i];
        diff[i].insert(c[i]);
    }
    for(int i = 1;i <= q;++i)
    {
        int a,b;
        cin >> a >> b;
        if(diff[a].size() > diff[b].size())
        {
            swap(diff[a],diff[b]);
        }
        for(auto x:diff[a])
        {
            diff[b].insert(x);
        }
        diff[a].clear();
        cout << diff[b].size() << '\n';
    }
    
}