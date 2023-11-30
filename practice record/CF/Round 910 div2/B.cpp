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
            cin >> a[i];
        int ed = n - 1;
        while(ed > 1 && a[ed - 1] <= a[ed])
            ed--;
        ll sum = 0;
        for(int i = ed - 1;i >= 0;--i)
        {
            if(a[i] <= a[i + 1])
                continue;
            ll cnt = a[i] / a[i + 1];
            sum += cnt;
            if(a[i] % a[i + 1] == 0)
            {   
                sum--;
                a[i] = a[i + 1];
            }else 
            {
                a[i]  /= cnt + 1;
            }

        }
        cout << sum << '\n';
    }
}