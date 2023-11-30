#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double inf = 1e20;
const double pi = acos(-1.0);
const int maxp = 10100;
int sgn(double x)
{
    if(fabs(x) < eps) return 0;
    if(x < 0) return -1;
    else return 1;
}
double sqr(double x){ return x * x;}
struct Point2
{
    double x,y;
    Point2(){};
    Point2 (double _x, double _y)
    {
        x = _x,y = _y;
    }
    bool operator == (const Point2 b)
    {
        return sgn(x - b.x) == 0 && sgn(y - b.y) == 0;
    }
    bool operator < (const Point2 b)
    {
        return sgn(x - b.x) == 0 ? sgn(y - b.y) < 0:x < b.x;
    }
    Point2 operator -(const Point2 b)
    {
        return Point2(x - b.x,y - b.y);
    }
    Point2 operator +(const Point2 b)
    {
        return Point2(x + b.x,y + b.y);
    }
    Point2 operator *(const double k)
    {
        return Point2(x * k,y * k);
    }
    Point2 operator /(const double k)
    {
        return Point2(x / k,y / k);
    }
    double operator ^(const Point2 b)
    {
        return x * b.y - y * b.x;
    }
    double operator *(const Point2 b)
    {
        return x * b.x + y * b.y;
    }
    double operator ^(const Point2 &b)const
    {
        return x * b.y - y * b.x;
    }
    double len()
    {
        return sqrt(x * x + y * y);
    }
    double len2()
    {
        return x * x + y * y;
    }
    double dis(const Point2 b)
    {
        return sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
    }
    double rad(Point2 a,Point2 b)
    {
        Point2 p = *this;
        return fabs(atan2(fabs((a - p) ^ (b - p)),(a - p) * (b - p)));
    }
    Point2 trunc(double r)
    {
        double l = len();
        if(!sgn(l))
            return *this;
        r /= l;
        return Point2(x * r,y * r);
    }
};
typedef Point2 Vec2;
struct Line
{
    Point2 s,e;
    Line(){}
    Line(Point2 _s,Point2 _e)
    {
        s = _s,e = _e; 
    }
    bool operator ==(const Line v)
    {
        return (s == v.s) && (e == v.e);
    }
    Line (Point2 p,double angle)
    {
        s = p;
        if(sgn(angle - pi / 2) == 0)
        {
            e = (s + Point2(0,1));
        }else 
        {
            e = (s + Point2(1,tan(angle)));
        }
    }
    Line(double a,double b,double c)
    {
        if(sgn(a) == 0)
        {
            s = Point2(0,-c / b);
            e = Point2(1,-c / b);
        }else if(sgn(b == 0))
        {
            s = Point2(-c / a,0);
            e = Point2(-c / a,1);
        }
        else
        {
            s = Point2(0,-c / b);
            e = Point2(1,(-c - a) / b);
        }
    }
    void adjust()
    {
        if(e < s)
            swap(s,e);
    }
    bool pointonseg(Point2 p)
    {
        return sgn((p - s) ^ (e - s)) == 0 && sgn((p - s) ^ (p - e)) <= 0;
    }
    double length()
    {
        return s.dis(e);
    }
    bool paraller(Line v)
    {
        return sgn((e - s)^(v.e - v.s)) == 0;
    }
    double dispointtoline(Point2 p)
    {
        return fabs((p - s) ^ (e - s)) / length();
    }
    double dispointtoseg(Point2 p)
    {
        if(sgn((p - s) * (e - s)) < 0 || sgn((p - e) * (s - e)) < 0)
        {
//             printf("1 ");
            return min(p.dis(s),p.dis(e));
        }
//         printf("2 ");
        return dispointtoline(p);
    }
};  
Point2 make_circle(Point2 a,Point2 b,Point2 c) //三点共圆确定圆心
{
    double a1 = b.x - a.x, b1 = b.y - a.y,c1 = (a1 * a1 + b1 * b1) / 2;
    double a2 = c.x - a.x, b2 = c.y - a.y,c2 = (a2 * a2 + b2 * b2) / 2;
    double d = a1 * b2 -a2 * b1;
    return Point2(a.x + (c1 * b2 - c2 * b1) / d,a.y+(a1 * c2 - a2 * c1) / d);
}
double Cross(Point2 A, Point2 B)///叉积计算
{
    return A.x * B.y - A.y * B.x;
}
bool inter(Line l1,Line l2)
{
    return 
    max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&
    max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&
    max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&
    max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&
    sgn((l2.s-l1.s)^(l1.e-l1.s))*sgn((l2.e-l1.s)^(l1.e-l1.s)) <= 0 &&
    sgn((l1.s-l2.s)^(l2.e-l2.s))*sgn((l1.e-l2.s)^(l2.e-l2.s)) <= 0;
}
Point2 shleter[maxp],typhoon[maxp];
Line lines[maxp];
int main()
{
    int n,m;
    scanf("%d %d",&m,&n);
    for(int i = 1;i <= m;++i)
    {
        scanf("%lf %lf",&typhoon[i].x,&typhoon[i].y);
//         printf("%lf %lf\n",typhoon[i].x ,typhoon[i].y);
    }
    for(int i = 1;i <= n;++i)
    {
        scanf("%lf %lf",&shleter[i].x,&shleter[i].y);
    }
    for(int i = 1;i < m;++i)
    {
        lines[i] = Line(typhoon[i],typhoon[i + 1]);
    }
    for(int i = 1;i <= n;++i)
    {
        double mn = 1e18;
        for(int j = 1;j < m;++j)
        {
            double temp = lines[j].dispointtoseg(shleter[i]);
            mn = min(mn,temp);
        }
        printf("%.4lf\n",mn);
    }
}