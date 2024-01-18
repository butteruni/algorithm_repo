#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PII;
const int N = 1e5 + 10;
int cmp(PII a,PII b)
{
    if(a.first != b.first) 
        return a.first > b.first;
    else 
        return a.second < b.second;
}
void solve()
{
    int n;
    cin >> n;
    vector<PII> a(n) , b(n) , c(n);
    for(int i = 1; i <= n ; i ++)
    {
        int x;
        cin >> x;
        a.push_back({x , i});
    }
    for(int i = 1; i <= n ; i ++)
    {
        int x;
        cin >> x;
        b.push_back({x , i});
    }
    for(int i = 1; i <= n ; i ++)
    {
        int x;
        cin >> x;
        c.push_back({x , i});
    }
    sort(a.begin() , a.end() , cmp);
    sort(b.begin() , b.end() , cmp);
    sort(c.begin() , c.end() , cmp);
    
    ll res = 0;
    
    for(int i = 0 ; i < 3 ; i ++)
        for(int j = 0 ; j < 3 ; j ++)
            for(int k = 0; k < 3 ; k ++)
                if(a[i].second != b[j].second && a[i].second != c[k].second && c[k].second != b[j].second)
                    res = max(res , a[i].first + b[j].first + c[k].first);
                
    cout << res << endl;
    
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}