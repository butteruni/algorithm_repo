#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int idx;
int tree[N << 2][2];
void insert(int x)
{
    int p = 0;
    for (int i = 21; i >= 0; i--)
    {
        int u = x >> i & 1;
        if (!tree[p][u])
        {
            idx++;
            tree[p][u] = idx;
        }
        p = tree[p][u];
    }
}
int query(int x)
{
    int p = 0;
    int ret = 0;
    for (int i = 21; i >= 0; i--)
    {
        int u = x >> i & 1;
        if (tree[p][u ^ 1])
        {
            p = tree[p][u ^ 1];
            ret += (1 << i);
        }
        else
        {
            p = tree[p][u];
        }
    }
    return ret;
}
int a[N];
int pre[N];
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
        pre[i + 1] = pre[i] ^ a[i];
        insert(pre[i + 1]);
    }
    bool ok = 0;
    for (int i = 0; i <= n - 1; i++)
    {
        if (query(i) == n - 1)
        {
            cout << i << " ";
            for (int j = 2; j <= n; j++)
            {
                ok = 1;
                int t = i ^ pre[j];
                cout << t << " \n"[j == n];
            }
            break;
        }else if(i == n - 1 && query(i) == n - 2)
        {
            cout << i << " ";
            for (int j = 2; j <= n; j++)
            {
                ok = 1;
                int t = i ^ pre[j];
                cout << t << " \n"[j == n];
            }
            break;
        }
    }
    assert(ok == 1);
    return 0;
}