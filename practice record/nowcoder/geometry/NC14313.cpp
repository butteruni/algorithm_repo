#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
const double eps = 1e-4;
int sgn(double x)
{
    if(fabs(x) <= eps)return 0;
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
Point make_circle(Point a,Point b,Point c) //三点共圆确定圆心
{
    double a1 = b.x - a.x, b1 = b.y - a.y,c1 = (a1 * a1 + b1 * b1) / 2;
    double a2 = c.x - a.x, b2 = c.y - a.y,c2 = (a2 * a2 + b2 * b2) / 2;
    double d = a1 * b2 - a2 * b1;
    return Point(a.x + (c1 * b2 - c2 * b1) / d,a.y+(a1 * c2 - a2 * c1) / d);
}
Point po[N];
void solve(int n)
{
    long long a,b,c,k;
    while(1)
    {
        k = 0;
        a = (rand() % n) + 1,b = (rand() % n) + 1,c = (rand() % n) + 1;
        Point circle = make_circle(po[a],  po[b], po[c]);
        double cur_dis = dis(circle,po[a]);
        if(fabs(circle.x) > 1e9 || fabs(circle.y) > 1e9 || cur_dis > 1e9)
            continue;
        for(int i = 1;i <= n;++i)
        {
            double temp = dis(circle,po[i]);
            if(fabs(temp - cur_dis) <= 1e-6)
            {
                k++;
            }
            if(k == (n + 1) / 2)
            {
                printf("%.10lf %.10lf %.10lf\n",circle.x,circle.y ,cur_dis);
                break ;
            }
        }
        if(k == (n + 1) / 2)
        {
            break;
        }
    }
    
}
int main()
{
    long long  t;
    scanf("%d",&t);
    while(t--)
    {
        long long n;
        scanf("%d",&n);
        for(int i = 1;i <= n;++i)
        {
            scanf("%lf %lf",&po[i].x,&po[i].y);
        }
        if(n < 5)
        {
            if(n == 1)
            {
                printf("%.10lf %.10lf %.10lf\n",po[1].x + 1.0,po[1].y,1.0);
            }else 
            {
                printf("%.10lf %.10lf %.10lf\n",(po[1].x + po[2].x) / 2,(po[1].y + po[2].y) / 2,dis(po[1],po[2]) / 2);
            }
        }else 
        {
            solve(n);
        }
    }
}