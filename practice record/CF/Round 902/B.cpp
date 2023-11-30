#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    ll a,b;
};
bool cmp(node x,node y)
{
    return x.b < y.b;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll n,p;
        cin >> n >> p;
        vector<node>x(n);
        for(int i = 0;i < n;++i)
        {
            cin >> x[i].a;
        }
        for(int i = 0;i < n;++i)
        {
            cin >> x[i].b;
        }
        ll sum = 0;
        sort(x.begin(),x.end(),cmp);
        ll ans = 0;
        ll used = 0;
        if(x[0].b >= p)
        {
            cout << n * p << '\n';
        }else 
        {
            for(int i = 0;i < n && x[i].b < p && sum < n;++i)
            {
                if(i == 0)
                {
                    ans += p;
                    sum++;
                }
                if(sum + x[i].a >= n)
                {
                    ans += (n - sum) * x[i].b;
                    sum = n;
                }else 
                {
                    sum += x[i].a;
                    ans += x[i].a * x[i].b;
                }
            }
            if(sum < n)
            {
                ans += (n - sum) * p;
            }
            cout << ans << '\n';
        }
    }
}