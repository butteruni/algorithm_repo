#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
struct mat
{
    ll v[3][3];
    mat()
    {
        memset(v,0,sizeof(v));
    }
    void init()
    {
        for(int i = 0;i < 3;++i)
            v[i][i] = 1;
    }
};
mat operator *(mat a,mat b)
{
    mat c;
    for(int i = 0;i < 3;++i)
    {
        for(int j = 0;j < 3;++j)
        {
            c.v[i][j] = 0;
            for(int k = 0;k < 3;++k)
            {
                c.v[i][j] = (c.v[i][j] + (a.v[i][k] * b.v[k][j]) % mod + mod) % mod;
            }
        }
    }
    return c;
}
mat qpow(mat a,ll b)
{
    mat res;
    res.init();
    while(b)
    {
        if(b & 1)
            res = res * a;
        a = a * a;
        b /= 2;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        ll p,n;
        cin >> p >> n;
        mat mp;
        mp.v[0][0] = d,mp.v[0][1] = c;
        mp.v[1][0] = 1,mp.v[2][2] = 1;
        bool ok = 0;
        for(int i = 3;i <= n;)
        {
            if(p / i == 0)
            {
                mat tmp = mp;
                tmp = qpow(tmp,n - i + 1);
                ok = 1;
                cout << ((tmp.v[0][0] * b + tmp.v[0][1] * a + tmp.v[0][2]) % mod + mod) % mod << "\n";
                break;
            }
            int j = min(n,p / (p / i));
            mat tmp = mp;
            tmp.v[0][2] = p / i;
            tmp = qpow(tmp, j - i + 1);
            ll ans_a = ((tmp.v[1][0] * b + tmp.v[1][1] * a + tmp.v[1][2]) % mod + mod) % mod;
            ll ans_b = ((tmp.v[0][0] * b + tmp.v[0][1] * a + tmp.v[0][2]) % mod + mod) % mod;
            a = ans_a;
            b = ans_b;
            i = j + 1;
        }
        if(!ok)
            cout << b << '\n';
    }   
}