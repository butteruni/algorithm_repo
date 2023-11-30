#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int S(int x)
{
    return x < 0?-1 : 1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m,i1,i2,j1,j2;
        string d;
        cin >> n >> m >> i1 >> j1 >> i2 >> j2 >> d;
        bool ok = 0;
        i1 --,i2 --,j1--,j2--;
        int di = (d[0] == 'D' ? 1 : -1);
        int dj = (d[1] == 'R' ? 1 : -1);
        int ans = 0;
        map<int,int>vis_1;
        map<int,int>vis_2;
        while(1)
        {
            if(i1 == i2 && j1 == j2)
            {
                ok = 1;
                break;
            }
            if(di == dj && S(i2 - i1) == di && S(j2 - j1) == dj && i2 - j2 == i1 - j1)
            {
                ok = 1;
                break;
            }
            if(di != dj && S(i2 - i1) == di && S(j2 - j1) == dj && i2 + j2 == i1 + j1)
            {
                ok = 1;
                break;
            }
            if(di == dj && vis_1.count(i1 - j1) && vis_1[i1 - j1] > 1)
            {
                break;
            }
            if(di != dj && vis_2.count(i1 + j1) && vis_2[i1 + j1] > 1)
            {
                break;
            }
            if(di == dj)
            {
                vis_1[i1 - j1]++;
            }else if(di != dj)
            {
                vis_2[i1 + j1]++;
            }
            ans++;
            int d1 = (di < 0 ? i1 : n - i1 - 1);
            int d2 = (dj < 0 ? j1 : m - j1 - 1);
            i1 += di * min(d1,d2);
            j1 += dj * min(d1,d2);
            if(d1 == d2)
            {
                if(di < 0)
                    i1 = 0;
                else 
                {
                    i1 = n - 1;
                }
                if(dj < 0)
                {
                    j1 = 0;
                }else 
                {
                    j1 = m - 1;
                }
                di = -di;
                dj = -dj;
            }else if(d1 < d2) 
            {
                di = -di;
            }else 
            {
                dj = -dj;
            }
            // cout << i1 << " " << j1 << " ";
        }
        if(ok == 0)
        {
            cout << -1 << '\n';
        }else 
        {
            cout << ans << '\n';
        }
    }
}