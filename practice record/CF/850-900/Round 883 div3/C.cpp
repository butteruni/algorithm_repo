#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int h,n,m,t;
struct node
{
    ll point;
    ll penalty;
    bool s;
}a[N];
bool cmp(node x,node y)
{
    if(x.point != y.point)
    {
        return x.point > y.point;
    }else if(x.penalty != y.penalty)
    {
        return x.penalty < y.penalty;
    }else 
    {
        return x.s > y.s;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> h;
        memset(a,0,sizeof(a));
        vector<vector<int> >po;
        po.resize(n + 1);
        for(int i = 1;i <= n;++i)
        {
            po[i].resize(m);
            for(int j = 0;j < m;++j)
            {
                cin >> po[i][j];
            }
        }
        for(int i = 1;i <= n;++i)
        {
            sort(po[i].begin(),po[i].end());
            for(int j = 1;j < m;++j)
                po[i][j] += po[i][j - 1];
            int pos = 0;
            while(po[i][pos] <= h && pos < m)
            {
                a[i].point++;
                a[i].penalty += po[i][pos];
                pos++;
            }
            if(i == 1)
                a[i].s = 1;
        }
        sort(a + 1,a + 1 + n,cmp);
        // for(int i = 1;i <= n;++i)
        // {
        //     cout << i << " " << a[i].point << " " << a[i].penalty << endl;
        // }
        for(int i = 1;i <= n;++i)
        {
            if(a[i].s)
            {
                int pos = i;
                while(a[pos].point == a[i].point && a[i].penalty == a[pos].penalty&&pos>0)
                    pos--;
                cout << pos+1 << endl;
                break;
            }
        }
    }
}