#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 998244353;
int T;
ll max_factor, n;

ll gcd(ll a,ll b)
{
    return (!b)?a:gcd(b,a%b);
}

// a^b % mod
ll power(ll a,ll b,ll mod) 
{
	ll sum=1;
	while(b) 
    {
		if(b&1)sum=(__int128)sum*a%mod;
		a=(__int128)a*a%mod;
		b>>=1;
	}
	return sum;
}

bool Miller_Rabin(ll p) // 判断素数
{  
    if(p<2)return false;
    if(p==2)return true;
    if(p==3)return true;
    ll d=p-1,r=0;
    while(!(d&1))++r,d>>=1;  // 将d处理为奇数
    for(ll k=0;k<10;k++) 
    {
        ll a=rand()%(p-2)+2;
        ll x=power(a,d,p);
        if(x==1||x==p-1)continue;
        for(int i=0;i<r-1;i++) 
        {
            x=(__int128)x*x%p;
            if(x==p-1)break;
        }
        if(x!=p-1) return false;
    }
    return true;
}

ll Pollard_Rho(ll x) 
{
    ll s=0,t=0;
    ll c=(ll)rand()%(x-1)+1;
    int step=0,goal=1;
    ll val=1;
    for(goal=1;;goal*=2,s=t,val=1) // 倍增优化
    {  
        for(step=1;step<=goal;step++) 
        {
            t=(__int128)t*t%x;
            t=(t+c)%x;
            val=(__int128)val*abs(t-s)%x;
            if((step%127)==0) 
            {
                ll d=gcd(val,x);
                if(d>1)return d;
            }
        }
        ll d=gcd(val,x);
        if(d>1)return d;
    }
}

void fac(ll x) 
{
    if(x<=max_factor||x<2)return;
    if(Miller_Rabin(x))// 如果x为质数 
    {              
        max_factor=max(max_factor, x);  // 更新答案
        return;
    }
    ll p = x;
    while(p>=x)p=Pollard_Rho(x);  // 使用该算法
    while((x%p)==0)x/=p;
    fac(x);fac(p);  // 继续向下分解x和p
}

int main() 
{
    srand(time(0));
    scanf("%d",&T);
    while(T--) 
    {
        max_factor=0;
        scanf("%lld",&n);
        fac(n);
        if(max_factor==n)  // 最大的质因数即自己
        {
            printf("%lld ",n % mod);
        }
        else
        {
            ll mx = max_factor;
            cout << mx << endl;
            while(mx < n)
            {
                mx = mx * max_factor;
            }
            if(mx == n)
            {
                printf("%lld ",max_factor % mod);
            }else 
            {
                printf("1 ");
            }
        }
    }
    return 0;
}