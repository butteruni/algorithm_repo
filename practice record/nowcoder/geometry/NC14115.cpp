#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 10;
int n;
const double eps = 1e-7;
int sgn(double x)
{
    if(fabs(x) < eps)return 0;
    if(x < 0) return -1;
    else return 1;
}
double square(double x)
{
    return x * x;
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
double dis(Point a,Point b)
{
    return sqrt(square(a.x - b.x) + square(a.y - b.y));
}
Point po[2],v[2];
double r[2];
double calc_dis(double t)
{
    Point a,b;
    a.x = po[0].x + t * v[0].x;
    a.y = po[0].y + t * v[0].y;
    b.x = po[1].x + t * v[1].x;
    b.y = po[1].y + t * v[1].y;
    return  dis(a,b) - r[0] - r[1];
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
//         cout << t << endl;
        for(int i = 0;i <= 1;++i)
        {
            scanf("%lf %lf %lf %lf %lf",&po[i].x,&po[i].y,&r[i],&v[i].x,&v[i].y);
        }
        double l = 0,r = 1e10;
        while(r - l > eps)
        {
            double mid1 = l + (r - l) / 3,mid2 = r - (r - l) / 3;
            double ans1 = calc_dis(mid1),ans2 = calc_dis(mid2);
            if(ans2 >= ans1)
            {
                r = mid2;
            }else
            {
                l = mid1;
            }
        }
//         cout << l << endl;
        if(calc_dis(l) > 1e-6)
        {
            printf("%.10lf\n",calc_dis(l));
        }else 
        {
            l = 0;
            while(r - l > eps)
            {
                double mid = (r + l) / 2;
                if(calc_dis(mid) > 1e-7) //注意此处精度
                {
                    l = mid;
                }else 
                {
                    r = mid;
                }
            }
            printf("%.10lf\n",l);
        }
    }
}