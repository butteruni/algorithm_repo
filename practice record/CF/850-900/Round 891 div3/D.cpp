#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
struct node
{
    ll mins,id;
}c[N];
bool cmp(node x,node y)
{
    if(x.mins == y.mins)
    {
        return x.id < y.id;
    }
    return x.mins > y.mins;
}
ll a[N],b[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i = 1;i <= n;++i)
        {
            cin >> a[i];
        }
        for(int i = 1;i <= n;++i)
        {
            cin >> b[i];
        }
        for(int i = 1;i <= n;++i)
        {
            c[i].mins =  a[i] - b[i];
            c[i].id = i;
        }
        sort(c + 1,c + 1 + n,cmp);
        vector<ll> ans;
        ll st = 1;
        while(c[st].mins == c[1].mins && st <= n)
        {
            ans.push_back(c[st].id);
            st++;
        }
        cout << ans.size() << "\n";
        for(auto p : ans)
        {
            cout << p << " ";
        }
        cout << "\n";
    }
}