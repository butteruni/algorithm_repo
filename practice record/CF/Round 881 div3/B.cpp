#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int t;
int n;
ll a[N];
ll cnt_1,sum,cnt_2;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--)
    {
        cnt_1 = 0,sum = 0,cnt_2 = 0;
        cin >> n;
        int i = 1;
        ll cur_sum = 0;
        bool pre_1 = 0;
        bool pre_2 = 0;
        ll x;
        while(n--)
        {
            cin >> x;
            if(x > 0)
            {
                if(pre_1)
                {
                    sum += -1 * cur_sum;
                    cur_sum = 0;
                    cnt_1 ++;
                    pre_1 = 0;
                }
                pre_2 = 1;
                sum += x;
            }
            else if(x == 0)
            {
                continue;
            }else if(x < 0)
            {
                pre_1 = 1;
                if(pre_2)
                {
                    pre_2 = 0;
                    cnt_2 ++;
                }
                cur_sum += x;
            }
        }
        if(cur_sum < 0)
        {
            cnt_1++;
            sum += cur_sum * -1;
            cur_sum = 0;
        }
        cout << sum << " " << cnt_1 << "\n";
    }
}