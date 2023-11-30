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
        int n;
        cin >> n;
        vector<int>a(n);
        for(auto &x:a)
            cin >> x;
        bool ok = 1;
        if(n  == 2)
        {
            if(is_sorted(a.begin(),a.end()))
            {
                cout << "YES\n";
            }else 
            {
                cout << "NO\n";
            }
        }
        if(a[0] != 1)
            ok = 0;
        for(int i = 1;i < n - 1;++i)
        {
            if(a[i] > a[i + 1])
            {
                if(a[i] > a[i - 1])
                {
                    swap(a[i],a[i + 1]);
                }else 
                {
                    ok = 0;
                    break;
                }
            }
        }
        if(!ok)
        {
            cout << "NO\n";
        }else 
        {
            cout << "YES\n";
        }
    }

}