#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N],b[N];
bitset<N * N * N> f[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;++i)
    {
        cin >> a[i] >> b[i];
    }
    f[0][0] = 1;
    for(int i = 1;i <= n;++i)
    {
        for(int j = a[i];j <= b[i];++j)
        {
            f[i] |= f[i - 1] << (j * j);
        }
    }
    cout << f[n].count() << "\n";
}