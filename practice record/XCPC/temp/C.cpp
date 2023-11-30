#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{   
    int t;
    cin >> t;
    scanf("%d",&t);
    while(t--)
    {
        ll n,k;
        scanf("%lld %lld",&n,&k);
        vector<int>w(n + 1);
        double sum = 0;
        for(int i = 1;i <= n;++i)
        {
            scanf("%d",&w[i]);
            sum += w[i];
        }
        double fin = sum + k;
        for(int i = 1;i <= n;++i)
        {
            printf("%.10f ",fin / sum * w[i]);
        }
        puts("");
    }
}