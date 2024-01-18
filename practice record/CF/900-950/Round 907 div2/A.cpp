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
        vector<int>c(n + 1);
        for(int i = 1;i <= n;++i)
            cin >> c[i];
        ll st = 0;
        while((1 << st) <= n)
            st++;
        st --;
        bool ok = 1;
        for(int i = (1 << st) + 1;i < n;++i)
        {
            if(c[i] > c[i + 1])
                ok = 0;
        }
        while(st)
        {
            for(int i = (1 << (st - 1)) + 1;i < (1 << st) ;++i)
            {
                if(c[i] > c[i + 1])
                    
                    ok = 0;
            }
            st --;
        }
        if(!ok)
            cout << "No\n";
        else    
            cout << "Yes\n";
        
    }
}