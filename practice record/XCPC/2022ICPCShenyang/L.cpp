#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[10],b[10];
ll hpa[10],hpb[10];
int cnta[10],cntb[10];
int id[10];
double a_win,b_win,equ;
int n,m;
bool cmp1(int x,int y)
{
    return cnta[x] < cnta[y];
}
bool cmp2(int x,int y)
{
    return cntb[x] < cntb[y];
}
void print(double val)
{
    cout << fixed << setprecision(10) << val << "\n";
}
void dfs(int res_n,int res_m,double p,int cur)
{
    // for(int i = 1;i <= n;++i)
    //     cout << hpa[i] << " ";
    // cout << '\n';
    // for(int i = 1;i <= m;++i)
    //     cout << hpb[i] << " ";
    // cout << "\n";
    if(res_n == 0)
    {
        if(res_m == 0)
            equ += p;
        else 
            b_win += p;
        return;
    }
    if(res_m == 0)
    {
        if(res_n == 0)
        {
            equ += p;
        }else 
        {
            a_win += p;
        }
        return ;
    }
    if(cur == 1)
    {
        bool flag = 1;
        int cnt_b = 0;
        for(int i = 1;i <= m;++i)
            if(hpb[i] > 0)
                cnt_b++;
        double pp = 1.0 / (1.0 * cnt_b);
        // ll attack = 1e9;
        // for(int i = 1;i <= n;++i)
        // {
        //     if(hpa[i] > 0)
        //         attack = min(attack,a[i]);
        // }
        int mn_cnt = 1e9;
        for(int i = 1;i <= n;++i)
        {
            if(hpa[i] > 0)
            {
                mn_cnt = min(mn_cnt,cnta[i]);
            }
        }
        for(int i = 1;i <= n && flag;++i)
        {
            if(hpa[i] > 0 && cnta[i] == mn_cnt)
            {
                flag = 0;
                for(int j = 1;j <= m;++j)
                {
                    if(hpb[j] > 0)
                    {
                        ll tmp1 = hpb[j];
                        ll tmp2 = hpa[i];
                        hpb[j] -= a[i];
                        hpa[i] -= b[j];
                        if(hpb[j] <= 0)
                        {
                            hpb[j] = 0;
                        }
                        if(hpa[i] <= 0)
                        {
                            hpa[i] = 0;
                        }
                        cnta[i]++;
                        dfs(res_n - (hpa[i] == 0),res_m - (hpb[j] == 0),p * pp,cur ^ 1);
                        cnta[i]--;
                        hpb[j] = tmp1;
                        hpa[i] = tmp2;
                    }
                }
            }
        }
    }else 
    {
        bool flag = 1;
        int cnt_a = 0;
        for(int i = 1;i <= n;++i)
            if(hpa[i] > 0)
                cnt_a++;
        double pp = 1.0 / (1.0 * cnt_a);
        int mn_cnt = 1e9;
        for(int i = 1;i <= m;++i)
        {
            if(hpb[i] > 0)
            {
                mn_cnt = min(mn_cnt,cntb[i]);
            }
        }
        for(int i = 1;i <= m && flag;++i)
        {
            if(hpb[i] > 0 && cntb[i] == mn_cnt)
            {
                flag = 0;
                for(int j = 1;j <= n;++j)
                {
                    if(hpa[j] > 0)
                    {
                        ll tmp1 = hpb[i];
                        ll tmp2 = hpa[j];
                        hpb[i] -= a[j];
                        hpa[j] -= b[i];
                        if(hpb[i] <= 0)
                        {
                            hpb[i] = 0;
                        }
                        if(hpa[j] <= 0)
                        {
                            hpa[j] = 0;
                        }
                        cntb[i]++;
                        dfs(res_n - (hpa[j] == 0),res_m - (hpb[i] == 0),p * pp,cur ^ 1);
                        cntb[i]--;
                        hpb[i] = tmp1;
                        hpa[j] = tmp2;
                    }
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;++i)
        cin >> a[i];
    for(int i = 1;i <= n;++i)
    {
        hpa[i] = a[i];
    }
    for(int i = 1;i <= m;++i)
        cin >> b[i];
    for(int i = 1;i <= m;++i)
    {
        hpb[i] = b[i];
    }
    if(n > m)
    {
        dfs(n,m,1.0,1);
    }else if(n == m)
    {
        dfs(n,m,0.5,1);
        dfs(n,m,0.5,0);
    }else 
    {
        dfs(n,m,1.0,0);
    }
    print(a_win);
    print(b_win);
    print(equ);
}