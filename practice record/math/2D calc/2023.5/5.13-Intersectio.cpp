#include<iostream>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
typedef double db;
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
}l[10];
bool inside(Point p,Point a,Point b)
{
    return (p.x >= a.x && p.x <= b.x) && (p.y >= a.y && p.y <= b.y);
}
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
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        db x1,x2,y1,y2;
        Line temp;
        cin >> temp.e.x >> temp.e.y >> temp.s.x >> temp.s.y >> x1 >> y1 >> x2 >> y2;
        if(x1 > x2)
            swap(x1,x2);
        if(y1 > y2)
            swap(y1,y2);
        if(inside(temp.s,{x1,y1},{x2,y2}) || inside(temp.e,{x1,y1},{x2,y2}))
        {
            cout << "T" << endl;
            continue;
        }
        l[1].e = {x1,y1},l[1].s = {x2,y1}; 
        l[2].e = {x2,y1},l[2].s = {x2,y2}; 
        l[3].e = {x1,y2},l[3].s = {x2,y2}; 
        l[4].e = {x1,y1},l[4].s = {x1,y2}; 
        bool success = 0;
        for(int i = 1;i <= 4;++i)
        {
            if(inter(temp,l[i]))
                success = 1;
        }
        if(success)
            cout << "T" << endl;
        else 
            cout << "F" << endl;
    }
    return 0;
}