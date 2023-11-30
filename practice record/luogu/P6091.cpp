#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 10;
ll phi[N],pri[N],a[N],n,r,t;
ll d;
ll cnt;
bool vis[N];
ll ans[N];
ll gcd(ll a,ll b)
{
    return (!b)?a:gcd(b,a%b);
}
void init()
{
	vis[1] = 1;
	for (int i = 2; i < N; i++)
	{
		if (!vis[i])
		{
			pri[++cnt] = i;
			phi[i] = i - 1;
		}
		for (int j = 1; j <= cnt; j++)
		{
			if (1ll * i * pri[j] >= N)
				break;
			vis[i * pri[j]] = 1;
			if (i % pri[j] == 0)
			{
				phi[i * pri[j]] = phi[i] * pri[j];
				break;
			}
			phi[i * pri[j]] = phi[i] * (pri[j] - 1);
		}
	}
}
ll qpow(ll a,ll b,ll mo)
{
    ll res = 1;
    while(b)
    {
        if(b & 1)
            res = res * a % mo;
        a = a * a % mo;
        b /= 2;
    }
    return res;
}
int check(int n)
{
    if(n % 2 == 0)
        return -1;
    if(!vis[n])
        return n;
    for(int i = 2;pri[i] * pri[i] <= n;++i)
    {
        if(n % pri[i] == 0)
        {
            while(n % pri[i] == 0)
            {
                n /= pri[i];
            }
            if(n > 1)
                return -1;
            return pri[i];
        }
    }
    return -1;
}
bool solve(int g,int mo)
{
    if(gcd(g,mo) != 1)
    {
        return 0;
    }
    for(int i = 1;i <= r;++i)
    {
        if(qpow(g,phi[mo] / a[i],mo) == 1)
            return 0;
    }
    return 1;
}
int calc_g(int mo)
{
    int n = phi[mo];
    r = 0;
    for(int i = 1;pri[i] * pri[i] <= n;++i)
    {
        if(n % pri[i] == 0)
        {
            while(n % pri[i] == 0)
            {
                n /= pri[i];
            }
            a[++r] = pri[i];
        }
    }
    if(n > 1)
        a[++r] = n;
    for(int i = 2;i < mo;++i)
    {
        if(solve(i,mo))
            return i;
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
        cin >> n >> d;
        if(n == 2)
        {
            cout << 1 << '\n';
            if(d == 1)
                cout << 1 << '\n';
            else 
                cout << '\n';
            continue;
        }
        if(n == 4)
        {
            cout << 1 << '\n';
            if(d == 1)
            {
                cout << 3 << '\n';
            }else 
                cout << '\n';
            continue;
        }
        int ch = (n % 2 == 1) ? check(n) : check(n / 2);
        if(ch == -1)
        {
            cout << 0 << "\n";
            cout << '\n';
            continue;
        }
        int g = calc_g(n);
        int l = 0;
        for(int i = 1;i <= phi[n];++i)
        {
            if(gcd(i,phi[n]) == 1)
            {
                ans[++l] = qpow(g,i,n);
            }
        }
        sort(ans + 1,ans + 1 + l);
        cout << l << '\n';
        for(int i = d;i <= l;i += d)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}