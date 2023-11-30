#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
struct Node
{
    int type;//1:+ 0:. -1:-
    int ps,t;
};
int n,m;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        bool flag=false;
        vector<Node>ans(m+1);
        vector<PII>uk;
        for(int j=1;j<=a;j++)
        {
            string op;
            cin>>op;
            if(op=="+")
            {
                ans[i].type=1;
                string s;
                cin>>s;
                int tmp=0;
                for(auto ch:s)
                {
                    if(ch=='/')
                    {
                        ans[i].ps=tmp;
                        b-=(tmp-1)*20;
                        tmp=0;
                    }
                    else
                    {
                        tmp=tmp*10+ch-'0';
                    }
                }
                b-=tmp;
                a--;
                ans[i].t=tmp;
            }
            else if(op==".")
            {
                ans[i].type=0;
            }
            else if(op=="-")
            {
                cin>>ans[i].ps;
                ans[i].type=-1;
            }
            else if(op=="?")
            {
                ans[i].type=2;
                int tx,ty;
                cin>>tx>>ty;
                ans[i].ps=ty-tx;
                ans[i].t=ans[i].ps*20;
                uk.push_back({i,tx});
            }
        }
        for(int j=0;j<(1<<m);j++)
        {
            bool flag=true;
            int cnt=0;
            for(int k=0;k<m;k++)
            {
                int u=j>>k&1;
                if(u==1&&ans[k+1].type==-1)
                {
                    flag=false;
                    break;
                }
                if(u==1&&ans[k+1])
            }
        }
    }
}