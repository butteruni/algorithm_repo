#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
typedef pair<ll,ll>PLL;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    vector<PLL>p;
    for(int i = 0;i < n;++i)
    {
        ll t,d;
        cin >> t >> d;
        p.push_back(make_pair(t,t + d));
    }
    sort(p.begin(),p.end());
    priority_queue<ll,vector<ll>,greater<> > q;
    int ans = 0;
    int cur = 0;
    for(ll i = 0;;i++)
    {
        if(q.empty())
        {
            if(cur == n)
                break;
            i = p[cur].first;
        }
        while(cur < n && p[cur].first == i)
        {
            q.push(p[cur].second);
            cur++;
        }
        while(!q.empty() && q.top() < i)
        {
            q.pop();
        }
        if(!q.empty())
        {
            q.pop();
            ans++;
        }
    }
    cout << ans << '\n';

}