//POJ-1066
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <math.h>
using namespace std;

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
struct Line
{
    Point s,e;
    Line(){}
    Line(Point _s,Point _e)
    {
        s = _s;e = _e;
    }
};
Point p[2010];
Line l[1010];
int n,tot;
//判断线段相交
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
double dist(Point a,Point b)
{
    return sqrt((b-a)*(b-a));
}
int count(Line x)
{
    int t = 0;
    for(int i = 1;i <= n;++i)
    {
        if(inter(x, l[i]))
            t++;
    }
    return t;
}
int main()
{
    while(cin >> n)
    {
        for(int i = 1;i <= n;++i)
        {
            double x,y;
            cin >> x >> y;
            p[i * 2 - 1] = Point(x, y);
            cin >> x >> y;
            p[i * 2] = Point(x, y);
            l[i] = Line(p[i * 2 - 1],p[i * 2]);
        }
        Point st;
        double st_x,st_y;
        cin >> st_x >> st_y;
        st = Point(st_x,st_y);
        int ans = 10000000;
        for(int i = 1;i <= n * 2;++i)
        {
            Line temp = Line(st, p[i]);
            ans = min(ans ,count(temp));
        }
        if(n == 0)
            ans = 2;
        printf("Number of doors = %d\n",ans);
    }
}


