#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
string a;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> a;
        char x = a[0];
        int flag = -1;
        for(int i = 1;i < a.length();++i)
        {
            if(a[i] != x)
                flag = 1;
        }
        if(flag == 1)
            cout << a.length() - 1 << endl;
        else 
            cout << -1 << endl;
    }
}