#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll n,m;
        cin >> n >> m;
        vector<ll>a(n);
        vector<ll>b(m);
        vector<ll>c(n + m);
        for(auto &x:a)
            cin >> x;
        for(auto &x : b)
            cin >> x;
        sort(b.begin(),b.end(),greater<>());
        merge(a.begin(),a.end(),b.begin(),b.end(),c.begin(),greater<>());
        for(auto x:c)
        {
            cout << x << " ";
        }
        cout << '\n';

    }
}