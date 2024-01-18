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
        int n,q;
        cin >> n >> q;
        for(int i = 1;i < n;++i)
        {
            cout << i << " " << i + 1 << '\n';
        }
        int ed = n - 1;
        for(int i = 1;i <= q;++i)
        {
            int x;
            cin >> x;
            if(x != ed)
            {
                cout << n << " " << ed << " " << x << '\n';
                ed = x;
            }else 
            {
                cout << -1 << " " << -1 << " " << -1 << '\n'; 
            }
        }
    }
}