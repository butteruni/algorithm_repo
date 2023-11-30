#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll MAXN=2147483647;
const ll p=1e9+7;
ll inv[MAXN];
//线性求逆元
void init()
{
	inv[1]=1;
    for(ll i=2;i<=MAXN;++i) 
    {
        inv[i]=(long long)(p-p/i)*inv[p%i]%p;
    }
}
//快速幂求逆元 ps:mod p p应为质数
ll qpow(ll a,ll b) 
{
    ll ans = 1;
    a=(a%p+p)%p;
    while(b)
    {
        if(b&1)ans=(a*ans)%p;
        a=(a*a)%p;
        b>>=1;
    }
    return ans;
}
//扩展欧几里得求逆元 若a*x≡1(mod b),a,b互质,则称x为a的逆元 ax0+by0=gcd(a,b)=1 ps:gcd(a,b)不为1说明逆元不存在,若为1,调整x0到0~m-1的范围中即可
ll exgcd(ll a,ll b,ll& x,ll& y) 
{
	if(!b) 
	{
  		x=1;
  		y=0;
  		return a;
 	}
 	ll k=exgcd(b,a%b,y,x);
 	y-=a/b*x;
 	return k;
}

ll getInv(ll a,ll b)
{
    ll x,y;
    exgcd(a,b,x,y);
    return (x%b+b)%b;
}
int main()
{
    std::ios::sync_with_stdio(false);

    return ;
}