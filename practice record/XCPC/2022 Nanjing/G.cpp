#include<bits/stdc++.h>

using namespace std;

int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int cnt=0;
        int sum=1,num=1;
        bool flag=false;
        for(int i=1;i<=n;i++)
        {
            int t;
            cin>>t;
            if(t==1)
            {
                sum++;
                num++;
            }
            else if(t==0)
            {
                if(num>=2)
                {
                    num--;
                    cnt++;
                }
                else
                {
                    sum++;
                    num++;
                }
            }
            else if(t==-1)
            {
                if(num>=2)
                {
                    num--;
                }
                else
                {
                    if(cnt)
                    {
                        sum++;
                        num++;
                        cnt--;
                    }
                    else
                    {
                        flag=true;
                    }
                }
            }
            // cout<<sum<<" "<<num<<"---\n";
        }
        int d=gcd(sum,num);
        if(flag)cout<<-1<<"\n";
        else cout<<sum/d<<" "<<num/d<<"\n";
    }
}