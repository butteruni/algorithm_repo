#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b == 0)
    {
        x = 1,y = 0;
        return a;
    }
    ll d = exgcd(b,a % b,x,y);
    ll z = x;
    x = y,y = z - (a / b) * x;
    return d;
}
void count(ll a,ll b,ll c) // 计算 ax + by = c 解的个数
{
    ll x,y;
    ll d = exgcd(a,b,x,y);
    /*
        约束条件自行添加
    */
    if(c % d)
    {
        cout << -1 << '\n';
        return;
    }
    a /= d,b /= d;
    x *= c / d,y *= c / d;
    if(x <= 0)
    {
        ll cnt = abs(x) / b + 1;
        x = x % b + b;
        y -= cnt * a;
        if(y <= 0)
        {
            cout << x << " " << (y % a + a) << '\n';
            return ;
        }
    }
    if(y <= 0)
    {
        ll cnt = abs(y) / a + 1;
        y = y % a + a;
        x -= cnt * b;
        if(x <= 0)
        {
            cout << (x % b + b) << " " << y << '\n';
            return;
        }
    }
    ll cnt = x / b;
    x -= cnt * b;
    if(!x)
    {
        x += b;
        cnt--;
    }
    y += cnt * a;
    ll xmin = x,ymax = y;
    cnt = y / a;
    y -= cnt * a;
    if(!y)
    {
        y += a;
        cnt--;
    }
    x += cnt * b;
    ll ymin = y,xmax = x;
    cout << (xmax - xmin) / b + 1 << " " << xmin << " " << ymin << " " << xmax << " " << ymax << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll a,b,c;
        cin >> a >> b >> c;
        count(a,b,c);
    }
}