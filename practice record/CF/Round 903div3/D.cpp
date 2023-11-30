#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e6 + 10;
int cnt;
bool vis[MAXN];
int pri[MAXN];
map<int,int>pp;
void init()
{
    vis[1]=1;
    for(int i=2;i<MAXN;i++) 
    {
        if(!vis[i])//如果没有被筛过就是质数
        {
            pri[++cnt]=i;
            pp[i] = 1;
        }
        for(int j=1;j<=cnt;j++) 
        {
            if(1ll*i*pri[j]>MAXN)break;
            vis[i*pri[j]]=1;
            if(i%pri[j]==0) 
            {
                break;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    init();
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<ll>a(n);
        for(int i = 0;i < n;++i)
        {
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        map<int,int>mp;
        for(auto x:a)
        {
            if(pp.count(x))
            {
                mp[x]++;
                continue;
            }
            for(int i = 1;i <= cnt && pri[i] <= x;++i)
            {
                while(x % pri[i] == 0)
                {
                    x /= pri[i];
                    mp[pri[i]]++;
                }
            }
        }
        bool ok = 1;
        for(auto [x,val]:mp)
        {
            if(val % n != 0)
            {
                ok = 0;
            }
        }
        if(!ok)
        {
            cout << "NO\n";
        }else 
        {
            cout << "YES\n";
        }


    }
}