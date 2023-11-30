// https://ac.nowcoder.com/acm/problem/14676
#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
struct Point
{
    double x,y;
};
int t;
double r,n;
double sgn(double x)
{
    if(fabs(x) < 1e-3)
        return 0.0;
    else 
        return x;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--)
    {
        Point circle;
        cin >> circle.x >> circle.y >> r >> n;
        double angle = pi * 2 / n;
        for(int i = n;i >= 1;--i)
        {
            printf("%.2lf %.2lf\n",sgn(circle.x + r * cos(angle * (i))),sgn(circle.y + r * sin(angle * (i))));
        }
    }
}