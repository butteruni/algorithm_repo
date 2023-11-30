#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
ll a[N];
int t;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);   
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        bool unsort = 0;
        ll mins = 1e9;
        for(int i = 1;i <= n;++i)
        {
            cin >> a[i];
            if(a[i] < a[i - 1])
                unsort = 1;
            if(i != 1)
                mins = min(mins,a[i] - a[i - 1]);
        }
        if(unsort)
        {
            cout << "0\n";
        }else 
        {
            cout << max((mins) / 2 + 1,1ll) << '\n';
        }
    }
}     