#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<ll>a(n + 1);
        a[0] = 0;
        for(int i = 1;i <= n;++i)
        {
            cin >> a[i];
        }
        for(int i = 1;i <=n;++i)
        {
            a[i] += a[i - 1];
        }
        int l = 1,r = n;
        while(1)
        {
            if(l == r)
            {
                cout << "!" << " " << l << endl;
                break;
            }
            ll mid = (l + r) >> 1;
            ll sz = (mid - l + 1);
            cout << "? ";
            cout << sz << " ";
            for(int i = l;i <= mid;++i)
            {
                cout << i << " ";
            }
            cout << endl;
            ll sum;
            cin >> sum;
            if(sum == a[mid] - a[l - 1])
            {
                l = mid + 1;
            }else 
            {
                r = mid;
            }
        }
    }
}