#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);


int n=9;
for(int i=1;i<=n;i++,puts(""))
   for(int j=1;j<=i;j++)
      printf("%d*%d=%d,",j,i,i*j);
}