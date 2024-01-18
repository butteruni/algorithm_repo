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
        string a,b;
        cin >> a >> b;
        bool ok = 1;
        for(int i = 0;i < n - 1;++i)
        {
            if(a[i] == a[i + 1])
                ok = 0;
        }
        if(ok)
        {
            cout << "Yes\n";
            continue;
        }
        ok = 1;
        for(int i = 0;i < m - 1;++i)
        {
            if(b[i] == b[i + 1])
                ok = 0;
        }
        if(!ok)
        {
            cout << "No\n";
            continue;
        }
        ok = 1;
        for(int i = 0;i < n - 1;++i)
        {
            if(a[i] == a[i + 1])
            {
                if(a[i] == b[0])
                {
                    ok = 0;
                }
                if(a[i + 1] == b[m - 1])
                {
                    ok = 0;
                }
            }
        }
        if(ok)
        {
            cout << "Yes\n";
        }else 
        {
            cout << "No\n";
        }
    }
}