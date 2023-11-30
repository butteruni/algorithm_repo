#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int ans[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m,x;
    cin >> n >> m >> x;
    if((n + m) % 2 || x / 2 > min(n,m))
    {
        cout << "-1" << '\n';
    }else 
    {
        int xx = x / 2;
        n -= x,m -= x;
        if(n % 2 == 1 || m % 2 == 1)
            cout << "-1" << '\n';
        else 
        {
            for(int i = 1;i <= n;++i)
            {
                cout << "0";
            }
            for(int i = 1;i <= xx;++i)
            {
                cout << "01";
            }
            for(int i = 1;i <= m;++i)
            {
                cout << "1";
            }
        }
    }
}