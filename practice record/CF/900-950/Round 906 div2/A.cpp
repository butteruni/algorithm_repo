#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1010;
ll a[N];
ll b[N];
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
        for(int i = 1;i <= n;++i)
        {
            cin >> a[i];
        }
        sort(a + 1,a + 1 + n);
        int l = 1,r = n;
        bool ok = 0;
        for(int i = 1;i <= n;++i)
        {
            if(i & 1)
            {
                b[i] = a[l];
                l++;
            }else 
            {
                b[i] = a[r];
                r--;
            }
        }
        // ok = 1;
        int st = 1;
        while(b[st] + b[st + 1] == b[st + 1] + b[st + 2] && st + 2 <=n)
        {
            st++;
        }
        if(st == n - 1)
            ok = 1;
        l = 1,r = n;
        for(int i = 1;i <= n;++i)
        {
            if(i % 2 == 0)
            {
                b[i] = a[l];
                l++;
            }else 
            {
                b[i] = a[r];
                r--;
            }
        }
        // ok = 1;
        st = 1;
        while(b[st] + b[st + 1] == b[st + 1] + b[st + 2] && st + 2 <=n)
        {
            st++;
        }
        if(st == n - 1)
            ok = 1;
        if(ok)
        {
            cout << "Yes\n";
        }else 
        {
            cout << "No\n";
        }
    }
}