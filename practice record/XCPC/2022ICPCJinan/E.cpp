#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        int n,k;
        cin>>n>>k;
        if(n==k)
        {
            cout<<"Yes\n";
        }
        else
        {
            if(k%2==0)
            {
                cout<<"Yes\n";
            }
            else
            {
                if(k==1)
                {
                    cout<<"No\n";
                }
                else
                {
                    int res = n % k;
                    int t = n / k;

                    if(n%2==0)
                    {
                        if(res>=t&&(res-t)%2==0&&t+(res-t)/2<=k/2)
                        {
                            cout<<"Yes\n";
                        }
                        else
                        {
                            cout<<"No\n";
                        }
                    }
                    else
                    {
                        if(res>=t-1&&(res-t+1)%2==0&&t-1+(res-t+1)/2<=k/2)//101
                        {
                            cout<<"Yes\n";
                        }
                        else if(res>=t+1&&(res-t-1)%2==0&&t+1+(res-t-1)/2<=k/2)//010
                        {
                            cout<<"Yes\n";
                        }
                        else
                        {
                            cout<<"No\n";
                        }
                    }

                }

            }
        }
    }
    // 4 3
    // 0 1 1 0
    
    // 5 3
    // 1 0 1 1 0

    // 7 3
    // 0 1 1 0 1 1 0
    return 0;
}