#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int qu1[N],qu2[N];
int idx1,idx2;
ll query(ll l,ll r)
{
    idx1 = idx2 = 0;
    ll res = 0;
    while(l)
    {
        idx1++;
        qu1[idx1] = l % 3;
        l /= 3;
    }
    while(r)
    {
        idx2++;
        qu2[idx2] = r % 3;
        r /= 3;
    }
    ll ans = 0;
    bool ok = 0;
    for(int i = idx2;i >= 1;--i)
    {
        if(qu2[i] > qu1[i])
            ok = 1;
        if(ok)
        {
            if(qu2[i] == 2)
                res = max(res,ans + 2 + (i - 1) * 3);
            else 
            {
                if(i == idx2)
                {
                    res = max(res, ans + (i - 1) * 3);
                }else 
                    res = max(res,ans + 1 + (i - 1) * 3);
            }
        }
        if(qu2[i] == 2)
            ans += 3;
        else if(qu2[i] == 1)
            ans += 2;
        else    
            ans++;
    }
    for(int i = 0;i <= idx2;++i)
        qu1[i] = qu2[i] = 0;
    return max(ans,res);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll l,r;
        cin >> l >> r;
        cout << query(l,r) << '\n';
    }
    
}