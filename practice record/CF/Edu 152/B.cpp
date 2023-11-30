#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5 + 10;
struct node
{
    ll val;
    ll id;
}a[N];
ll k;
bool cmp(node a,node b)
{
    if(a.val != b.val)
        return a.val > b.val;
    return a.id < b.id;
}
ll t;
ll n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(int i = 1;i <= n;++i)
        {
            cin >> a[i].val;
            a[i].id = i;
            a[i].val %= k;
            if(a[i].val == 0)
                a[i].val = k;
        }
        sort(a + 1,a + 1 + n,cmp);
        for(int i = 1;i <= n;++i)
        {
            cout << a[i].id << ' ';
        }
        cout << '\n';
    }   
}