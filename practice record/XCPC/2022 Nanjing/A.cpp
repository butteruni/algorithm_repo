#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int N=1e3+10;
int pre[N<<1][N<<1];
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		int n,m,k;
		cin>>n>>m>>k;
		string s;
		cin>>s;
		int u=1,d=n,l=1,r=m;

		for(int i=0;i<=2*n+1;i++)
		{
			for(int j=0;j<=2*m+1;j++)
			{
				pre[i][j]=0;
			}
		}

		int tx=0,ty=0;
		for(auto ch:s)
		{
			if(ch=='U')tx++;
			if(ch=='D')tx--;
			if(ch=='L')ty++;
			if(ch=='R')ty--;
			u=max(u,1+tx);
			d=min(d,n+tx);
			l=max(l,1+ty);
			r=min(r,m+ty);
			pre[tx+n+1][ty+m+1]=1;
		}
		pre[n+1][m+1]=1;
		if(u>d||l>r)
		{
			if(k==0)
			{
				cout<<n*m<<"\n";
			}
			else
			{
				cout<<0<<"\n";
			}
		}
		else
		{
			int t=(d-u+1)*(r-l+1)-k;
			if(t<0)
			{
				cout<<0<<"\n";
			}
			else
			{
				for(int i=1;i<=2*n+1;i++)
				{
					for(int j=1;j<=2*m+1;j++)
					{
						pre[i][j]+=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
					}
				}
				int ans=0;
				for(int i=1;i<=n;i++)
				{
					for(int j=1;j<=m;j++)
					{
						int x1,y1,x2,y2;
						x2=d+n+1-i;
						y2=r+m+1-j;
						x1=u+n+1-i;
						y1=l+m+1-j;
						int tot=pre[x2][y2]-pre[x1-1][y2]-pre[x2][y1-1]+pre[x1-1][y1-1];
						if(tot==t)ans++;
					}
				}
				cout<<ans<<"\n";
			}
		}
	}
	return 0;
}
