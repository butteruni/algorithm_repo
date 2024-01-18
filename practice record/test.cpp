#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
vector<int>e[N];
int p[N];       
string person[8] = {"安如熙","鲍欣欣" ,"蔡睿","戴","袁","鄂","范","葛"}; 
int cnt[10];
int id[N];
int val[N];
int a[N],b[N],c[N];
bool cmp(int x,int y)
{
    return val[x] > val[y];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int idx = 1;
    e[0].push_back(1),e[0].push_back(2);
    e[1].push_back(1);
    e[2].push_back(1),e[2].push_back(2);
    e[3].push_back(2);
    e[4].push_back(3),e[4].push_back(4),e[4].push_back(5);
    e[5].push_back(5);
    e[6].push_back(3),e[4].push_back(4);
    e[7].push_back(2),e[4].push_back(3);
    for(int i = 0;i < 8;++i)
    {
        for(int j = i + 1;j < 8;++j)
        {
            for(int k = j + 1;k < 8;++k)
            {
                memset(cnt,0,sizeof(cnt));
                for(int u = 0;u < 8;++u)
                {
                    if(u == i || u == j || u == k)
                        continue;
                    
                    for(auto x:e[u])
                    {
                        cnt[x]++;
                    }
                    int value = 1;
                    for(int i = 1;i <= 5;++i)
                        value *= cnt[i];
                    id[idx] = idx;
                    val[idx] = value;
                    a[idx] = i,b[idx] = j,c[idx] = k;
                    idx++;
                }

            }
        }
    }
    sort(id + 1,id + idx,cmp);
    int mx_id = id[1];
    for(int i = 0;i < 8;++i)
    {
        if(i == a[mx_id] || i == b[mx_id] || i == c[mx_id])
            continue;
        cout << person[i] << ' ';
    }
}   