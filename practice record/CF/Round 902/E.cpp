#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    vector<ll>a(n + 1);
    vector<ll>cnt(n + 1);
    vector<bool>un_cir(n + 1);
    queue<int>q;
    for(int i = 1;i <= n;++i)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for(int i = 1;i <= n;++i)
    {
        if(cnt[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int>ans;
    while(q.size())
    {
        int tmp = q.front();
        q.pop();
        un_cir[tmp] = 1;
        ans.push_back(tmp);
        if(!un_cir[a[tmp]] && --cnt[a[a[tmp]]] == 0)
        {
            q.push(a[a[tmp]]);
        }
        un_cir[a[tmp]] = 1;
    }
    bool ok = 1;
    vector<bool>vis(n + 1);
    for(int i = 1;i <= n;++i)
    {
        if(un_cir[i])
            continue;
        vector<int>circle;
        for(int ne = i;!un_cir[ne];ne = a[ne])
        {
            circle.push_back(ne);
            un_cir[ne] = 1;
        }
        if(circle.size() & 1)
        {
            ok = 0;
            break;
        }
        for(int j = 0;j < circle.size();j += 2)
        {
            ans.push_back(circle[j]);
        }
    }
    if(!ok)
    {
        cout << -1 << '\n';
    }else 
    {
        cout << ans.size() << '\n';
        sort(ans.begin(),ans.end());
        for(auto x:ans)
        {
            // cout << x << " ";
            cout << a[x] << " ";
        }
        cout << '\n';
    }
}