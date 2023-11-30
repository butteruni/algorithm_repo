#include <bits/stdc++.h>
using namespace std;
const int mod=4;
struct Hash{
	static const int MOD=233333;
	static const int maxn=1e6+5;
	int tot,head[MOD+10],next[maxn],h[maxn],val[maxn];
	inline void clear(){tot=0;memset(head,0,sizeof(head));}
	inline void insert(int H,int VAL)
	{
		for(int i=head[H%MOD];i;i=next[i])
		if(h[i]==H){
			val[i]=VAL;return;
		}
		h[++tot]=H;val[tot]=VAL;next[tot]=head[H%MOD];head[H%MOD]=tot;
	}
	inline int count(int H)
	{
		for(int i=head[H%MOD];i;i=next[i])if(h[i]==H)return val[i];
		return 0;
	}
}q;
//unordered_map<int,int>q;//较慢10倍左右 
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int ksm(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)res=1ll*res*a%mod;
        a=1ll*a*a%mod;
        b>>=1;
    }
    return res;
}
int bsgs(int y,int z)
{
    q.clear();
    int cnt=0;
    int m=sqrt(mod),t=1;
//    for(int i=gcd(y,mod);i!=1;i=gcd(y,mod))//exbsgs处理当mod与y不互质时
//    {
//        if(z%i){
//            return -1;
//        }
//        cnt++;mod/=i;z/=i;t=t*y/i%mod;
//        if(z==t)
//        {
//            return cnt;
//        }
//    }
    int s=z,ans=-1;
    for(int i=0;i<m;i++)//从0~m-1枚举右边 
    {
//    	q[s]=i;
        q.insert(s,i);
        s=1ll*s*y%mod;
    }
    int xx=ksm(y,m);s=t;
    for(int i=1;i<=m+1;i++)
    {
        s=1ll*s*xx%mod;
        if(q.count(s))
        {
            ans=i*m-q.count(s)+cnt;
            break;
        }
    }
    return ans;
//    if(ans==-1)cout<<"No Solution\n";
//    else cout<<ans<<"\n";
}
int main()
{
    cout << bsgs(4,2) << endl;
    return 0;
}