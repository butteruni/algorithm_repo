#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N  = 1e6 + 10;
ll n,m,p,q;
int fa[N],col[N];
int findr(int a)
{
    return fa[a] == a ? a : fa[a] = findr(fa[a]);
}
int main()
{
    scanf("%d %d %d %d", &n, &m, &p, &q);
    for(int i = 1;i <= n + 1;++i)
        fa[i] = i;
    for(int i = m;i;i--)
    {
        ll l = (i * p + q) % n + 1;
        ll r = (i * q + p) % n + 1;
        if(l > r)
            swap(l,r);
        l = findr(l);
        while(l <= r)
        {
            col[l] = i;
            fa[l] = findr(l + 1);
            l = findr(l);
        }
    }
    for(int i = 1;i <= n;++i)
        printf("%d\n",col[i]);
}