#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
int t;
ll n,m;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        if(m >= n)
        {
            cout << -1 << '\n';
        }else 
        {
            ll mins = n - m;
            ll b = n - m;
            if(b <= m)
                cout << -1 << '\n';
            else 
            {
                ll a = m;
                cout << a << " " << b << '\n';
            }
        }
    }
}