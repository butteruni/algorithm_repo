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
const int MAXN = 100;
Line line[MAXN];
double dis[MAXN][MAXN];
const double INF = 1e20;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    double x,y1,y2,y3,y4;
    while(scanf("%d",&n) == 1)
    {
        if(n == -1) break;
        for(int i = 1;i <= n;i++)
        {
            scanf("%lf%lf%lf%lf%lf",&x,&y1,&y2,&y3,&y4);
            line[2*i-1] = Line(Point(x,y1),Point(x,y2));
            line[2*i] = Line(Point(x,y3),Point(x,y4));
        }
        for(int i = 0;i <= 4*n+1;i++)
            for(int j = 0;j <= 4*n+1;j++)
            {
                if(i == j)dis[i][j] = 0;
                else dis[i][j] = INF;
            }
        for(int i = 1;i <= 4*n;i++) 
        {
            int lid = (i+3)/4;
            bool flag = true;
            Point tmp;
            if(i&1)tmp = line[(i+1)/2].s;
            else tmp = line[(i+1)/2].e;

            for(int j = 1;j < lid;j++)//有哪些点能与起点相连
                if(inter(line[2*j-1],Line(Point(0,5),tmp)) == false
                        && inter(line[2*j],Line(Point(0,5),tmp)) == false)
                    flag = false;
            if(flag)
                dis[0][i] = dis[i][0] = dist(Point(0,5),tmp);
            flag = true;

            for(int j = lid+1;j <= n;j++)//有哪些点能与终点相连
                if(inter(line[2*j-1],Line(Point(10,5),tmp)) == false
                        && inter(line[2*j],Line(Point(10,5),tmp)) == false)
                    flag = false;
            if(flag)
                dis[i][4*n+1] = dis[4*n+1][i] = dist(Point(10,5),tmp);
        }
        for(int i = 1;i <= 4*n;i++)
            for(int j = i+1;j <=4*n;j++)//中间点彼此相连
            {
                int lid1 = (i+3)/4;
                int lid2 = (j+3)/4;
                bool flag = true;
                Point p1,p2;
                if(i&1)
                    p1 = line[(i+1)/2].s;
                else 
                    p1 = line[(i+1)/2].e;
                if(j&1)
                    p2 = line[(j+1)/2].s;
                else 
                    p2 = line[(j+1)/2].e;
                for(int k = lid1+1;k < lid2;k++)
                    if(inter(line[2*k-1],Line(p1,p2)) == false
                            && inter(line[2*k],Line(p1,p2)) == false)
                        flag = false;
                if(flag) 
                    dis[i][j] = dis[j][i] = dist(p1,p2);
            }
        
        bool flag = true;
        for(int i = 1;i <= n;i++)
            if(inter(line[2*i-1],Line(Point(0,5),Point(10,5))) == false
                    && inter(line[2*i],Line(Point(0,5),Point(10,5))) == false)
                flag = false;
        if(flag)
            dis[0][4*n+1] = dis[4*n+1][0] = 10;

        for(int k = 0;k <= 4*n+1;k++) //floyd求最短路
            for(int i = 0;i <= 4*n+1;i++)
                for(int j = 0;j <= 4*n+1;j++)
                    if(dis[i][k] + dis[k][j] < dis[i][j])
                        dis[i][j] = dis[i][k] + dis[k][j];
        printf("%.2lf\n",dis[0][4*n+1]);
    }
    
    return 0;
}