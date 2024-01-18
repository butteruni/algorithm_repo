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
        vector<ll>a(n);
        for(int i = 0;i < n;++i)
        {
            cin >> a[i];
        }
        vector<ll>b(n);
        for(int i = 0;i < n;++i)
        {
            cin >> b[i];
        }
        if(is_sorted(a.begin(),a.end()))
        {
            cout << 1 << " " << n << "\n";
        }else 
        {
            int l = 0,r = n - 1;
            while(a[l] == b[l])
            {
                l++;
            }
            while(a[l - 1] <= b[l] && l - 1 >= 0)
            {
                l--;
            }
            while(a[r] == b[r])
            {
                r--;
            }
            while(a[r + 1] >= b[r] && r + 1 <= n - 1)
            {
                r++;
            }
            cout << l + 1 << " " << r + 1 << '\n';
        }
    }
}