#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
int sgn(double x)
{
    if(fabs(x) < eps)
        return 0;
    if(x > 0)
        return 1;
    return -1;
}
struct Point3
{
    double x,y,z;
    Point3(double _x = 0,double _y = 0,double _z = 0)
    {
        x = _x,y = _y,z = _z;
    }
    void input()
    {
        scanf("%lf %lf %lf",&x,&y,&z);
    }
    void output()
    {
        printf("%lf %lf %lf\n",x,y,z);
    }
    bool operator ==(const Point3 &b)const 
    {
        return sgn(x - b.x) == 0 && sgn(y - b.y) == 0 && sgn(y - b.y) == 0;
    }
    double len()
    {
        return sqrt(x * x + y * y + z * z);
    }
    double len2()
    {
        return x * x + y * y + z * z;
    }
    double dis(const Point3 & b)const 
    {

        return sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y) + (z - b.z) * (z - b.z));
    }
    Point3 operator -(const Point3 &b)const
    {
       return Point3(x - b.x,y - b.y,z - b.z);
    }
    Point3 operator +(const Point3 &b)const
    {
       return Point3(x + b.x,y + b.y,z + b.z);
    }
    Point3 operator +(const double &b)const
    {
       return Point3(x + b,y + b,z + b);
    }
    Point3 operator -(const double &b)const
    {
       return Point3(x - b,y - b,z - b);
    }
    Point3 operator *(const double &b)const
    {
       return Point3(x * b,y * b,z * b);
    }
    Point3 operator /(const double &b)const
    {
       return Point3(x / b,y / b,z / b);
    }
    double operator *(const Point3 &b)const
    {
       return x * b.x + y * b.y + z * b.z;
    }
    Point3 operator ^(const Point3 &b)const 
    {
        return Point3(y * b.z - z * b.y,
                      z * b.x - x * b.z,
                      x * b.y - y * b.x);
    }
    double rad(Point3 a,Point3 b)
    {
        Point3 p = *this;
        return acos((a - p) * (b - p) / (a.dis(p) * b.dis(p))); 
    }
    Point3 trunc(double r)
    {
        double l = len();
        if(!sgn(l))return *this;
        r /= l;
        return Point3(x * r,y * r,z * r);
    }
};
struct Line3
{
    Point3 s,e;
    Line3(){};
    Line3(Point3 _s,Point3 _e)
    {
        s = _s,e = _e;
    }
    bool operator ==(const Line3 v)
    {
        return (s == v.s) && (e == v.e);
    }
    void input()
    {
        s.input();
        e.input();
    }
    double length()
    {
        return s.dis(e);
    }
    double dispointtoline(Point3 p)
    {
        return ((e - s) ^ (p - s)).len() / s.dis(e);
    }
    double dispointtoseg(Point3 p)
    {
        if(sgn((p - s) * (e - s)) < 0 || sgn((p - e) * (s - e)) < 0)
        {
            return min(p.dis(s),p.dis(e));
        }
        return dispointtoline(p);
    }
    Point3 lineporg(Point3 p)
    {
        return s + ((e - s) * ((e - s) * (p - s))) / ((e - s).len2());
    }
    bool pointtoseg(Point3 p)
    {
        return sgn(((s - p) ^ (e - p)).len()) == 0 
        && sgn((s - p) * (e - p)) == 0)
    }
};
struct Plane
{
    Point3 a,b,c,n;
    Plane(){};
    Plane(Point3 _a,Point3 _b,Point3 _c)
    {
        a = _a,b = _b,c = _c;
        n = pvec();
    }
    Point3 pvec()
    {
        return (b - a) ^ (c - a);
    }
    Plane(double _a,double _b,double _c,double _d)
    {
        n = Point3(_a,_b,_c);
        if(sgn(_a) != 0)
        {
            a = Point3((-_d - _c - _b) / _a,1,1);
        }else if(sgn(_b) != 0)
        {
            a = Point3(1,(-_d - _c - _a) / _b,1);
        }else if(sgn(_c) != 0)
        {
            a = Point3(1,1,(-_d - _a - _b) / _c);
        }
    }
    bool pointonplane(Point3 p)
    {
        return sgn((p - a) * n) == 0;
    }
    double angleplane(Plane f)
    {
        return acos(n * f.n) / (n.len() * f.n.len());
    }
    int crossline(Line3 u, Point3 &p)
    {
        double x = n * (u.e - a);
        double y = n * (u.s - a);
        double d = x - y;
        if(sgn(d) == 0)
            return 0;
        p = ((u.s * x) - (u.e * y)) / d;
        return 1;
    }
    Point3 pointtoplane(Point3 p)
    {
        Line3 u = Line3(p,p + n);
        crossline(u,p);
        return p;
    }
};