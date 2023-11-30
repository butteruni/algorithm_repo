#include<bits/stdc++.h>

using namespace std;
int exgcd(int a,int b,int &x,int &y)
{
    if(!b)
    {
        x=1;y=0;
        return a;
    }
    int k=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return k;
}
int main()
{
    ios::sync_with_stdio(false);
    int a,b;
    while(cin>>a>>b)
    {
        int x,y;
        if(exgcd(a,b,x,y)!=1)
        {
            cout<<"sorry"<<endl;
        }
        else
        {
            while(x<=0)
            {
                x+=b;
                y-=a;
            }
            while(x-b>0)
            {
                x-=b;
                y+=a;
            }
            cout<<x<<' '<<y<<endl;
        }
        
    }
    return 0;
}
