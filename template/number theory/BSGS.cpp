#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

map<ll,ll> vis;
ll Power(ll a,ll b,ll mod) 
{
	ll sum=1;
	while(b) 
    {
		if(b&1)sum=sum*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return sum;
}
//a^x ≡ b (mod mod)
ll bsgs(ll a,ll b,ll mod)
{
    a%=mod;
    b%=mod;
    if(a==0&&b==0)return 1;
    if(a==0&&b!=0)return -1;
    vis.clear();
    ll m=ceil(sqrt(mod));
    vis[b]=0;
    for(ll i=1;i<=m;i++)
    {
        b=b*a%mod;
        vis[b]=i;
    }
    ll t=Power(a,m,mod);
    b=1;
    for(ll i=1;i<=m;i++)
    {
        b=b*t%mod;
        if(vis[b])
        {
            ll ans=i*m-vis[b];
            return (ans%mod+mod)%mod;
        }
    }
    return -1;
}
int T,k;
ll y,z,p;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>T>>k;
    while(T--)
    {
        cin>>y>>z>>p;
        y%=p;
        if(k==1)
        {
            cout<<Power(y,z,p)<<endl;
        }
        else if(k==2)
        {
            z%=p;
            if(y==0&&z!=0)
            {
                cout<<"Orz, I cannot find x!"<<endl;
            }
            else 
            {
                cout<<z*Power(y,p-2,p)%p<<endl;
            }
        }
        else if(k==3)
        {
            ll ans=bsgs(y,z,p);
            if(ans==-1)cout<<"Orz, I cannot find x!"<<endl;
            else cout<<ans<<endl;
        }
    }
    return 0;
}