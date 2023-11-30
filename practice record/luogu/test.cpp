#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll cnt = 0;
    for(int i = 1;i <= 2000000;++i)
    {
        cnt += sqrt(2000000 / i);
    }
    cout << cnt << " ";
}