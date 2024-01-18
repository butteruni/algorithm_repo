#include <bits/stdc++.h>
using namespace std;
int n;
int t,a,b;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        if(a > b)
            swap(a,b);
        if(a == 1)
        {
            if(b != 2)
                cout << 2 << endl;
            else 
                cout << 3 << endl;
        }
        else 
            cout << a - 1 << endl;
    }
}