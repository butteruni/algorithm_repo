//POJ-1269

#include <cstdio>
#include <math.h>
using namespace std;

typedef long long ll;
typedef double db;
const int N = 1e5 + 10;
const db eps = 1e-8;
#define y1 ya

db x1,x2,x3,x4,y1,y2,y3,y4;

db make_cross(db xa,db ya,db xb, db yb)
{
    return xa * yb - xb * ya;
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("INTERSECTING LINES OUTPUT\n");
    for(int i = 1;i <= n;i++)
    {
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
        if(fabs((x2 - x1) * (y4 - y3) - (y2 - y1) * (x4 - x3)) < eps)//平行
        {
            if(fabs((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1)) < eps)//共线
            {
                printf("LINE\n");
            }else 
                printf("NONE\n");
        }else //相交
        {
            db s1 = make_cross(x2 - x1, y2 - y1, x4 - x3, y4 - y3);
            db s2 = make_cross(x4 - x3, y4 - y3, x1 - x3, y1 - y3);
            db ans = s2 / s1;
            printf("POINT %.2lf %.2lf\n", x1 + (x2 - x1) * ans, y1 + (y2 - y1) * ans);
        }
    }
    printf("END OF OUTPUT\n");
}