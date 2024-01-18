#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n;
int t,a,b;
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        int temp;
        if(n & 1)
            temp = 2;
        else 
            temp = 3;
        for(int i = 1;i <= n;++i)
        {
            if(i == (n + 1) / 2)
            {
                cout << 1 << " ";
                temp = n;
            }
            else 
            {
                if(i < (n + 1) / 2)
                {
                    cout << temp << " ";
                    temp += 2;
                }
                else 
                {
                    cout << temp << " ";
                    temp -= 2;
                }
            }
        }
        cout << '\n';
    }
}