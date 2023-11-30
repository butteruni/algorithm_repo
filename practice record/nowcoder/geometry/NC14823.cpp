#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define eq(a,b) (fabs(a-b)<eps)
#define IN(x) ((x)>=-L && (x)<=L)
#define pb push_back

using namespace std;

typedef double ld;

const int N=510,M=1000010;
const ld eps=1e-7;

inline char nc(){
  static char buf[100000],*p1=buf,*p2=buf;
  return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}

inline void read(int &x){
  char c=nc(); x=0;
  for(;c>'9'||c<'0';c=nc());for(;c>='0'&&c<='9';x=x*10+c-'0',c=nc());
}

inline void read(ld &x){
  char c=nc(); int f=1,flg=0,dv=1; x=0;
  for(;c>'9'||c<'0';c=nc())if(c=='-')f=-1;
  for(;c>='0'&&c<='9' || c=='.';x=x*10+c-'0',c=nc(),dv=flg?dv*10:dv)
    if(c=='.'){
      flg=1; c=nc();
    }
  x/=dv; x*=f;
}

ld L,l,r;
int cnt,tot,t,n,m,id[N];
ld A[N],B[N],C[N];

struct Point{
  ld x,y;
  Point(ld _x=0,ld _y=0):x(_x),y(_y){}
  friend bool operator <(const Point &a,const Point &b){
    if(a==b) return 0;
    if(!eq(a.x,b.x)) return a.x<b.x;
    return a.y<b.y;
  }
  friend bool operator ==(const Point &a,const Point &b){
    return eq(a.x,b.x) && eq(a.y,b.y);
  }
};

struct node{
  Point x; int g,a,b;
  friend bool operator <(const node &a,const node &b){
    if(a.x==b.x) return a.a<b.a;
    return a.x<b.x;
  }
}a[M];

vector<ld> border; 
vector<Point> polygon[M];

inline Point Cross(int x,int y){
  ld k1=-A[x]/B[x],d1=-C[x]/B[x],k2=-A[y]/B[y],d2=-C[y]/B[y];
  if(eq(k1,k2)) return Point(-1e20,-1e20);
  Point ret; ret.x=(d1-d2)/(k2-k1); ret.y=k1*ret.x+d1;
  return ret;
}

int ans[M];

inline ld f(int g,ld x){
  return -(A[g]*x+C[g])/B[g];
}

inline bool cmp(const int &a,const int &b){
  if(!eq(f(a,l),f(b,l))) return f(a,l)<f(b,l);
  return -A[a]/B[a]>-A[b]/B[b];
}

int p=1,rk[N],pnum[N];

inline void work(){
  for(int i=1;i<t;i++){
    ++cnt;
    polygon[cnt].pb(Point(l,f(id[i],l)));
    polygon[cnt].pb(Point(l,f(id[i+1],l)));
    pnum[i]=cnt;
  }
  for(;p<=tot;p++){
    if(a[p].x.x>r) break;
    if(a[p].g){
      int l=1,r=t,res,mid;
      while(l<=r) f(id[mid=l+r>>1],a[p].x.x)<a[p].x.y?l=(res=mid)+1:r=mid-1;
      ans[a[p].g]=pnum[res];
      continue;
    }
    int np=p,revL=min(rk[a[p].a],rk[a[p].b]),revR=max(rk[a[p].a],rk[a[p].b]);
    while(np<tot && a[np+1].x==a[p].x){
      np++;
      revL=min(min(rk[a[np].a],rk[a[np].b]),revL);
      revR=max(max(rk[a[np].a],rk[a[np].b]),revR);
    }
    if(pnum[revL-1])
      polygon[pnum[revL-1]].pb(a[p].x);
    if(pnum[revR])
      polygon[pnum[revR]].pb(a[p].x);
    reverse(id+revL,id+revR+1);
    for(int i=revL;i<=revR;i++){
      rk[id[i]]=i;
      if(i==revR) break;
      polygon[pnum[i]].pb(a[p].x);
      pnum[i]=++cnt;
      polygon[cnt].pb(a[p].x);
    }
    p=np;
  }
  for(int i=1;i<t;i++){
    polygon[pnum[i]].pb(Point(r,f(id[i],r)));
    polygon[pnum[i]].pb(Point(r,f(id[i+1],r)));
  }
}

ld siz[M];
int vis[M];

Point s;

inline bool cmp1(const Point &a,const Point &b){
  return (a.y-s.y)*(b.x-s.x)<(b.y-s.y)*(a.x-s.x);
}

inline ld cross(const Point &a,const Point &b){
  return (a.x-s.x)*(b.y-s.y)-(a.y-s.y)*(b.x-s.x);
}

inline ld calc(int x){
  vector<Point> &c=polygon[x];
  for(int i=1;i<c.size();i++)
    if(c[i]<c[0]) swap(c[i],c[0]);
  s=c[0]; sort(c.begin()+1,c.end(),cmp1);
  ld ret=0;
  for(int i=1;i<c.size()-1;i++)
    ret+=cross(c[i],c[i+1]);
  return ret/2;
}

void PutAns(int x){
  if(x>=10) PutAns(x/10); putchar(x%10+'0');
}

int main(){
  read(n); read(m); read(L);
  for(int i=1;i<=n;i++){
    read(A[i]); read(B[i]); read(C[i]);
    if(!eq(B[i],0))
      id[++t]=i;
    else if(IN(C[i]/A[i]))
      border.pb(-C[i]/A[i]);
  }
  id[++t]=n+1; A[n+1]=0; B[n+1]=1; C[n+1]=L;
  id[++t]=n+2; A[n+2]=0; B[n+2]=1; C[n+2]=-L;
  border.pb(-L); border.pb(L);
  sort(border.begin(),border.end());
  l=-L; sort(id+1,id+1+t,cmp);
  for(int i=1;i<=t;i++) rk[id[i]]=i;
  for(int i=1;i<=t;i++)
    for(int j=i+1;j<=t;j++){
      Point cur=Cross(id[i],id[j]);
      //printf("%d %d %.2lf %.2lf\n",i,j,cur.x,cur.y);
      if(!IN(cur.x)) continue;
      ++tot; a[tot].x=cur; a[tot].a=id[i]; a[tot].b=id[j]; a[tot].g=0;
    }
  for(int i=1;i<=m;i++){
    ++tot; read(a[tot].x.x); read(a[tot].x.y);
    a[tot].g=i;
  }
  sort(a+1,a+1+tot);
  for(int i=0;i<border.size()-1;i++){
    l=border[i]; r=border[i+1];
    if(eq(l,r)) continue;
    work();
  }
  /*for(int i=1;i<=cnt;i++){
    printf("%d : ",i);
    for(auto x : polygon[i]) printf("%.2lf %.2lf\n",x.x,x.y);
    putchar('\n');
    }*/
  for(int i=1;i<=m;i++){
    if(!vis[ans[i]])
      vis[ans[i]]=1,siz[ans[i]]=calc(ans[i]);
    PutAns((int)(siz[ans[i]]+0.005)); 
           putchar('.');
    int r=(long long)(siz[ans[i]]*100+0.5)%100;
    if(r<10) putchar('0');
    PutAns(r); putchar('\n');
    //printf("%.2lf\n",size[ans[i]]);
  }
  return 0;
}
