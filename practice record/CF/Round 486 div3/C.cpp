#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
map<ll,vector<PII>> mp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    vector<vector<ll>>a(t);
    for(int i = 0;i < t;++i)
    {
        int n;
        cin >> n;
        a[i].resize(n);
        ll sum = 0;
        for(int j = 0;j < n;++j)
        {
            cin >> a[i][j];
            sum += a[i][j];
        }
        for(int j = 0;j < n;++j)
        {
            a[i][j] = sum - a[i][j];
            if(!mp.count(a[i][j]) || mp[a[i][j]].back().first != i + 1)
                mp[a[i][j]].push_back(make_pair(i + 1,j + 1));
        }
        // sort(a[i].begin(),a[i].end());
    }
    bool ok = 0;
    for(auto [x,val]:mp)
    {
        if(val.size() >= 2)
        {
            ok = 1;
            cout << "YES\n";
            cout << val[0].first << " " << val[0].second << "\n";
            cout << val[1].first << " " << val[1].second << "\n";
            break;
        }
    }
    if(!ok)
    {
        cout << "NO\n";
    }
}