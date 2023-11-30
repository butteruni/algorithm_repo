#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 10;
int n;
ll x;
ll a[N],b[N],c[N];
bool l(ll a ,ll b)
{
    ll temp = 1;
    while(temp <= a)
    {
        if((a & temp) && !(b & temp))
            return false;
        temp *= 2;
    }
    return true;
}
int t;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    // cout << l(1,0) << endl;
    while(t--)
    {
        cin >> n >> x;
        // cout << x << '\n';
        int mx_a = n,mx_b = n,mx_c = n;
        for(int i = 1;i <= n;++i) 
        {
            cin >> a[i];
            if(!l(a[i],x) && mx_a == n)
            {
                mx_a = i - 1;
            }
        }  
        for(int i = 1;i <= n;++i)
        {
            cin >> b[i];
            if(!l(b[i],x) && mx_b == n)
            {
                mx_b = i - 1;
            }
        }
        for(int i = 1;i <= n;++i)
        {
            cin >> c[i];
            if(!l(c[i],x) && mx_c == n)
            {
                mx_c = i - 1;
            }
        }
        ll ans = 0;
        bool check = 0;
        if(ans == x)
            check = 1;
        for(int i = 1;i <= mx_a;++i)
        {
            ans |= a[i];
            if(ans == x)
                check = 1;
        }
        for(int i = 1;i <= mx_b;++i)
        {
            ans |= b[i];
            if(ans == x)
                check = 1;
        }
        for(int i = 1;i <= mx_c;++i)
        {
            ans |= c[i];
            if(ans == x)
                check = 1;
        }
        // cout << mx_a << " " << mx_b << " " << mx_c << '\n';
        if(check)
            cout << "Yes" << '\n';
        else 
            cout << "No" << '\n';
    }
}