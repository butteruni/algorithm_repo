//POJ-2318
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5010;
int n,m,x1,ya,x2,yb;
struct node
{
    int x,y;
}po[N];
int cnt[N];
int ans[N];
int id[N];
bool cmp(node a,node b)
{
    return a.x < b.x; 
}
bool check(int x,int y,int idx)
{
    int cross = (x - po[idx].x) * (y - yb) - (x - po[idx].y) * (y - ya);
    if(cross < 0)
        return true;
    else 
        return false;
}
int main()
{
    while(cin >> n)
    {
        if(n == 0)
            break;
        cin >> m >> x1 >> ya >> x2 >> yb;
        for(int i = 1;i <= n;++i)
        {
            int x,y;
            cin >> po[i].x >> po[i].y;
            id[i] = i;
        }
        po[0].x = x1, po[0].y = x1;
        po[n + 1].x = x2, po[n + 1].y = x2;
        memset(cnt,0,sizeof(cnt));
        memset(ans,0,sizeof(ans));
        sort(po,po + n + 2,cmp);
        for(int i = 1;i <= m;++i)
        {
            int l = 0,r = n + 1;
            int x,y;
            cin >> x >> y;
            while(l < r)
            {
                int mid = l + r >> 1;
                if(check(x, y, mid))
                    r = mid;
                else 
                    l = mid + 1;
            }
            cnt[l]++;
        }
        for(int i = 0;i <= n + 1;++i)
            ans[cnt[i]]++;
        cout << "Box\n";
        for(int i = 1;i <= n + 1;++i)
        {
            if(ans[i])
            {
                printf("%d: %d\n",i,ans[i]);
            }
        }
    }
    return 0;
}