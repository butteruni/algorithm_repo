#include <bits/stdc++.h>
using namespace std;
int x,y,z;
int in[4] = {2,3,5,7};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> x;
    int ans = 0;
    for(int i = 0;i < 4;++i)
    {
        if(x % in[i] == 0)
            ans++;
    }
    if(ans)
        cout << "YES" << '\n';
    else 
        cout << "NO" << '\n';

}