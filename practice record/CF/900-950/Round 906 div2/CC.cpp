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
        int n;
        cin>>n;
        string s;
        cin>>s;
        if(n%2==1)
        {
            cout<<-1<<"\n";
        }
        else
        {
            bool flag=true;
            int l=0,r=n;
            int cnt=0;
            deque<int>q;
            vector<int>ans;
            for(auto ch:s)
            {
                q.push_back(ch-'0');
            }
            for(int i=1;i<=(n+cnt)/2;i++)
            {
                if(cnt>=600)
                {
                    flag=false;
                    break;       
                }
                if(q.front()==q.back())
                {
                    if(q.front()==0)
                    {
                        ans.push_back(r);
                        cnt+=2;
                        l++;
                        r++;
                        q.pop_front();
                        q.push_back(0);
                    }
                    else
                    {
                        ans.push_back(l);
                        cnt+=2;
                        l++;
                        r++;
                        q.pop_back();
                        q.push_front(1);
                    }
                }
                else
                {
                    l++;
                    r--;
                    q.pop_front();
                    q.pop_back();
                }
            }
            if(flag)
            {
                cout<<ans.size()<<"\n";
                for(auto u:ans)
                {
                    cout<<u<<" ";
                }
                cout<<"\n";

            }
            else
            {
                cout<<-1<<"\n";
            }
        }
    }
    return 0;
}
