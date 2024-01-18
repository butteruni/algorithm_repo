#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ll pre_mx = -1;
        ll st;
        ll pre_mn = 1e10;
        ll pre = 0;
        bool cnt = 1;
        for(int i = 1;i <= n;++i)
        {
            bool added = 0;
            ll x;
            cin >> x;
            if(i == 1)
                st = x;
            if(cnt)
            {
                if(x >= pre)
                {
                    added = 1;
                }else if(x <= st)
                {
                    added = 1;
                    cnt -= 1;
                }
            }else 
            {
                if(x <= st && x >= pre)
                {
                    added = 1;
                }
            }
            if(added)
            {
                pre = x;
                cout << 1;
            }
            else  
            {
                cout << 0;
            }  

        }
        cout << "\n";
    }
}