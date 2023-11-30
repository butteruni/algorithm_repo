/*
输入三个数a,b,p
求出a^b mod p 的值

输入
输入一行三个整数a,b,p （1 < a,p < 10000000 ,1 < b < 2100000000）


输出
输出结果
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,y,p;

// a*b % mod
ll mul(ll a, ll b, ll mod) 
{
	ll sum = 0;
	while (b) 
    {
		if(b&1)sum=(sum+a)%mod;
		a=(a+a)%mod;
		b>>=1;
	}
	return sum;
}

// a^b % mod
ll power(ll a,ll b,ll mod) 
{
	ll sum=1;
	while(b) 
    {
		if(b&1)sum=mul(sum,a,mod);
		a=mul(a,a,mod);
		b>>=1;
	}
	return sum;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>x>>y>>p;
    cout<<power(x,y,p);
    return 0;
}
