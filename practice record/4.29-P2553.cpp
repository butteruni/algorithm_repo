#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1 << 22;
const double eps = 1e-6, pi = acos(-1.0);
int a[N],b[N],r[N],ans[N];
int main()
{
    string poly;
    while(getline(cin, poly))
    {
        poly.erase(remove(poly.begin(),poly.end(),' '),poly.end());
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(ans,0,sizeof(ans));
        int len = poly.length();
        int i = 0;
        while(poly[i] != ')')
        {
            if(poly[i] == '(' || poly[i] == '+' || poly[i] == '^' || poly[i] == 'a' || poly[i] == ' ')
            {
                i++;
                continue;
            }
            int cur = 0;
            while(isdigit(poly[i]))
            {
                int x = poly[i] -= '0';
                cur *= 10;
                cur += poly[i];
                i++;
            }
            if(poly[i] == 'a')
            {
                i += 2;
                int idx = poly[i] - '0';
                // cout << idx << endl;
                a[idx] = cur;
            }else 
            {
                a[0] = cur;
                break;
            }
            i++;
        }
        i++;
        while(poly[i] != ')')
        {
            if(poly[i] == '(' || poly[i] == '+' || poly[i] == '*' || poly[i] == 'a' || poly[i] == ' ')
            {
                i++;
                continue;
            }
            int cur = 0;
            while(isdigit(poly[i]))
            {
                int x = poly[i] -= '0';
                cur *= 10;
                cur += poly[i];
                i++;
            }
            // cout << poly[i] << endl;
            if(poly[i] == 'a')
            {
                i += 2;
                int idx = poly[i] - '0';
                // cout << idx << endl;
                b[idx] = cur;
            }else 
            {
                b[0] = cur;
                break;
            }
            i++;
        }
    //    for(int i = 0;i <= 30;++i)
    //    {
    //         if(b[i])
    //             cout << a[i]  << "-" << i << "|";
    //    }
    //     cout << endl;
        for(int i = 0;i <= 30;++i)
            for(int j = 0;j <= 30;++j)
            {
                ans[i + j] += a[i] * b[j];
            }
        bool success = 0;
        for(int i = 60;i > 0;--i)
        {
            if(ans[i])
            {
                if(success)
                    cout << '+';
                cout << ans[i] << "a^" << i;
                success = 1;
            }
        }
        if(ans[0])
        {
            if(success)
                cout << '+';
            cout << ans[0];
        }
        cout << endl;
    }
}