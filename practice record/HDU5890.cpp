#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int a[N];
bitset<100>dp[11];
bool ans[100][100][100];
int n,t;
bool check(int x,int y,int z)
{
    for(int i = 0;i <= 10;++i)
        dp[i].reset();
    dp[0][0] = 1;
    for(int i = 1;i <= n;++i)
    {
        if(i != x && i != y && i != z)
        {
            for(int ne = 10;ne >= 1;ne--)
            {
                dp[ne] |= dp[ne - 1] << a[i];
            }
        }
    }
    if(dp[10][87] == 1)
        return 1;
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--)
    {
        memset(ans,0,sizeof(ans));
        cin >> n;
        for(int i = 1;i <= n;++i)
        {
            cin >> a[i];
        }
        for(int i = 1;i <= n;++i)
        {
            for(int j = i;j <= n;++j)
            {
                for(int k = j;k <= n;++k)
                {
                    if(check(i,j,k))
                        ans[i][j][k] = 1;
                }
            }
        }
        int q;
        cin >> q;
        while (q--)
        {
            int i,j,k;
            cin >> i >> j >> k;
            int ii = min(i,min(j,k));
            int kk = max(i,max(j,k));
            int jj = i + j + k - ii - kk;
            if(ans[ii][jj][kk])
            {
                cout << "Yes" << "\n";
            }else 
            {
                cout << "No" << "\n";
            }
        }
        
    }
}