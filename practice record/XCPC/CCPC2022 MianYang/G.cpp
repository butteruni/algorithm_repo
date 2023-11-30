#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int N = 2e5 + 10;
ll a[N];
ll suf[N];
ll pre[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    // vector<ll>a(n);
    for(int i = 1;i <= n;++i)
    {
        cin >> a[i];
    }
    if(n == 1)
    {
        cout << 0 << '\n';
    }else if(is_sorted(a + 1,a + 1 + n))
    {
        cout << 1 << '\n';
    }else 
    {
        vector<ll>cur;
        vector<ll>pre;
        int ans = 0;
        for(int i = 1;i <= n;++i)
        {
            pre.push_back(a[i]);
        }
        while(pre.size() > 1)
        {
            int sz = pre.size();
            for(int i = 0;i < sz;++i)
            {
                if(i == 0)
                {
                    if(pre[i] < pre[i + 1])
                    {
                        continue;
                    }else 
                    {
                        cur.push_back(pre[i]);
                        continue;
                    }
                }
                if(i == sz - 1)
                {
                    if(pre[i] < pre[i - 1])
                        continue;
                    cur.push_back(pre[i]);
                    continue;
                }
                if(pre[i - 1] > pre[i] || pre[i] < pre[i + 1])
                    continue;
                cur.push_back(pre[i]);
            }
            pre.clear();
            pre = cur;
            cur.clear();
            ans++;
        }
        cout << ans << '\n';
    }
}