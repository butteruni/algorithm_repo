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
        int n;
        cin >> n;
        ll cnt = 0;
        vector<int>p(n + 1);
        bool ok = 1;
        for(int i = 1;i <= n;++i)
        {
            cin >> p[i];
            if(i % 2 == 0)
            {
                if(p[i] < p[i - 1])
                {
                    if(p[i] !=  p[i - 1] - 1)
                        ok = 0;
                    cnt++;
                    swap(p[i],p[i - 1]);
                }else if(p[i] > p[i - 1] + 1)
                {
                    ok = 0;
                }
            }
        }
        ll sz = 1;
        while(sz < log2(n))
        {
            int step = 0;
            int gap = 1 << sz;
            for(int i = 1;i <= n;i += (1 << sz))
            {
                if(step & 1)
                {
                    if(p[i] < p[i - gap])
                    {
                        if(p[i] != p[i - gap] - gap)
                        {
                            ok = 0;
                            // cout << i << " " << p[i] << "||";
                        }
                        cnt++;
                        swap(p[i],p[i - gap]);
                    }else if(p[i] > p[i - gap] + gap)
                    {
                        ok = 0;
                    }
                }
                step++;
            }
            sz++;
        }
        if(!ok)
        {
            cout << -1 << '\n';
            continue;
        }
        cout << cnt << '\n';
    }
    // cout << log2(262144);
}