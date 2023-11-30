#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,q;
        cin >> n >> q;
        vector<ll>a(n + 1);
        vector<int>pos[60];
        for(int i = 0;i <= 30;++i)
            pos[i].clear();
        for(int i = 1;i <= n;++i)
        {
            cin >> a[i];
            ll st = 1;
            while(a[i] % (1 << st) == 0)
            {
                pos[st].push_back(i);
                st++;
            }
        }
        for(int i = 1;i <= q;++i)
        {
            int x;
            cin >> x;
            for(auto p : pos[x])
            {
                if(a[p] % (1 << x) == 0)
                {
                    // a[p] -= (1 << x);
                    a[p] += (1 << (x - 1));
                    pos[x - 1].push_back(p);
                }
            }
            pos[x].clear();
        }
        for(int i = 1;i <= n;++i)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}