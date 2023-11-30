#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,int>mp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    vector<ll>a(n);
    for(int i = 0;i < n;++i)
    {
        cin >> a[i];
        mp[a[i]] = i;
    }
    sort(a.begin(),a.end());
    vector<ll>ans;
    ans.push_back(a[0]);

    for(ll d = 0;d <= 31;++d)
    {
        vector<bool>vis(n,0);
        ll gap = 1ll << d;
        for(int i = 0;i < n;++i)
        {
            if(vis[i])
                continue;
            else 
            {
                ll st = a[i];
                vis[i] = 1;
                vector<ll>cur_ans;
                cur_ans.push_back(st);
                while(mp.count(st + gap) && cur_ans.size() < 3)
                {
                    st += gap;
                    cur_ans.push_back(st);
                    vis[mp[st]] = 1;
                }
                if(cur_ans.size() > ans.size())
                {
                    ans = cur_ans;
                }
            }
        }
    }
    cout << ans.size() << '\n';
    for(auto x:ans)
    {
        cout << x << " ";
    }
    cout << "\n";


}