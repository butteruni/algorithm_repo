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
        int n,m;
        cin >> n >> m;
        vector<ll>a(n);
        vector<ll>b(m);
        for(auto &x : a)
            cin >> x;
        for(auto x : b)
        {
            cin >> x;
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int la = 0,ra = n - 1;
        int lb = 0,rb = m - 1;
        
    }
}