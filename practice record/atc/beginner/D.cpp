#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int N = 3030;
ll cnt_1[N],cnt_2[N],cnt_3[N];
ll qpow(ll x,ll y)
{
    if(y == 0)
        return 0;
    ll res = 1;
    while(y)
    {
        if(y & 1)
            res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    s = " " + s;
    for(int i = 1;i <= n;++i)
    {
        cnt_1[i] = cnt_1[i - 1];
        cnt_2[i] = cnt_2[i - 1];
        cnt_3[i] = cnt_3[i - 1];
        if(s[i] == ')')
            cnt_2[i] ++;
        if(s[i] == '(')
            cnt_1[i]++;
        if(s[i] == '?')
            cnt_3[i]++;
    }
    ll ans = 0;
    for(int i = 1;i <= n;++i)
    {
        
    }
}