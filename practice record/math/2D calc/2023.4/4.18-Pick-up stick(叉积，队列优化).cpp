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
const int MAXN = 1e5 + 10;
Line line[MAXN];
Point p[MAXN * 2];
bool vis[MAXN];
const double INF = 1e20;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;
    int tot;
    while(scanf("%d",&n))
    {
        if(n == 0)
            break;
        tot = 0;
        int cnt = 0;
        queue<int> q;

        for(int i = 1;i <= n;++i)
        {
            double x1,x2,y1,y2;
            scanf("%lf %lf %lf %lf",&x1, &y1, &x2, &y2);
            p[++tot] = Point(x1, y1);
            p[++tot] = Point(x2, y2);
            line[++cnt] = Line(p[tot], p[tot - 1]);
            q.push(cnt);
            if(i == 1)
                continue;
            while(!q.empty())
            {
                int temp = q.front();
                q.pop();
                if(temp == i)
                {
                    q.push(temp);
                    break;
                }
                bool up = inter(line[temp], line[i]);
                if(!up)
                    q.push(temp);
            }
        }
        printf("Top sticks: %d", q.front());
        q.pop();
        while(!q.empty())
        {
            int temp;
            temp = q.front();
            q.pop();
            printf(", %d",temp);
        }
        printf(".\n");
    }
}