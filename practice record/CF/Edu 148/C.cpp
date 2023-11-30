#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
typedef long long ll;
int n,k;
ll a[N];
ll contrast[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        memset(a,0,sizeof(a));
        // memset(pre_sum,0,sizeof(pre_sum));
        cin >> n;
        int lens = n;
        bool change = 0;
        for(int i = 1;i <= n;++i)
        {
            cin >> a[i];
        }
        int pre_sign = 0;
        for(int i = 2;i <= n;++i)
        {
            int cur_sign;
            if(a[i] > a[i - 1])
            {
                cur_sign = 1;
            }else if(a[i] < a[i - 1])
            {
                cur_sign = 2;
            }else 
            {
                lens--;
                continue;
            }
            if(cur_sign == pre_sign)
            {
                lens--;
            }else 
            {
                pre_sign = cur_sign;
                // if(i != 2)
                // {
                //     change = 1;
                //     cout << i << " ";
                // }
            }
        }
        // lens -= change == 0;
        cout << lens << '\n';
    }
}