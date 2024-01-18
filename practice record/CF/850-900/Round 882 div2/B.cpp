#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int n,t;
ll a[N];
ll mins = 0;
int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1;i <= n;++i)
        {
            cin >> a[i];
        }
        mins = a[1];
        for(int i = 2;i <= n;++i)
            mins &= a[i];
        if(mins != 0)
        {
            cout << 1 << '\n';
        }else 
        {
            int cnt = 0;
            ll temp = a[1];
            for(int i = 2;i <= n;++i)
            {
                if(temp == 0)
                {
                    cnt++;
                    temp = a[i];
                }else 
                    temp &= a[i];
            }
            if(temp == 0)
                cnt++;
            cout << cnt << endl;
        }
    }
}