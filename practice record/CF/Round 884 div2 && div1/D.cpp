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
        int temp = n + 1;
        for(int i = 1;i <= n;++i)
        {
            if(n % i == 0)
            {
                continue;
            }else 
            {
                temp = i;
                break;
            }
        }   
        int cnt = 0;
        while(cnt < n)
        {
            char x = 'a';
            for(int i = 1;i <= temp;++i)
            {
                cout << x;
                x ++;
                cnt++;
                if(cnt == n)
                    break;
            }
        }
        cout << endl;
    }
}