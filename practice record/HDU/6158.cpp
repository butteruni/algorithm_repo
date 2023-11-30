#include<bits/stdc++.h>
using namespace std;
const double eps=1e-13;
double pi=acos(-1.0);
double ans,R1,R2,k,rr,r1;
int n,T;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf%lf",&R1,&R2);
        scanf("%d",&n);
        if (R1>R2) swap(R1,R2);
        double k=1; //k可以取任意值
        double rr=k*k/(4*R1)-k*k/(4*R2); //反形圆半径
        double lx=k*k/(2*R2)+rr; //反形圆的圆心到反演点的距离

        ans=pi*(R2-R1)*(R2-R1);  //因为n>=1
        for(int i=2;i<=n;i+=2)
        {
            double ly=(i/2)*2*rr;
            double l=sqrt(lx*lx+ly*ly); //第i个圆的反形圆的圆心到反演点的距离
            double r=( k*k/(l-rr)-k*k/(l+rr) )/2.0; //利用反演求第i个圆的圆心
            if (pi*r*r<eps) break;
            if (i+1>n) ans+=pi*r*r;
              else ans+=pi*r*r*2;
        }
        printf("%.5lf\n",ans);
    }
}