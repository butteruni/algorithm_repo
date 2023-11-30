#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
const ll mod = 998244353;
ll a[N];
int t,n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n;
        ll x = 0;
        for(int i = 1;i <= n;++i)
        {
            cin >> a[i];
        }
        bool change_1 = 0;
        bool change_2 = 0;
        for(int i = 1;i <= n;++i)
        {
            if(!change_1)
            {
                x = (x + a[i]);
            }else 
            {
                if(a[i] <= 1)
                {
                    x = (x + a[i]);
                }else 
                {
                    x = x * a[i];
                }
            }
            if(x > 1)
                change_1 = 1;
            if(x > mod)
            {
                x %= mod;
            }
            
        }
        cout << (x % mod) << endl;
    }
}