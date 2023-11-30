#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    int summin = 0,summax = 0;
    int pre = 0;
    cin >> pre;
    n--;
    summin += pre,summax += pre;
    while(n--)
    {
        int x;
        cin >> x;
        if(pre != x)
            summin += x,pre = x;
        summax += x;
    }
    cout << summax << '\n' << summin << '\n';
}