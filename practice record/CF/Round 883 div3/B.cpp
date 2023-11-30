#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n;
int t;
char a[5][5];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--)
    {
        for(int i = 1;i <= 3;++i)
        {
            for(int j = 1;j <= 3;++j)
            {
                cin >> a[i][j];
            }
        }
        bool success = 0;
        char ans;
        for(int i = 1;i <= 3;++i)
        {
            if(success)
                break;
            for(int j = 1;j <= 3;++j)
            {
                if(j == 3)
                {
                    ans = a[i][j];
                    if(ans != '.')
                        success = 1;
                }
                if(a[i][j + 1] != a[i][j])
                    break;
            }
        }
        for(int i = 1;i <= 3;++i)
        {
            if(success)
                break;
            for(int j = 1;j <= 3;++j)
            {
                if(j == 3)
                {
                    ans = a[j][i];
                    if(ans != '.')
                        success = 1;
                }
                if(a[j + 1][i] != a[j][i])
                    break;
            }
        }
        for(int i = 1;i <= 3;++i)
        {
            if(success)
                break;
            if(i == 3)
            {
                ans = a[i][i];
                if(ans != '.')
                    success = 1;
            }
            if(a[i][i] != a[i + 1][i + 1])
            {
                break;
            }
        }
        for(int i = 1;i <= 3;++i)
        {
            if(success)
                break;
            if(i == 3)
            {
                ans = a[i][4 - i];
                if(ans != '.')
                    success = 1;
            }
            if(a[i][4 - i] != a[i + 1][3 - i])
            {
                break;
            }
        }
        if(success)
        {
            if(ans == '.')
                cout << "DRAW" << endl;
            else 
                cout << ans << endl;
        }
        else 
            cout << "DRAW" << endl;
    }

}