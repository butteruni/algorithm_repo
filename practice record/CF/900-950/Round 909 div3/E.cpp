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
        vector<ll>b(n);
        ll mn = 1e18;
        for(int i = 0;i < n;++i)
        {
            cin >> a[i];
            b[i] = a[i];
        }   
        sort(b.begin(),b.end());
        mn = b[0];
        int st = 0;
        while(a[st] != mn)
            st++;
        bool ok = 1;
        for(int i = st + 1;i < n;++i)
        {
            if(a[i] < a[i - 1])
                ok = 0;
        }
        if(!ok)
        {
            cout << "-1" <<'\n';
        }else 
        {
            cout << st << '\n';
        }
    }
}