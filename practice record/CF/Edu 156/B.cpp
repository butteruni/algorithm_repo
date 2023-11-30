#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double eps = 1e-12;
double dis(double dx,double dy)
{
    return sqrt(dx * dx + dy * dy);
}
double sgn(double x)
{
    if(fabs(x) < eps)
    {
        return 0;
    }else if(x > 0)
    {
        return 1;
    }else 
    {
        return -1;
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
        double px,py,ax,ay,bx,by;
        cin >> px >> py >> ax >> ay >> bx >> by;
        double r1 = 1e4;
        double l1 = 0;
        while(sgn(r1 - l1) == 1)
        {
            double mid = (r1 + l1) / 2;
            bool ok = 0;
            if(sgn(dis(px - ax,py - ay) - mid) <= 0 && sgn(dis(ax,ay) - mid) <= 0) // p在圆a内
            {
                ok = 1;
            }
            if(sgn(dis(px - bx,py - by) - mid) <= 0 && sgn(dis(bx,by) - mid) <= 0)
            {
                ok = 1;
            }
            if(sgn(dis(bx - ax,by - ay) - 2 * mid) <= 0 
            && sgn(dis(px - bx,py - by) - mid) <= 0
            &&sgn(dis(ax,ay) - mid) <= 0) // p在圆b且圆b，a有交
            {
                ok = 1;
            }
            if(sgn(dis(bx - ax,by - ay) - 2 * mid) <= 0 
            && sgn(dis(px - ax,py - ay) - mid) <= 0
            &&sgn(dis(bx,by) - mid) <= 0) // p在圆b且圆b，a有交
            {
                ok = 1;
            }
            if(ok)
            {
                r1 = mid;
            }else 
            {
                l1 = mid;
            }
        }
        cout  << fixed << setprecision(10) << l1 << '\n';
    }
}