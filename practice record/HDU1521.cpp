#include <bits/stdc++.h>
using namespace std;
int n,m;
double a[1000],b[1000];
double cnt[1000];
double fac[1000];
void init()
{
    fac[0] = fac[1] = 1;
    for(int i = 2;i <= 10;++i)
        fac[i]  = fac[i - 1] * i;
}
int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0),cout.tie(0);
    init();
    while(scanf("%d %d",&n,&m) != EOF)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i = 1;i <= n;++i)
            cin >> cnt[i];
        for(int i = 0;i <= cnt[1];++i)
        {
            a[i] = 1.0/fac[i];
        }
        for(int i = 2;i <= n;++i)
        {
            for(int j = 0;j <= m;++j)
            {
                for(int k = 0;k <= cnt[i];++k)
                {
                    if(k + j <= m)
                    {
                        b[j + k] += a[j] / fac[k]; 
                    }
                }
            }
            for(int i = 0;i <= m;++i)
            {
                a[i] = b[i];
                b[i] = 0;
            }
        }
        printf("%.0lf\n",fac[m] *a[m]);

    }
    return 0;
}