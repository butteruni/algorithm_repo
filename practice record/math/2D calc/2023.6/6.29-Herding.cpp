#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e3 + 10;
int t,n;
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

Point points[N];
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1;i <= n;++i)
        {
            cin >> points[i].x >> points[i].y;
        }
        double ans = 1e9;
        for(int i = 1;i <= n - 2;++i)
        {
            for(int j = i + 1;j <= n - 1;++j)
            {
                for(int k = j + 1;k <= n;++k)
                {
                    Point A = points[i],B = points[j],C = points[k];
                    double area = fabs(Area2(A,B,C));
                    // cout << area << '\n';
                    if(sgn(area) == 0)
                        continue;
                    if(area < ans)
                        ans = area;
                }
            }
        }
        if(ans > 1e8)
            printf("Impossible\n");
        else 
            printf("%.2lf\n",ans);
    }
}