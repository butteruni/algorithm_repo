#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> PLL;
const int N=1e6+10;
int n,m,idx;
int cnt[N];
bool vis[N];
int tree[N][26];
int f[30][30];
int tot;
void insert(string s,int v)
{
    int p=0;
    for(int i=0;i<s.length();i++)
    {
        int u=s[i]-'a';
        for(int j=0;j<26;j++)
        {
            if(j!=u)
            {
                f[u][j]+=cnt[tree[p][j]];
            }
        }
        if(!tree[p][u])tree[p][u]=++idx;
        p=tree[p][u];
        cnt[p]+=v;
    }
    for(int i=0;i<26;i++)
    {
        tot+=cnt[tree[p][i]];
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        insert(s,1);
    }
    while(m--)
    {
        string t;
        cin>>t;
        int ans=tot;
        for(int i=0;i<26;i++)
        {
            
            for(int j=i+1;j<26;j++)
            {
                ans+=f[t[i]-'a'][t[j]-'a'];
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
