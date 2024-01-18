#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PLL;
const int N = 1e6 + 10;
ll a[N];
map<ll,ll>mp;
void solve()
{
    int n;
    cin >> n;
    mp.clear();
    // n <= 2 * cnt[x] && cnt[x] < n 
    // x = 0 && cnt[0] = n 删光
    // if(2 * cnt[0] >= n && cnt[0] < n) end
    ll sum = 0;
    for(int i = 1;i <= n;++i)
        cin >> a[i];
    sort(a + 1,a + 1 + n);
    if(n == 1)
    {
        if(a[n] == 0 || a[n] & 1)
        {
            cout << "Dog\n";
            return;
        }
        cout << "Cat\n";
        return;
    }else if(n == 2)
    {
        if(a[2] == 0)
        {
            cout << "Dog\n";
            return;
        }else 
        {
            if(a[2] == 1 && a[1] == 0) // all is 0
            {
                cout << "Dog\n";
                return;
            }else if(a[2] == a[1] + 1)
            {
                cout << "Cat\n";
            }else 
            {
                cout << "Dog\n";
                return;
            }
        }
    }else 
    {
        int limit = (n - 1) / 2;
        int res = n - limit;
        int cnt_0 = 0;
        for(int i = 1;i <= n;++i)
        {
            sum += a[i];
            cnt_0 += (a[i] == 0);
        }
        if(sum == 0)
        {
            cout << "Dog\n";
            return;
        }else if(cnt_0 * 2>= n)
        {
            cout << "Dog\n";
            return;
        }else  // 操作至0超过一半
        {
            sum -= res;
            if(sum & 1) 
            {
                cout << "Cat\n";
            }else 
            {
                cout << "Dog\n";
            }
        }
    }

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}