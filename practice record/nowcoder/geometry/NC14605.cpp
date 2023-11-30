// https://ac.nowcoder.com/acm/problem/14605
#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double inf = 1e20;
const double pi = acos(-1.0);
const int maxp = 1010;
int sgn(double x)
{
    if(fabs(x) < eps) return 0;
    if(x < 0) return -1;
    else return 1;
}
struct Point
{
    double x,y;
    Point(){};
    Point (double _x, double _y)
    {
        x = _x,y = _y;
    }
    bool operator == (const Point b)
    {
        return sgn(x - b.x) == 0 && sgn(y - b.y) == 0;
    }
    bool operator < (const Point b)
    {
        return sgn(x - b.x) == 0 ? sgn(y - b.y) < 0:x < b.x;
    }
    Point operator -(const Point b)
    {
        return Point(x - b.x,y - b.y);
    }
    Point operator +(const Point b)
    {
        return Point(x + b.x,y + b.y);
    }
    double operator ^(const Point b)
    {
        return x * b.y - y * b.x;
    }
};
struct Line
{
    Point s,e;
    Line(){}
    Line(Point _s,Point _e)
    {
        s = _s,e = _e; 
    }
};
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
double Cross(Point A, Point B)///叉积计算
{
    return A.x * B.y - A.y * B.x;
}
Point st = {0.0,0.0},ed = {2000,2000};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i)
    {
        Point a,b,c;
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
        Line line1 = {a,b},line2 = {a,c},line3 = {b,c};
        if(!Cross(a - b,a - c))
        {
            cout << "NO\n";
            continue;
        }
        Line s1 = {st,ed};
        int cnt = 0;
        if(inter(line1,s1))
            cnt++;
        if(inter(line2,s1))
            cnt++;
        if(inter(line3,s1))
            cnt++;
        if(cnt % 2 == 0)
            cout << "NO\n";
        else 
            cout << "YES\n";
    }
}