#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, mod = 929;
typedef long long ll;
string s;
int n,w;
vector<int>p;
ll ans[N];
ll q[N],g[N],d[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> w >> n;
    cin >> s;
    int pre = 3;
    int k = 0;
    if(n == -1)
    {
        k = 0;
    }else 
    {
        k = pow(2, n + 1);
    }
    for(int i = 0;i < s.length();++i)
    {
        char x = s[i];
        int cur = 0;
        if(isdigit(x))
        {
            cur = 1;
        }else if(islower(x))
        {
            cur = 2;
        }else
        {
            cur = 3;
        }
        if(pre == 0)
        {
            pre = cur;
        }else if(pre != cur)
        {
            if(cur == 2)
            {
                p.push_back(27);
            }else
            {
                p.push_back(28);
                if(pre == 2 && cur == 3)
                    p.push_back(28);
            }
            pre = cur;
        }
        if(cur == 1)
            p.push_back(x - '0');
        else if(cur == 2)
            p.push_back(x - 'a');
        else 
            p.push_back(x - 'A');
    }
    int sz = p.size();
    if(sz & 1)
        p.push_back(29);
    int idx = 0;
    for(int i = 1;i <= sz;i += 2)
    {
        ans[idx++] = p[i - 1] * 30 + p[i];
    }
    if((idx + k + 1) % w != 0)
    {
        while((idx + k + 1) % w != 0)
        {
            ans[idx++] = 900;
        }
    }
    g[0] = 1;
    int temp = -3;
    for(int i = 1;i <= k; temp = temp * 3 % mod,++i) //计算g[x]系数
    {
        for(int j = i - 1;j >= 0;--j)
            g[j + 1] = (g[j + 1] + g[j] * temp % mod) % mod;
    }
    // for(int i = 0;i <= k;++i)
    //     cout << g[i] << " ";
    // cout << endl;
    d[0] = idx + 1;
    for(int i = 1;i <= idx;++i)  //d[x]系数
    {
        d[i] = ans[i - 1];
    }
    for(int i = 0;i <= idx;++i)
    {
        for(int j = 1;j <= k;++j)
        {
            d[i + j] = (d[i + j] - d[i] * g[j] % mod) % mod; //计算-r[x]
        }
    }
    // for(int i = 0;i <= idx + k; ++ i)
    // {
    //     cout << d[i] << " ";
    // }
    // cout << endl;
    cout << idx + 1 << endl;
    for(int i = 0;i < idx;++i)
    {
        cout << ans[i] << endl;
    }
    for(int i = idx + 1;i <= idx + k;++i)
    {
        cout << (-d[i] % mod + mod) % mod << endl;
    }
}