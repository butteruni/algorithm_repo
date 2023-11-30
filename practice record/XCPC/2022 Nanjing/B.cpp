#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 5e5 + 10;

int n, k, q;
int a[MAXN];
ll f[MAXN], g[MAXN];
string str;

struct MonoQue
{
    ll q[MAXN<<1], p[MAXN<<1];
    // q[]用于存储值，p[]用于存储元素对应位置
    int l, r;
    inline void init()
    {
        l = 1, r = 1;
    }
    inline void pop_front(int j)
    {
        while(l <= r && p[l] < j - k)
            ++l;
    }
    inline void push(int val, int pos)
    {
        while((q[r-1] >= val || str[pos] == '1') && l < r)
            --r;
        q[r] = val;
        p[r] = pos;
        ++r;
    }
    inline ll query()
    {
        return q[l];
    }
}que;

struct MonoQue2
{
    ll q[MAXN<<1], p[MAXN<<1];
    // q[]用于存储值，p[]用于存储元素对应位置
    int l, r;
    inline void init()
    {
        l = 1, r = 1;
    }
    inline void pop_front(int j)
    {
        while(l <= r && p[l] > j + k)
            ++l;
    }
    inline void push(int val, int pos)
    {
        while((q[r-1] >= val || str[pos] == '1') && l < r)
            --r;
        q[r] = val;
        p[r] = pos;
        ++r;
    }
    inline ll query()
    {
        return q[l];
    }
}que2;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n >> k;
        for(int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            f[i] = g[i] = 0;
        }
        cin >> str;
        str = '1' + str;
        str = str + '1';
        que.init();
        int idx = 1;
        for(int i = 1; i <= k; ++i, ++idx)
        {
            f[i] = a[i];
            que.push(f[i], i);
            if(str[i] == '1')
                break;
        }
        for(int i = idx; i <= n; ++i)
        {
            que.pop_front(i);
            f[i] = que.query() + a[i];
            que.push(f[i], i);
        }

        que2.init();
        idx = n;
        for(int i = n; i >= n-k; --i, --idx)
        {
            g[i] = 0;
            que2.push(a[i], i);
            if(str[i] == '1')
                break;
        }
        for(int i = idx-1; i >= 1; --i)
        {
            que2.pop_front(i);
            g[i] = que2.query();
            que2.push(g[i]+a[i], i);
        }

        cin >> q;
        for(int i = 1; i <= q; ++i)
        {
            que.init();
            int p, v;
            cin >> p >> v;
            for(int j = max(p-k, 1); j <= p-1; ++j)
            {
                que.push(f[j], j);
            }
            ll ans = 1e18;
            vector<ll> tmp(n+1);
            for(int j = p; j <= min(p+k-1, n+1); ++j)
            {
                que.pop_front(j);
                int val = a[j];
                if(j == p)
                    val = v;
                // cout << que.query() << " " << val << endl;
                tmp[j] = que.query() + val;
                que.push(tmp[j], j);
                // cout << tmp[j] << " " << g[j] << endl;
                ans = min(ans, tmp[j]+g[j]);
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
