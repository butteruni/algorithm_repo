#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int  N = 2e5 + 10;
ll a[N];
map<ll,int>mp1;
map<ll,int>mp2;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,q;
    cin >> n >> q;
    for(int i = 1;i <= n;++i)
    {
        cin >> a[i];
    }
    for(int i = 0;i <= n + 10;++i)
    {
        mp2[i] = 1;
    }
    for(int i = 1;i <= n;++i)
    {
        mp1[a[i]]++;
        mp2.erase(a[i]);
    }
    for(int i = 1;i <= q;++i)
    {
        ll pos,val;
        cin >> pos >> val;
        mp1[a[pos]]--;
        if(mp1[a[pos]] == 0)
        {
            mp1.erase(a[pos]);
            mp2[a[pos]] = 1;
        }
        a[pos] = val;
        if(mp1[a[pos]] == 0)
        {
            mp2.erase(a[pos]);
        }
        mp1[a[pos]]++;
        for(auto [x,val]:mp2)
        {
            cout << x << '\n';
            break;
        }
    }
}   