#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll A,B,C;
ll k;
ll qpow(ll a,ll b)
{
    ll res = 1;
    while(b)
    {
        if(b & 1)
        {
            res =res * a;
        }
        a =a * a ;
        b >>= 1;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> A >> B >> C >> k;
        // cout << qpow(10,A - 1) << "|" << qpow(10, A) << endl;
        bool success = 0;
        for(ll i = qpow(10, A - 1);i < qpow(10,A);i++)
        {
            // cout << 1 << endl;
            ll st_b = max(qpow(10,C - 1) - i,qpow(10,B - 1));
            ll en_b = min(qpow(10, B) - 1,qpow(10, C) - 1 - i);
            // cout << st_b << "|" << en_b << endl;
            ll length = en_b - st_b + 1;
            if(length <= 0)
                continue;
            else 
            {
                if(k <= length)
                {
                    success = 1;
                    cout << i << " + " << st_b + k - 1 << " = " << i + st_b + k - 1 << '\n';
                    break; 
                }else 
                {
                    k -= length;
                }
            }
        }
        if(!success)
            cout << -1 << '\n';
    }
}