#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 2e5 + 10;
int n;
ll a[N],b[N];
bool ok;
void check()
{
    deque<int>q;
    ok = 1;
    for(int i = 1;i <= n;++i)
    {
        if(a[i] == b[i])
        {
            while(q.size())
            {
                q.pop_back();
            }
            q.push_back(a[i]);
        }else 
        {
            if(b[i] < a[i])
            {
                ok = 0;
                break;
            }else 
            {
                while(q.size() && q.back() < a[i])
                {
                    q.pop_back();
                }
                q.push_back(a[i]);
                while(q.size() && q.front() > b[i])
                {
                    q.pop_front();
                }
                if(q.size() && b[i] == q.front())
                {
                    a[i] = q.front();
                }
            }
        }
    }
    if(ok)
    {
        for(int i = 1;i <= n;++i)
            if(a[i] != b[i])
                ok = 0;
    }
}
void solve()
{
    cin >> n;
    for(int i = 1;i <= n;++i)
        cin >> a[i];
    for(int i = 1;i <= n;++i)
        cin >> b[i];
    check();
    reverse(a + 1,a + 1 + n);
    reverse(b + 1,b + 1 + n);
    check();
    if(ok)
    {
        cout << "YES\n";
    }else 
    {
        cout << "NO\n";
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}