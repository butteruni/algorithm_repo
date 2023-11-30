#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 1e6 + 10;
vector<int>e[N];
vector<int>link[N];
ll cnt[N];
ll in[N];
bool vis[N];
unordered_map<ll,ll>mp;
int n;
#define LD double
#define Re int
inline char nc() {
	static char buf[1000000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;
}
template <typename _Tp> inline void read(_Tp&sum) {
	char ch=nc();sum=0;
	while(!(ch>='0'&&ch<='9')) ch=nc();
	while(ch>='0'&&ch<='9') sum=(sum<<3)+(sum<<1)+(ch-48),ch=nc();
}
inline void print(Re x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);putchar(x%10+'0');
}
inline LD LDin(){
	LD X=0,Y=1.0;int f=0;char c=getchar();
	while(c<'0'||c>'9')f|=c=='-',c=getchar(); 
	while(c>='0'&&c<='9')X=X*10+(c^48),c=getchar(); 
	if(c=='.'){c=getchar();while(c>='0'&&c<='9')X+=(Y/=10)*(c^48),c=getchar();}
	return f?-X:X;
}
void bfs()
{
    queue<int>q;
    q.push(n);
    vis[n] = 1;
    while(!q.empty())
    {
        int tmp = q.front();
        q.pop();
        for(auto x:link[tmp])
        {
            in[x]++;
            if(!vis[x])
            {
                q.push(x);
                vis[x] = 1;
            }
        }
    }
    cnt[n] = 1;
    q.push(n);
    while(!q.empty())
    {
        int tmp = q.front();
        q.pop();
        for(auto x:link[tmp])
        {
            cnt[x] += cnt[tmp];
            in[x]--;
            if(!in[x])
                q.push(x);
        }
    }
}
int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0),cout.tie(0);
    int t;
    read(t);
    while(t--)
    {
        // cin >> n;
        read(n);
        mp.clear();
        for(int i = 1;i <= n;++i)
        {
            e[i].clear();
            in[i] = 0;
            link[i].clear();
            cnt[i] = 0;
            vis[i] = 0;
            int type;
            // cin >> type; 
            read(type)   ;
            if(type == 1)
            {
                int k;
                read(k);
                // cin >> k;
                while(k--)
                {
                    int x;
                    read(x);
                    e[i].push_back(x);   
                }
            }else 
            {
                int a,b;
                // cin >> a >> b;
                read(a),read(b);
                link[i].push_back(a);
                link[i].push_back(b);
            }
        }   
        bfs();
        for(int i = 1;i <= n;++i)
        {
            if(e[i].size() != 0)
            {
                for(auto x:e[i])
                {
                    mp[x] += cnt[i];
                }
            }
        }
        ll len = 0;
        ll mx = 0;
        for(auto [x,val]:mp)
        {
            len += val;
            if(val > mx)
                mx = val;
        }
        ll ans = 0;
        if(mx * 2 > len)
        {
            ans = 2 * (len - mx);
        }else 
        {
            ans = len ;
        }
        printf("%lld\n",ans);
    }
    return 0;
}