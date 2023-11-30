#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 10;
int n;
const double eps = 1e-8;
int sgn(double x)
{
    if(fabs(x) < eps)return 0;
    if(x < 0) return -1;
    else return 1;
}
struct Point
{
    double x,y;
    Point(){}
    Point(double _x,double _y)
    {
        x = _x;y = _y;
    }
    Point operator -(const Point &b)const
    {
        return Point(x - b.x,y - b.y);
    }
    double operator ^(const Point &b)const
    {
        return x*b.y - y*b.x;
    }
    double operator *(const Point &b)const
    {
        return x*b.x + y*b.y;
    }
};
double Cross(Point A, Point B)///叉积计算
{
    return A.x * B.y - A.y * B.x;
}
double Area2(Point A, Point B, Point C)///用叉积计算三角形面积
{
    return Cross(B - A, C - A) / 2.0;
}
Point p[N];
int main()
{
    while(cin >> n)
    {
        if(n == 0)
            break;
        double ans = 0;
        for(int i = 1;i <= n;++i)
        {
            cin >> p[i].x >> p[i].y;
        }
        for(int i = 2;i < n;i ++)
        {
            // cout << Area2(p[1],p[i],p[i + 1]) << '\n';
            ans += Area2(p[1],p[i],p[i + 1]);
        }
        printf("%.1lf\n",ans);
    }
}