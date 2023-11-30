#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
int x[N],y[N];
int cross(int x1,int y1,int x2,int y2)
{
    return x1 * y2 - x2 * y1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0;i < n;++i)
    {
        cin >> x[i] >> y[i];
    }
    int ans = 0;
    int aft = 1;
    for(int i = 0;i < n;++i)
    {
        int pre = (i - 1 + n) % n;
        // int aft = i;

        while(y[i] == y[aft])
        {
            aft = (aft + 1) % n;
        }
        if(y[i] < y[pre] && y[i] < y[aft])
        {
            if(y[i] != y[(i + 1) % n])
            {  
                if(cross(x[pre] - x[i],y[pre] - y[i],x[aft] - x[i],y[aft] - y[i]) < 0) 
                    ans++;
            }else 
            {
                if(x[(i + 1) % n] > x[i])
                    ans++;
            }
        }
        
    }
    cout << ans << '\n';
}

